

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ZoteroWps.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ZoteroWps_i_h__
#define __ZoteroWps_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IZoteroAddin_FWD_DEFINED__
#define __IZoteroAddin_FWD_DEFINED__
typedef interface IZoteroAddin IZoteroAddin;

#endif 	/* __IZoteroAddin_FWD_DEFINED__ */


#ifndef __ZoteroAddin_FWD_DEFINED__
#define __ZoteroAddin_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZoteroAddin ZoteroAddin;
#else
typedef struct ZoteroAddin ZoteroAddin;
#endif /* __cplusplus */

#endif 	/* __ZoteroAddin_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IZoteroAddin_INTERFACE_DEFINED__
#define __IZoteroAddin_INTERFACE_DEFINED__

/* interface IZoteroAddin */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZoteroAddin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a9d1a923-fd01-4284-8965-8774dfb6b338")
    IZoteroAddin : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnButtonClick( 
            /* [in] */ IDispatch *pDispControl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnLoadRibbon( 
            /* [in] */ IDispatch *pRibbonUI) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnLoadImage( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IPictureDisp **ppPicDisp) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IZoteroAddinVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZoteroAddin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZoteroAddin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZoteroAddin * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZoteroAddin * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZoteroAddin * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZoteroAddin * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZoteroAddin * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnButtonClick )( 
            IZoteroAddin * This,
            /* [in] */ IDispatch *pDispControl);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnLoadRibbon )( 
            IZoteroAddin * This,
            /* [in] */ IDispatch *pRibbonUI);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnLoadImage )( 
            IZoteroAddin * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IPictureDisp **ppPicDisp);
        
        END_INTERFACE
    } IZoteroAddinVtbl;

    interface IZoteroAddin
    {
        CONST_VTBL struct IZoteroAddinVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZoteroAddin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZoteroAddin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZoteroAddin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZoteroAddin_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZoteroAddin_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZoteroAddin_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZoteroAddin_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IZoteroAddin_OnButtonClick(This,pDispControl)	\
    ( (This)->lpVtbl -> OnButtonClick(This,pDispControl) ) 

#define IZoteroAddin_OnLoadRibbon(This,pRibbonUI)	\
    ( (This)->lpVtbl -> OnLoadRibbon(This,pRibbonUI) ) 

#define IZoteroAddin_OnLoadImage(This,bstrName,ppPicDisp)	\
    ( (This)->lpVtbl -> OnLoadImage(This,bstrName,ppPicDisp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZoteroAddin_INTERFACE_DEFINED__ */



#ifndef __ZoteroWpsLib_LIBRARY_DEFINED__
#define __ZoteroWpsLib_LIBRARY_DEFINED__

/* library ZoteroWpsLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ZoteroWpsLib;

EXTERN_C const CLSID CLSID_ZoteroAddin;

#ifdef __cplusplus

class DECLSPEC_UUID("c18019c8-49f4-41f7-b26e-ba5aae3b3e8c")
ZoteroAddin;
#endif
#endif /* __ZoteroWpsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


