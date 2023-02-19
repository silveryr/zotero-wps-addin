// dllmain.cpp: DllMain 的实现。

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ZoteroWps_i.h"
#include "dllmain.h"

CZoteroWpsModule _AtlModule;

class CZoteroWpsApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CZoteroWpsApp, CWinApp)
END_MESSAGE_MAP()

CZoteroWpsApp theApp;

BOOL CZoteroWpsApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CZoteroWpsApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
