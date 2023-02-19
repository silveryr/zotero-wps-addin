// dllmain.h: 模块类的声明。

class CZoteroWpsModule : public ATL::CAtlDllModuleT< CZoteroWpsModule >
{
public :
	DECLARE_LIBID(LIBID_ZoteroWpsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ZOTEROWPS, "{24a2f5e1-beaf-49fb-8d0c-fad05a79e558}")
};

extern class CZoteroWpsModule _AtlModule;
