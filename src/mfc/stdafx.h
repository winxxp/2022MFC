// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// STDAFX.H is the header that includes the standard includes that are used
//  for most of the project.  These are compiled into a pre-compiled header

#define _CRT_RAND_S

#include <winsdkver.h>

#undef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_MAXVER

#undef NTDDI_VERSION

#include <sdkddkver.h>

// turn off warnings for /W4 (just for MFC implementation)
#ifndef ALL_WARNINGS
#pragma warning(disable: 4073)  // disable warning about using init_seg
#pragma warning(disable: 4702)  // unreachable code
#endif

// MFC inline constructors (including compiler generated) can get deep
#pragma inline_depth(16)

#ifdef _AFX_DEVBUILD
	#define AFX_IMPL_DATA AFX_DATA_EXPORT
#else
	#define AFX_IMPL_DATA
#endif

#ifdef _AFX_MFCS  // Building the static component of the DLL version.  Import stuff from MFC*.dll
#include <afxv_dll.h>
#else  // Building the DLL itself
// override default values for data import/export when building MFC DLLs
#ifdef _AFX_CORE_IMPL
	#define AFX_CORE_DATA   AFX_IMPL_DATA
	#define AFX_CORE_DATADEF
#endif

#ifdef _AFX_OLE_IMPL
	#define AFX_OLE_DATA    AFX_IMPL_DATA
	#define AFX_OLE_DATADEF
#endif

#ifdef _AFX_DB_IMPL
	#define AFX_DB_DATA     AFX_IMPL_DATA
	#define AFX_DB_DATADEF
#endif

#ifdef _AFX_NET_IMPL
	#define AFX_NET_DATA    AFX_IMPL_DATA
	#define AFX_NET_DATADEF
#endif
#endif

#define _AFX_NOFORCE_LIBS
#define _AFX_FULLTYPEINFO
#define VC_EXTRALEAN
#define NO_ANSIUNI_ONLY
#define _MFC_OVERRIDES_NEW

#define AFX_COMDAT __declspec(selectany)

// core headers
#include "afx.h"
#include "afxplex_.h"
#include "atlbase.h"
#include "afxcoll.h"
#include "afxtempl.h"

// public headers
#include "afxwin.h"
#include "afxdlgs.h"
#include "afxext.h"

#ifndef _OLE2_H_
	#include <Ole2.h>
#endif

#include <winspool.h>

// for the release version, MFC internally can use the more efficient
//  method of directly accessing CRuntimeClass objects.
#ifndef _DEBUG
#undef RUNTIME_CLASS
#define RUNTIME_CLASS(class_name) _RUNTIME_CLASS(class_name)
#endif

// include OLE dialog/helper APIs
#ifndef _OLEDLG_H_
	#include <OleDlg.h>
#endif

#include <winreg.h>
	#include "afxcom_.h"
#include "afxole.h"
#include "afxdtctl.h"
#include "afxocc.h"

#include "afxdocob.h"

#ifndef _AFX_NO_DAO_SUPPORT
	#include "afxdao.h"
#endif

#include "afxodlgs.h"
#include "afxctl.h"
#include "afxdb.h"
#include "afxmt.h"
#include "afxinet.h"

// private headers as well
#include "afxpriv.h"
#include "afximpl.h"
#include "winhand_.h"
#include "oleimpl2.h"
#include "ctlimpl.h"
#include "dbimpl.h"
#ifndef _AFX_NO_DAO_SUPPORT
	#include "daoimpl.h"
#endif
#ifndef _WINSOCKAPI_
	#include <winsock.h>
#endif
#include "sockimpl.h"
#include "afxsock.h"
#include "afxcmn.h"
#include "afxcview.h"
#include "afxrich.h"
#include "afxhtml.h"
#include "afxdhtml.h"

#if defined(_UNICODE)
	#include "afxtaskdialog.h"
#endif

#ifndef _AFX_MFCS
// This header is included by about a third of the source files.
// It takes about 30% of the total compile time of the MFC project if
// not included in the PCH header.
#include "afxtoolbarimages.h"
#endif

#include <winreg.h>
#include <WinNls.h>
#include <stddef.h>
#include <limits.h>
#include <malloc.h>
#include <new.h>
#include <eh.h>

#undef AfxWndProc

// implementation uses _AFX_PACKING as well
#ifdef _AFX_PACKING
#ifndef ALL_WARNINGS
#pragma warning(disable: 4103)
#endif
#pragma pack(_AFX_PACKING)
#endif

// special exception handling just for MFC library implementation

// MFC does not rely on auto-delete semantics of the TRY..CATCH macros,
//  therefore those macros are mapped to something closer to the native
//  C++ exception handling mechanism when building MFC itself.

#undef TRY
#define TRY { try {

#undef CATCH
#define CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); UNUSED(e);

#undef AND_CATCH
#define AND_CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); UNUSED(e);

#undef CATCH_ALL
#define CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); UNUSED(e);

#undef AND_CATCH_ALL
#define AND_CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); UNUSED(e);

#undef END_TRY
#define END_TRY } catch (CException* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); e->Delete(); } }

#undef THROW_LAST
#define THROW_LAST() throw

// Because of the above definitions of TRY...CATCH it is necessary to
//  explicitly delete exception objects at the catch site.

#define DELETE_EXCEPTION(e) do { if(e) { e->Delete(); } } while (0)
#define NO_CPP_EXCEPTION(expr)


/////////////////////////////////////////////////////////////////////////////
