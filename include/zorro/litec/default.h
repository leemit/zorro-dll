
#ifndef default_h
#define default_h

#ifdef ZORRO_CPP_PURE
#define ZORRO_ENUM_VALUE(enumValue, macroName) enumValue
#else
#define ZORRO_ENUM_VALUE(enumValue, macroName) macroName
#endif

/////////////////////////////////////////////////////////////////////
// overloaded functions
inline var round(var val,var step) {
	return roundto(val,step);
}
inline var round(var val) {
	return roundto(val,1.);
}
inline string strdate(string format) {
	return strdate(format,0);
}
inline var strvar(string str,string name) {
	return strvar(str,name,0);
}
inline var optimize(var val,var start,var end,var step) {
	return optimize(val,start,end,step,0);
}
inline var optimize(var val,var start,var end) {
	return optimize(val,start,end,0,0);
}
inline var DominantPeriod(int Period) {
	return DominantPeriod(series(price()),Period);
}
inline var DominantPhase(int Period) {
	return DominantPhase(series(price()),Period);
}
inline void assetAdd(string Name) {
	assetAdd(Name,50,0,0,0,0.01,0.01,0,1,1,0,Name);
}
inline void plot(string name,int val,EPlotType type,EColor color) {
	plot(name,(var)val,type,color);
}
inline void plot(string name,vars data,EPlotType type,EColor color) {
	plot(name,data[0],type,color);
}
inline int memory() {
	return memory(0);
}
inline var Ichimoku() {
	return Ichimoku(0,0,0,0);
}
inline var Chikou() {
	return Chikou(26);
}
inline var SAR(var AFstep,var AFmax) {
	return SAR(AFstep,AFstep,AFmax);
}
inline var Fisher(cvars data,int period) {
	return FisherN(data,period);
}
inline var HH(int period) {
	return HH(period,0);
}
inline var LL(int period) {
	return LL(period,0);
}
inline var genSine(var period) {
	return genSine(period,period);
}
inline var genSquare(var period) {
	return genSquare(period,period);
}

/////////////////////////////////////////////////////////////////////
// user functions

// optimizing objective based on PRR
inline var objectivePRR()
{
	if(!NumWinTotal && !NumLossTotal) return 0.;
	var wFac = 1./sqrt(1.+NumWinTotal); 
	var lFac = 1./sqrt(1.+NumLossTotal);
	var win = WinTotal, loss = LossTotal;
	// remove single outliers
	if(NumWinTotal > 2) win -= (NumWinTotal-2)*WinMaxTotal/NumWinTotal;
	if(NumLossTotal > 2) loss -= (NumLossTotal-2)*LossMaxTotal/NumLossTotal;
	// return PRR
	return (1.-wFac)/(1.+lFac)*(1.+win)/(1.+loss);
}

// helper functions for limiting the open trades
inline TRADE* reverseLong(int MaxTrades)
{
	// update the stops and profit targets of open trades
	var Price = priceClose();
	if(Stop > 0 && Stop < Price/2) // stop distance 
		exitLong(0,Price-Stop);
	else if(Stop >= Price/2) // stop limit
		exitLong(0,Stop); 
	if(TakeProfit > 0 && TakeProfit < Price/2) 
		exitLong(0,-(Price+TakeProfit));
	else if(TakeProfit >= Price/2) 
		exitLong(0,-TakeProfit);

	// extend the exit time of open non-advise trades 
	if(ExitTime > 1)
		for(long_trades)
			if(TradeIsOpen && !(ThisTrade->dSignals))
				TradeExitTime = TradeTime+ExitTime;

	// if MaxTrades is not reached, open a new trade
	if(NumOpenLong < MaxTrades || is(ZORRO_ENUM_VALUE(EStatusFlag::TRAINMODE,TRAINMODE)))
		return enterLong();
	// otherwise, close any opposite trades
	else if(Hedge <= 1)
		exitShort();
	return 0;
}

inline TRADE* reverseShort(int MaxTrades)
{
	var Price = priceClose();
	if(Stop > 0 && Stop < Price/2) 
		exitShort(0,Price+Stop); 
	else if(Stop >= Price/2)
		exitShort(0,Stop); 
	if(TakeProfit > 0 && TakeProfit < Price/2) 
		exitShort(0,-(Price-TakeProfit));
	else if(TakeProfit >= Price/2) 
		exitShort(0,-TakeProfit);

	if(ExitTime > 1)
		for(short_trades)
			if(TradeIsOpen && !(ThisTrade->dSignals))
				TradeExitTime = TradeTime+ExitTime;

	if(NumOpenShort < MaxTrades || is(ZORRO_ENUM_VALUE(EStatusFlag::TRAINMODE,TRAINMODE)))
		return enterShort();
	else if(Hedge <= 1)
		exitLong();
	return 0;
}

inline TRADE* reverseLong(int MaxTrades,function f)
{
	reverseLong(0);
	if(NumOpenLong < MaxTrades)
		return enterLong(f);
	return 0;
}

inline TRADE* reverseShort(int MaxTrades,function f)
{
	reverseShort(0);
	if(NumOpenShort < MaxTrades)
		return enterShort(f);
	return 0;
}

// helper function for printing the date
inline string datetime()
{
	return strf("%02d.%02d.%02d %02d:%02d:%02d",
		day(),month(),year()-2000,hour(),minute(),(int)second());
}

int scriptVersion()
{
	return SCRIPT_VERSION;
}

#undef ZORRO_ENUM_VALUE

#endif // default_h
