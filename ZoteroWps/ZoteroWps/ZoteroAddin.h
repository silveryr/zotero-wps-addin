// ZoteroAddin.h: CZoteroAddin 的声明

#pragma once
#include "resource.h"       // 主符号

#include "ZoteroWps_i.h"
#include <unordered_map>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CZoteroAddin

class ATL_NO_VTABLE CZoteroAddin :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CZoteroAddin, &CLSID_ZoteroAddin>,
	public IDispatchImpl<IZoteroAddin, &IID_IZoteroAddin, &LIBID_ZoteroWpsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<_IDTExtensibility2, &__uuidof(_IDTExtensibility2), &LIBID_AddInDesignerObjects, /* wMajor = */ 1, /* wMinor = */ 0>,
	public IDispatchImpl<IRibbonExtensibility, &__uuidof(IRibbonExtensibility), &LIBID_Office, /* wMajor = */ 3, /* wMinor = */ 0>
{
public:
	CZoteroAddin()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CZoteroAddin)
	COM_INTERFACE_ENTRY(IZoteroAddin)
	COM_INTERFACE_ENTRY2(IDispatch, IZoteroAddin)
	COM_INTERFACE_ENTRY2(IDispatch, _IDTExtensibility2)
	COM_INTERFACE_ENTRY(_IDTExtensibility2)
	COM_INTERFACE_ENTRY(IRibbonExtensibility)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

// _IDTExtensibility2 Methods
public:
	STDMETHOD(OnConnection)(IDispatch* Application, ext_ConnectMode ConnectMode, IDispatch* AddInInst, SAFEARRAY** custom);

	STDMETHOD(OnDisconnection)(ext_DisconnectMode RemoveMode, SAFEARRAY** custom);

	STDMETHOD(OnAddInsUpdate)(SAFEARRAY** custom);

	STDMETHOD(OnStartupComplete)(SAFEARRAY** custom);

	STDMETHOD(OnBeginShutdown)(SAFEARRAY** custom);


// IRibbonExtensibility Methods
public:
	STDMETHOD(GetCustomUI)(BSTR RibbonID, BSTR* RibbonXml);

	STDMETHOD(OnButtonClick)(IDispatch* pDispControl);
	STDMETHOD(OnLoadRibbon)(IDispatch* pRibbonUI);
	STDMETHOD(OnLoadImage)(BSTR bstrName, IPictureDisp** ppPicDisp);

private:
	void ZoteroCommand(const WCHAR* cmd, bool bringToFront) const;
	HRESULT GetActiveDocument(CComPtr<IDispatch>& spDispatch) const;
	CString GetDocumentPath(IDispatch* pDispatch) const;

	CComPtr<IDispatch> m_spApplication;
};

OBJECT_ENTRY_AUTO(__uuidof(ZoteroAddin), CZoteroAddin)
