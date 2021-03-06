
// Trend Trading
#define ZORRO_DLLMAIN
#include "zorro_impl.h"

ZORRO_EXPORT void ZORRO_CALL run()
{
	vars Price = series(price());
	vars Trend = series(LowPass(Price,500));
	
	Stop = 4 * ATR(100);
	
	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
	
	StartDate = 2010;
	EndDate = 2015; // fixed simulation period 
	
	set(EZorroFlag::LOGFILE); // log all trades
	PlotWidth = 800;
	PlotHeight1 = 300;
	//plot("MMI_Raw",MMI_Raw,NEW,GREY);
	//plot("MMI_Smooth",MMI_Smooth,0,BLACK);
	//plotTradeProfile(-50); 
}
