///////////////////////////////////////////////////////
// Common code for DLL-based Zorro strategies
// Include this file once in a cpp file
///////////////////////////////////////////////////////
#pragma once

#define ZORRO_IMPL
#include "zorro/zorro_common.h"

////////////////////////////////////////////////////////
// Default DllMain

#ifdef ZORRO_DLLMAIN
BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
)
{
	(void)hinstDLL;
	(void)fdwReason;
	(void)lpvReserved;

	return TRUE;
}
#endif

////////////////////////////////////////////////////////

ZORRO_NAMESPACE_OPEN

ZORRO_EXPORT int ZORRO_CALL zorro(GLOBALS* Globals)
{
	g = Globals;
	int N = 0;
// Populate the list of function pointers
#define F(x) (DWORD&)x = g->Functions[N++];
#define F0(x) (DWORD&)x##0 = g->Functions[N++];
#define F1(x) (DWORD&)x##1 = g->Functions[N++];
#define F2(x) (DWORD&)x##2 = g->Functions[N++];
#define F3(x) (DWORD&)x##3 = g->Functions[N++];
#include "zorro/func_list.h"

	return SCRIPT_VERSION;
}

ZORRO_NAMESPACE_CLOSE

#undef ZORRO_IMPL
