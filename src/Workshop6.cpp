
// Workshop 6_2: Money Management
#define ZORRO_DLLMAIN
#include "zorro_impl.h"

void tradeCounterTrend()
{
	TimeFrame = 4;
	vars Price = series(price());
	vars Filtered = series(BandPass(Price,static_cast<int>(optimize(30,20,40)),0.5));
	vars Signal = series(Fisher(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1);
	
	Stop = optimize(4,2,10) * ATR(100);
	Trail = 4*ATR(100);
	
	if(crossUnder(Signal,-Threshold)) 
		enterLong(); 
	else if(crossOver(Signal,Threshold)) 
		enterShort();
}

void tradeTrend()
{
	TimeFrame = 1;
	vars Price = series(price());
	vars Trend = series(LowPass(Price,static_cast<int>(optimize(500,300,700))));

	Stop = optimize(4,2,10) * ATR(100);
	Trail = 0;

	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
}

ZORRO_EXPORT void ZORRO_CALL run()
{
	set(EZorroFlag(EZorroFlag::PARAMETERS|EZorroFlag::FACTORS)); // generate and use optimized parameters and factors
	NumCores = -2;         // use multiple cores (Zorro S only)
	BarPeriod = PERIOD_H1; // 1 hour bars
	LookBack = 2000;       // needed for Fisher()
	StartDate = 2005;
	EndDate = 2016;        // fixed simulation period
	NumWFOCycles = 10;     // activate WFO
	Capital = 10000;       // reinvestment mode
	
	if(ReTrain) {
		UpdateDays = -1;            // update price data from the server 
		SelectWFO = -1;             // select the last cycle for re-optimization
		reset(EZorroFlag::FACTORS); // don't generate factors when re-training
	}
	
	// portfolio loop
	while(asset(loop("EUR/USD","USD/JPY")))
	while(algo(loop("TRND","CNTR")))
	{
		// don't reinvest
		Margin = 0.5 * OptimalF * Capital;
		// reinvest the square root of the component profit		
		//Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);

		if(strcmp(Algo, "TRND")==0) 
			tradeTrend();
		else if(strcmp(Algo, "CNTR")==0) 
			tradeCounterTrend();
	}
	
	PlotWidth = 600;
	PlotHeight1 = 300;
	//ColorUp = ColorDn = ColorWin = ColorLoss = 0; // don't plot candles and trades
	set(EZorroFlag(EZorroFlag::TESTNOW|EZorroFlag::LOGFILE));
}
