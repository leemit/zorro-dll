
// Workshop 5: Counter trend trading, optimized
#define ZORRO_DLLMAIN
#include "zorro_impl.h"

ZORRO_EXPORT void ZORRO_CALL run()
{
	set(EZorroFlag::PARAMETERS);  // generate and use optimized parameters
	BarPeriod = PERIOD_H4; // 4 hour bars
	LookBack = 500;
	StartDate = 2005;
	EndDate = 2016; // fixed simulation period
	NumWFOCycles = 10; // activate WFO
	asset("EUR/USD");

	if(ReTrain) {
		UpdateDays = -1; // update price data from the server 
		SelectWFO = -1; // select the last cycle for re-optimization
	}
	
	// calculate the buy/sell signal
	vars Price = series(price());
	vars Filtered = series(BandPass(Price, static_cast<int>(optimize(30,20,40)), 0.5));
	vars Signal = series(FisherN(Filtered, 500));
	var Threshold = optimize(1, 0.5, 1.5, 0.1);

	// buy and sell
	Stop = optimize(4,2,10) * ATR(100);
	Trail = 4 * ATR(100);

	if(crossUnder(Signal,-Threshold))
		enterLong(); 
	else if(crossOver(Signal,Threshold))
		enterShort();

	// plot signals and thresholds
	plot("Filtered",Filtered, EPlotType::NEW, EColor::BLUE);
	plot("Signal",Signal, EPlotType::NEW, EColor::RED);
	plot("Threshold1", 1, EPlotType::REGULAR, EColor::BLACK);
	plot("Threshold2", -1, EPlotType::REGULAR, EColor::BLACK);
	PlotWidth = 600;
	PlotHeight1 = 300;
	set(EZorroFlag::PLOTNOW);
}
