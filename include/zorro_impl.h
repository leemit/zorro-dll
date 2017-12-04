///////////////////////////////////////////////////////
// Common code for DLL-based Zorro strategies
// Include this file once in a cpp file
///////////////////////////////////////////////////////

#ifndef ZORRO_IMPL_H_
#define ZORRO_IMPL_H_

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

ZORRO_EXPORT int ZORRO_CALL zorro(GLOBALS* pGlobals)
{
	assert(pGlobals != 0);
	assert(g == 0);

	g = pGlobals;
	unsigned int n = 0;

// Populate the list of function pointers
#define F(x)  assert(g->Functions[n] != 0); (DWORD&) ZORRO_NAMESPACE x    = g->Functions[n++];
#define F0(x) assert(g->Functions[n] != 0); (DWORD&) ZORRO_NAMESPACE x##0 = g->Functions[n++];
#define F1(x) assert(g->Functions[n] != 0); (DWORD&) ZORRO_NAMESPACE x##1 = g->Functions[n++];
#define F2(x) assert(g->Functions[n] != 0); (DWORD&) ZORRO_NAMESPACE x##2 = g->Functions[n++];
#define F3(x) assert(g->Functions[n] != 0); (DWORD&) ZORRO_NAMESPACE x##3 = g->Functions[n++];
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
	ZORRO_NAMESPACE g_zevents.main();
}

ZORRO_EXPORT void ZORRO_CALL run()
{
	ZORRO_NAMESPACE g_zevents.run();
}

ZORRO_EXPORT void ZORRO_CALL tick()
{
	ZORRO_NAMESPACE g_zevents.tick();
}

ZORRO_EXPORT void ZORRO_CALL tock()
{
	ZORRO_NAMESPACE g_zevents.tock();
}

ZORRO_EXPORT void ZORRO_CALL click(int row, int col)
{
	ZORRO_NAMESPACE g_zevents.click(row, col);
}

ZORRO_EXPORT void ZORRO_CALL evaluate(const PERFORMANCE* pPerformance)
{
	ZORRO_NAMESPACE g_zevents.evaluate(pPerformance);
}

ZORRO_EXPORT var ZORRO_CALL objective()
{
	return ZORRO_NAMESPACE g_zevents.objective();
}

ZORRO_EXPORT EOrderResult ZORRO_CALL order(EOrderAction type)
{
	return ZORRO_NAMESPACE g_zevents.order(type);
}

ZORRO_EXPORT var ZORRO_CALL neural(ENeuralMode mode, int model, int numSignals, const void* pData)
{
	return ZORRO_NAMESPACE g_zevents.neural(mode, model, numSignals, pData);
}

ZORRO_EXPORT EBarAction ZORRO_CALL bar(cvars open, cvars high, cvars low, cvars close, cvars price, DATE start, DATE time)
{
	return ZORRO_NAMESPACE g_zevents.bar(open, high, low, close, price, start, time);
}

#endif // ZORRO_USE_EVENT_CLASS

#undef ZORRO_IMPL

#endif // ZORRO_IMPL_H_
