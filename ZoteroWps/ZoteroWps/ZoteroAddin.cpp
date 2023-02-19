// ZoteroAddin.cpp: CZoteroAddin 的实现

#include "pch.h"
#include "ZoteroAddin.h"

static HRESULT ExecDispathGet(IDispatch* pDisp, const WCHAR* funcName, CComVariant* pFuncArgs, UINT argCount, CComVariant* pResult)
{
	CComBSTR bsName(funcName);
	DISPID dispid = 0;
	HRESULT hr = pDisp->GetIDsOfNames(IID_NULL, &bsName, 1, LOCALE_USER_DEFAULT, &dispid);
	if (hr != S_OK)
		return hr;

	DISPPARAMS disp = { pFuncArgs, NULL, argCount, 0 };
	hr = pDisp->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &disp, pResult, NULL, NULL);
	return hr;
}


// CZoteroAddin

STDMETHODIMP CZoteroAddin::OnConnection(IDispatch* Application, ext_ConnectMode ConnectMode, IDispatch* AddInInst, SAFEARRAY** custom)
{
	Application->QueryInterface(__uuidof(IDispatch), (LPVOID*)&m_spApplication);
	return S_OK;
}

STDMETHODIMP CZoteroAddin::OnDisconnection(ext_DisconnectMode RemoveMode, SAFEARRAY** custom)
{
	m_spApplication = NULL;
	return S_OK;
}

STDMETHODIMP CZoteroAddin::OnAddInsUpdate(SAFEARRAY** custom)
{
	return S_OK;
}

STDMETHODIMP CZoteroAddin::OnStartupComplete(SAFEARRAY** custom)
{
	return S_OK;
}

STDMETHODIMP CZoteroAddin::OnBeginShutdown(SAFEARRAY** custom)
{
	return S_OK;
}

STDMETHODIMP CZoteroAddin::GetCustomUI(BSTR RibbonID, BSTR* RibbonXml)
{
	if (!RibbonXml)
		return E_INVALIDARG;

	const WCHAR* const cszUIXml = L"<?xml version=\"1.0\" encoding=\"utf-16\"?>\
		<customUI xmlns = \"http://schemas.microsoft.com/office/2009/07/customui\" onLoad=\"OnLoadRibbon\" loadImage=\"OnLoadImage\">\
		<ribbon>\
		<tabs>\
		<tab id = \"ZoteroWpsTab\" label = \"Zotero WPS\">\
		<group id = \"ZoteroWpsGroup\" label = \"Zotero\">\
		<button id = \"WpsInsertZoteroCitationButton\" label = \"Add/Edit Citation\" size = \"large\" image=\"addEditZoteroCitation\" onAction = \"OnButtonClick\" supertip = \"Insert a new citation, or edit the citation at the current cursor position\" />\
		<button id = \"WpsInsertZoteroNoteButton\" label = \"Add Note\" size = \"large\" image=\"addZoteroNote\" onAction = \"OnButtonClick\" supertip = \"Insert a new note at the current cursor position\" />\
		<button id = \"WpsInsertZoteroBibliographyButton\" label = \"Add/Edit Bibliography\" size = \"large\" image=\"addEditZoteroBibliography\" onAction = \"OnButtonClick\" supertip = \"Insert a new bibliography, or edit the existing bibliography, at the current cursor position\" />\
		<button id = \"WpsZoteroSetDocPrefs\" label = \"Document Preferences\" image=\"setZoteroDocPrefs-small\" onAction = \"OnButtonClick\" supertip = \"Change the citation style or locale\" />\
		<button id = \"WpsRefreshZotero\" label = \"Refresh\" imageMso = \"DataRefreshAll\" onAction = \"OnButtonClick\" supertip = \"Update all citations to reflect changes\" />\
		<button id = \"WpsZoteroRemoveCodes\" label = \"Unlink Citations\" imageMso = \"RemoveHyperlink\" onAction = \"OnButtonClick\" supertip = \"Remove all Zotero field codes and unlink from Zotero library\" />\
		</group>\
		</tab>\
		</tabs>\
		</ribbon>\
		</customUI>";

	*RibbonXml = ::SysAllocString(cszUIXml);
	return S_OK;
}

STDMETHODIMP CZoteroAddin::OnButtonClick(IDispatch* pDispControl)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CComQIPtr<IRibbonControl> spRibbonCtl(pDispControl);

	CComBSTR bstrId;
	spRibbonCtl->get_Id(&bstrId);

	if (bstrId == L"WpsInsertZoteroCitationButton")
	{
		ZoteroCommand(L"addEditCitation", true);
	}
	else if (bstrId == L"WpsInsertZoteroNoteButton")
	{
		ZoteroCommand(L"addNote", true);
	}
	else if (bstrId == L"WpsInsertZoteroBibliographyButton")
	{
		ZoteroCommand(L"addEditBibliography", true);
	}
	else if (bstrId == L"WpsZoteroSetDocPrefs")
	{
		ZoteroCommand(L"setDocPrefs", true);
	}
	else if (bstrId == L"WpsRefreshZotero")
	{
		ZoteroCommand(L"refresh", false);
	}
	else if (bstrId == L"WpsZoteroRemoveCodes")
	{
		ZoteroCommand(L"removeCodes", false);
	}

	return S_OK;
}


