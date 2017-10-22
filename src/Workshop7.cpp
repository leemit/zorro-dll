
// Machine learning
#define ZORRO_DLLMAIN
#include "zorro_impl.h"

ZORRO_EXPORT void ZORRO_CALL run()
{
	StartDate = 2005;
	EndDate = 2016;
	BarPeriod = PERIOD_D1; // 1 day
	BarZone = ETimeZone::WET; // Western European midnight
	Weekend = EWeekendMode::UPDATE_TMF_AND_GENERATE_BARS; // don't merge Friday and Sunday bars
	LookBack = 3; // only 3 bars needed
	NumWFOCycles = 10;

	set(EZorroFlag(EZorroFlag::RULES|EZorroFlag::TESTNOW));

	if(Train) Hedge = EHedgeMode::ALLOW_ANY; // for training, allow long + short	
	ExitTime = 6; // one week

	if(adviseLong(EAdviseMode(EAdviseMode::PATTERN|2),0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 40)
		reverseLong(1);
	
	if(adviseShort() > 40)
		reverseShort(1);

	PlotWidth = 600;
	PlotHeight1 = 300;
	//plotTradeProfile(40);
	//plotWFOCycle(Equity,0);
	//plotWFOProfit();
}
