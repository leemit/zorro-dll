///////////////////////////////////////////////////////
// Header for DLL-based Zorro strategies
///////////////////////////////////////////////////////

#ifndef ZORRO_H_
#define ZORRO_H_

#include "zorro/common.h"

#include <wtypes.h>
#include <Windows.h>
#include <stdio.h>
#include <math.h>

#pragma pack(push, 4)

#ifdef ZORRO_CPP_PURE
#include "zorro/trading_cpp.h"
#else
#include "zorro/litec/trading_types.h"
#include "zorro/litec/trading_defines.h"
#endif

#pragma pack(pop)

#ifdef ZORRO_IMPL
GLOBALS* g = 0;
#else
extern GLOBALS* g;
#endif

#include "zorro/functions_cpp.h"

#ifdef ZORRO_CPP_PURE
#include "zorro/variables_cpp.h"
#else
#include "zorro/litec/variables.h"
#endif

#ifdef ZORRO_CPP
#include "zorro/litec/default.h"
#endif

#ifdef ZORRO_USE_EVENT_CLASS
class CZorroEvents
{
private:
	CZorroEvents() {};
	CZorroEvents(const CZorroEvents&) {};

public:
	void main();
	void run();
	void tick();
	void tock();
	void click(int row, int col);
	void evaluate(const PERFORMANCE* pPerformance);
	var objective();
	EOrderResult order(EOrderAction type);
	var neural(ENeuralMode mode, int model, int numSignals, const void* pData);
	EBarAction bar(cvars open, cvars high, cvars low, cvars close, cvars price, DATE start, DATE time);

	static CZorroEvents getInstance() { static CZorroEvents instance; return instance; }
};
#endif // ZORRO_USE_EVENT_CLASS

#endif // ZORRO_H_
