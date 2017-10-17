///////////////////////////////////////////////////////
// Common code for DLL-based Zorro strategies
// Include this file once in a cpp file
///////////////////////////////////////////////////////
#pragma once

#include "zorro_common.h"

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
#endif // ZORRO_DLL

////////////////////////////////////////////////////////
// Create a list of function pointers
#define F(x) (*x)
#define F0(x) (*x##0)
#define F1(x) (*x##1)
#define F2(x) (*x##2)
#define F3(x) (*x##3)
#define C
#include "functions.h"

GLOBALS *g;

DLLFUNC int zorro(GLOBALS* Globals)
{
	g = Globals;
	int N = 0;
// Populate the list of function pointers
#define F(x) (DWORD&)x = g->Functions[N++];
#define F0(x) (DWORD&)x##0 = g->Functions[N++];
#define F1(x) (DWORD&)x##1 = g->Functions[N++];
#define F2(x) (DWORD&)x##2 = g->Functions[N++];
#define F3(x) (DWORD&)x##3 = g->Functions[N++];
#include "func_list.h"

	return SCRIPT_VERSION;
}
