///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////
#define ZORRO_DLLMAIN
#include "zorro_impl.h"
#include "zorro.h"

#define WORKSHOP7

#ifdef WORKSHOP4
ZORRO_EXPORT void ZORRO_CALL run()
{
//	print(1,"\nTest!");
	vars Price = series(price(0));
	vars Trend = series(LowPass(Price,500));
	
	Stop = 4*ATR(100);
	
	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
	
	StartDate = 2010;
	EndDate = 2016; // fixed simulation period 
	
	set(LOGFILE); // log all trades
	//Verbose = 2;
	PlotWidth = 800;
	PlotHeight1 = 300;
	//set(PLOTNOW);
	//plot("MMI_Raw",MMI_Raw,NEW,GREY);
	//plot("MMI_Smooth",MMI_Smooth,0,BLACK);
	//plotTradeProfile(-50); 
}
#endif

#ifdef WORKSHOP6
void tradeCounterTrend()
{
	TimeFrame = 4;
	vars Price = series(price(0));
	vars Filtered = series(BandPass(Price,optimize(30,20,40,0,0),0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1,0);
	
	Stop = optimize(4,2,10,0,0) * ATR(100);
	Trail = 4*ATR(100);
	
	if(crossUnder(Signal,-Threshold)) 
		enterLong(); 
	else if(crossOver(Signal,Threshold)) 
		enterShort();
}

void tradeTrend()
{
	TimeFrame = 1;
	vars Price = series(price(0));
	vars Trend = series(LowPass(Price,optimize(500,300,700,0,0)));

	Stop = optimize(4,2,10,0,0) * ATR(100);
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
	set(PARAMETERS+FACTORS);  // generate and use optimized parameters and factors
	//NumCores = -2;		// use multiple cores (Zorro S only)
	BarPeriod = 60;	// 1 hour bars
	LookBack = 2000;	// needed for Fisher()
	StartDate = 2005;
	EndDate = 2016; 	// fixed simulation period
	NumWFOCycles = 10; // activate WFO
	Capital = 10000;		// reinvestment mode
	
	if(ReTrain) {
		UpdateDays = -1;	// update price data from the server 
		SelectWFO = -1;	// select the last cycle for re-optimization
		reset(FACTORS);	// don't generate factors when re-training
	}
	
// portfolio loop
	while(asset(loop("EUR/USD","USD/JPY")))
	while(algo(loop("TRND","CNTR")))
	{
// don't reinvest
		//Margin = 0.5 * OptimalF * Capital;
// reinvest the square root of the component profit		
		Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);

		if(strstr(Algo,"TRND")) 
			tradeTrend();
		else if(strstr(Algo,"CNTR")) 
			tradeCounterTrend();
	}
	
	PlotWidth = 600;
	PlotHeight1 = 300;
	//ColorUp = ColorDn = ColorWin = ColorLoss = 0; // don't plot candles and trades
	set(TESTNOW+LOGFILE);
}
#endif

#ifdef WORKSHOP7
ZORRO_EXPORT void ZORRO_CALL run()
{
	StartDate = 2005;
	EndDate = 2016;
	BarPeriod = 1440; // 1 day
	BarZone = static_cast<int>(ETimeZone::WET); // Western European midnight
	Weekend = 1;	// don't merge Friday and Sunday bars
	LookBack = 3;	// only 3 bars needed
	NumWFOCycles = 10;

	set(static_cast<int>(EZorroFlag::RULES)); //+TESTNOW);

	//if(Train) Hedge = 2;	// for training, allow long + short	
	LifeTime = 5;  				// one week
	MaxLong = MaxShort = 1;
	
	if(adviseLong(static_cast<int>(EAdviseMode::PATTERN | EAdviseMode::PATTERNS_2),0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 40)
		enterLong();
	
	if(adviseShort() > 40)
		enterShort();

	PlotWidth = 600;
	PlotHeight1 = 300;
}
#endif
