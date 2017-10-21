///////////////////////////////////////////////////////
// Common code for DLL-based Zorro strategies
// Include this file once in a cpp file
///////////////////////////////////////////////////////
#pragma once

#define ZORRO_IMPL
#include "zorro.h"

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
	unsigned int n = 0;
// Populate the list of function pointers
#define F(x)  (DWORD&)x##_ptr  = g->Functions[n++];
#define F0(x) (DWORD&)x##0_ptr = g->Functions[n++];
#define F1(x) (DWORD&)x##1_ptr = g->Functions[n++];
#define F2(x) (DWORD&)x##2_ptr = g->Functions[n++];
#define F3(x) (DWORD&)x##3_ptr = g->Functions[n++];
#define C
#define R(x)
#define A(x)
#define D(x)
#define I(x)
#define VA ,...
#include "zorro/litec/functions_list.h"

	// TODO assert number of functions
	// TODO assert names of functions

	return SCRIPT_VERSION;
}

ZORRO_NAMESPACE_CLOSE

#undef ZORRO_IMPL
