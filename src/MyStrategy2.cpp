///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////

#define ZORRO_DLLMAIN                 // defines a dll entry point for this strategy
#define ZORRO_USE_EVENT_CLASS         // uses a pre defined zorro event class for all event functions
#include "zorro_impl.h"
#pragma warning(disable: 4100)

void CZorroEvents::main()
{

}

void CZorroEvents::run()
{
	enterLong();

	forLongTrades([]() { /* do something */ });
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
	return EOrderResult::OK;
}

var CZorroEvents::neural(ENeuralMode mode, int model, int numSignals, const void* pData)
{
	return 0.0;
}

EBarAction CZorroEvents::bar(cvars open, cvars high, cvars low, cvars close, cvars price, DATE start, DATE time)
{
	return EBarAction::CLOSE_NORMALLY;
}
