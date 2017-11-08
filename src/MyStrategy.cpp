///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////

#define ZORRO_DLLMAIN                 // defines a dll entry point for this strategy
#define ZORRO_EXPECT_ALL_FUNCTIONS    // asserts at runtime if the strategy is not using all functions from zorro
#define ZORRO_FORCE_LITEC             // forces the lite-c preprocessor defines instead of c++ variables/enums
#define ZORRO_USE_EVENT_CLASS         // uses a pre defined zorro event class for all event functions
#include "zorro_impl.h"
#pragma warning(disable: 4100)

void CZorroEvents::main()
{

}

void CZorroEvents::run()
{
	set(TICKS);

	if (is(FIRSTRUN))
	{
		enterLong();
		// your zorro code ...
	}
}

void CZorroEvents::tick()
{

}

void CZorroEvents::tock()
{

}

void CZorroEvents::click(int row, int col)
{

}

void CZorroEvents::evaluate(const PERFORMANCE* pPerformance)
{

}

var CZorroEvents::objective()
{
	return objectivePRR();
}

EOrderResult CZorroEvents::order(EOrderAction type)
{
	return ORDER_OK;
}

var CZorroEvents::neural(ENeuralMode mode, int model, int numSignals, const void* pData)
{
	return 0.0;
}

EBarAction CZorroEvents::bar(cvars open, cvars high, cvars low, cvars close, cvars price, DATE start, DATE time)
{
	return BAR_CLOSE_NORMALLY;
}
