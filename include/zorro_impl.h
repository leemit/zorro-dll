///////////////////////////////////////////////////////
// Common code for DLL-based Zorro strategies
// Include this file once in a cpp file
///////////////////////////////////////////////////////
#pragma once

#define ZORRO_IMPL
#include "zorro.h"
#include <assert.h>

////////////////////////////////////////////////////////
// Default DllMain

#ifdef ZORRO_DLLMAIN
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD     fdwReason,
	LPVOID    lpvReserved
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

ZORRO_EXPORT int ZORRO_CALL zorro(GLOBALS* pGlobals)
{
	assert(pGlobals != 0);
	g = pGlobals;
	unsigned int n = 0;
// Populate the list of function pointers
#define F(x)  assert(g->Functions[n] != 0); (DWORD&)x##_ptr  = g->Functions[n++];
#define F0(x) assert(g->Functions[n] != 0); (DWORD&)x##0_ptr = g->Functions[n++];
#define F1(x) assert(g->Functions[n] != 0); (DWORD&)x##1_ptr = g->Functions[n++];
#define F2(x) assert(g->Functions[n] != 0); (DWORD&)x##2_ptr = g->Functions[n++];
#define F3(x) assert(g->Functions[n] != 0); (DWORD&)x##3_ptr = g->Functions[n++];
#define C
#define R(x)
#define A(x)
#define D(x) ;
#define I(param,value) param
#define VA ,...
#include "zorro/litec/functions_list.h"

	// TODO assert names of functions
	// TODO replace assert with proper error handling?

#ifdef ZORRO_EXPECT_ALL_FUNCTIONS
	assert(g->Functions[n] == 0);
#endif

	return SCRIPT_VERSION;
}

ZORRO_NAMESPACE_CLOSE

#undef ZORRO_IMPL
