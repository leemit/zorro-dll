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

#ifdef ZORRO_USE_EVENT_CLASS

ZORRO_EXPORT void ZORRO_CALL main()
{
	CZorroEvents::getInstance().main();
}

ZORRO_EXPORT void ZORRO_CALL run()
{
	CZorroEvents::getInstance().run();
}

ZORRO_EXPORT void ZORRO_CALL tick()
{
	CZorroEvents::getInstance().tick();
}

ZORRO_EXPORT void ZORRO_CALL tock()
{
	CZorroEvents::getInstance().tock();
}

ZORRO_EXPORT void ZORRO_CALL click(int row, int col)
{
	CZorroEvents::getInstance().click(row, col);
}

ZORRO_EXPORT void ZORRO_CALL evaluate(const PERFORMANCE* pPerformance)
{
	CZorroEvents::getInstance().evaluate(pPerformance);
}

ZORRO_EXPORT var ZORRO_CALL objective()
{
	return CZorroEvents::getInstance().objective();
}

ZORRO_EXPORT EOrderResult ZORRO_CALL order(EOrderAction type)
{
	return CZorroEvents::getInstance().order(type);
}

ZORRO_EXPORT var ZORRO_CALL neural(ENeuralMode mode, int model, int numSignals, const void* pData)
{
	return CZorroEvents::getInstance().neural(mode, model, numSignals, pData);
}

ZORRO_EXPORT EBarAction ZORRO_CALL bar(cvars open, cvars high, cvars low, vars close, vars price, DATE start, DATE time)
{
	return CZorroEvents::getInstance().bar(open, high, low, close, price, start, time);
}

#endif // ZORRO_USE_EVENT_CLASS

ZORRO_NAMESPACE_CLOSE

#undef ZORRO_IMPL