STDMETHODIMP CZoteroAddin::OnLoadRibbon(IDispatch* pRibbonUI)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此处添加分派处理程序代码

	return S_OK;
}

STDMETHODIMP CZoteroAddin::OnLoadImage(BSTR bstrName, IPictureDisp** ppPicDisp)
{
	if (!ppPicDisp)
		return E_INVALIDARG;

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	static std::unordered_map<std::wstring, size_t> s_pngIndexs =
	{
		{ L"zoteroz16", IDB_PNG8 },
		{ L"addEditZoteroCitation", IDB_PNG3 },
		{ L"addZoteroNote", IDB_PNG5 },
		{ L"addEditZoteroBibliography", IDB_PNG1 },
		{ L"setZoteroDocPrefs-small", IDB_PNG7}
	};

	auto iter = s_pngIndexs.find(bstrName);
	if (iter == s_pngIndexs.end())
		return E_FAIL;

	HMODULE hMod = GetModuleHandle(L"ZoteroWps");
	HRSRC hRes = FindResourceW(hMod, MAKEINTRESOURCEW(iter->second), L"PNG");
	if (!hRes)
		return E_FAIL;

	HGLOBAL hResLoad = LoadResource(hMod, hRes);
	if (!hResLoad)
		return E_FAIL;

	DWORD sizePng = SizeofResource(hMod, hRes);
	LPVOID pResData = LockResource(hResLoad);

	HGLOBAL hMem = GlobalAlloc(GMEM_FIXED, sizePng);
	LPVOID pMem = GlobalLock(hMem);
	memcpy(pMem, pResData, sizePng);
	GlobalUnlock(hMem);

	CComPtr<IStream> spStmRes;
	CreateStreamOnHGlobal(hMem, TRUE, &spStmRes);

	CImage imgObj;
	imgObj.Load(spStmRes);

	CComPtr<IStream> spStmBitmap;
	CreateStreamOnHGlobal(NULL, TRUE, &spStmBitmap);
	imgObj.Save(spStmBitmap, Gdiplus::ImageFormatBMP);

	LARGE_INTEGER li = { 0 };
	spStmBitmap->Seek(li, STREAM_SEEK_SET, NULL);

	CComPtr<IPictureDisp> spPicture;
	OleLoadPicture(spStmBitmap, 0, FALSE, IID_IPictureDisp, (LPVOID*)&spPicture);

	if (!spPicture)
		return E_FAIL;

	*ppPicDisp = spPicture.Detach();
	return S_OK;
}


void CZoteroAddin::ZoteroCommand(const WCHAR* cmd, bool bringToFront) const
{
	HWND hAppWnd = NULL;
	const WCHAR* appNames[4] = { L"ZoteroMessageWindow", L"FirefoxMessageWindow", L"BrowserMessageWindow", L"firefox-devMessageWindow" };
	for (int i = 0; i < sizeof(appNames)/sizeof(appNames[0]) && !hAppWnd; i++)
	{
		hAppWnd = FindWindow(appNames[i], NULL);
	}

	if (!hAppWnd)
	{
		MessageBoxW(GetFocus(), L"找不到 Zotero 窗口，请从开始菜单启动 Zotero 软件后重试.", L"错误", MB_OK | MB_ICONWARNING);
		return;
	}

	if (bringToFront)
		SetForegroundWindow(hAppWnd);

	CComPtr<IDispatch> spDoc;
	GetActiveDocument(spDoc);

	CString docName = GetDocumentPath(spDoc);
	CString args;

	args.Format(L"-silent -ZoteroIntegrationAgent WinWord -ZoteroIntegrationCommand %s -ZoteroIntegrationDocument \"%s\" -ZoteroIntegrationTemplateVersion 1", cmd, docName.GetString());
	CString cmdStr;
	cmdStr.Format(L"firefox.exe %s \0 C:\\", args.GetString());

	int length = WideCharToMultiByte(CP_UTF8, 0, cmdStr.GetBuffer(), -1, 0, 0, 0, 0);
	char* buffer = new char[length + 1];
	WideCharToMultiByte(CP_UTF8, 0, cmdStr.GetBuffer(), -1, buffer, length, 0, 0);
	buffer[length] = 0;

	COPYDATASTRUCT cds;
	memset(&cds, 0, sizeof(COPYDATASTRUCT));
	cds.dwData = 1;
	cds.cbData = length;
	cds.lpData = buffer;
	SendMessage(hAppWnd, WM_COPYDATA, 0, (LPARAM)&cds);

	delete []buffer;
}

HRESULT CZoteroAddin::GetActiveDocument(CComPtr<IDispatch>& spDispatch) const
{
	CComVariant result;
	if (ExecDispathGet(m_spApplication, L"ActiveDocument", NULL, 0, &result) == S_OK)
	{
		spDispatch = V_DISPATCH(&result);
		return S_OK;
	}
	return E_FAIL;
}

CString CZoteroAddin::GetDocumentPath(IDispatch* pDispatch) const
{
	CString path(L"文字文稿");
	if (!pDispatch)
		return path;

	CComVariant result;
	if (ExecDispathGet(pDispatch, L"FullName", NULL, 0, &result) == S_OK)
	{
		path = V_BSTR(&result);
	}

	return path;
}
