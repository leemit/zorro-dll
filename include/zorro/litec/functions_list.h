// This file contains all Zorro function definitions
// Add new functions to the end

// system functions
C R(int)  F(print)    A((int to,const char* format VA));
C R(int)  F(msg)      A((const char* format VA));
C R(HWND) F(window)   A((const char* title));
C R(void) F(keys)     A((const char* format VA));
C R(int)  F(mouse)    A((int* x,int* y,HWND hwnd));
C R(int)  F(hit)      A((int key));
C R(int)  F(progress) A((int n1,int n2));
C R(var)  F0(slider)  A((int n,int pos,int lower,int upper,string name,string tooltip VA));
C R(void) F(sound)    A((const char* filename));

C R(int)   F(login)   A((int mode));
C R(int)   F(exec)    A((const char* name,const char* args,int mode));
C R(void)  F(quit)    A((string text VA));
C R(int)   F(memory)  A((int mode));
C R(int)   F(wait)    A((int ms));
C R(var)   F(timer)   A(());
C R(int)   F(lock)    A(());
C R(void)  F(unlock)  A(());
C R(var)   F(version) A(());
C R(int)   F0(is)     A((long flag));
C R(int)   F1(is)     A((long mode,long flag));
C R(void)  F0(set)    A((long flag));
C R(void)  F1(set)    A((long* mode, long flag));
C R(void)  F0(reset)  A((long flag));
C R(void)  F1(reset)  A((long* mode,long flag));
C R(int)   F(mode)    A((long flag));
C R(var)   F(xtest)   A((var value));
C R(void*) F(ytest)   A((void* ptr,int mode));
C R(long)  F(checkLookBack) A((long num));

// chart
C R(void)   F(plot)       A((string name,var val,int type,zcolor color));
C R(void)   F(plotBar)    A((string name,int num,var label,var val,int type,zcolor color));
C R(void)   F(plotGraph)  A((string name,var num,var val,int type,zcolor color));
C R(DATA*)  F(plotData)   A((string name));
C R(zcolor) F(color)      A((var value,zcolor color1,zcolor color2,zcolor color3,zcolor color4 VA));
C R(zcolor) F(colorScale) A((zcolor color,var factor));

// price
C R(var) F(price)      A((int offset VA));
C R(var) F(priceOpen)  A((int offset VA));
C R(var) F(priceClose) A((int offset VA));
C R(var) F(priceHigh)  A((int offset VA));
C R(var) F(priceLow)   A((int offset VA));
C R(int) F(priceSet)   A((int offset,var open, var high, var low, var close));
C R(int) F(priceQuote) A((var timestamp,var quote));
C R(var) F(marketVal)  A((int offset VA));
C R(var) F(marketVol)  A((int offset VA));

// trading
C R(TRADE*) F0(enterLong)  A((function f,var v0,var v1,var v2,var v3,var v4,var v5,var v6,var v7 VA));
C R(TRADE*) F0(enterShort) A((function f,var v0,var v1,var v2,var v3,var v4,var v5,var v6,var v7 VA));
C R(void)   F0(exitLong)   A((string name,var limit,int lots VA));
C R(void)   F0(exitShort)  A((string name,var limit,int lots VA)); 
C R(int)    F0(exitTrade)  A((TRADE* tr,var limit,int lots VA)); 
C R(void)   F(cancelTrade) A((int id));
C R(TRADE*) F(forTrade)    A((int mode));
C R(TRADE*) F(findTrade)   A((string name));

// options / futures
C R(CONTRACT*) F0(contract)         A((int type,int days,var strike));
C R(CONTRACT*) F1(contract)         A((CONTRACT* c));
C R(CONTRACT*) F2(contract)         A((TRADE* tr));
C R(CONTRACT*) F3(contract)         A((int n));
C R(int)       F(contractUpdate)    A((string name,int handle,int mode));
C R(var)       F0(contractDays)     A((CONTRACT* c));
C R(var)       F1(contractDays)     A((TRADE* tr));
C R(var)       F0(contractPrice)    A((CONTRACT* c));
C R(var)       F1(contractPrice)    A((TRADE* tr));
C R(int)       F0(contractPosition) A((CONTRACT* c));
C R(int)       F1(contractPosition) A((TRADE* tr));
C R(int)       F(contractCheck)     A((TRADE* tr));
C R(void)      F(contractExercise)  A((TRADE* tr,var Price VA));

// algo / asset
C R(int)  F(algo)          A((string name));
C R(int)  F(asset)         A((string name));
C R(int)  F(assetType)     A((string name));
C R(void) F(assetAdd)      A((string name,var vPrice,var vSpread,var vRollLong,var vRollShort,var vPip,var vPipCost,var vMarginCost,var vLeverage,var vLotAmount,var vCommission,string sSymbol));
C R(int)  F(assetList)     A((string filename));
C R(int)  F(assetHistory)  A((string name,int mode));
C R(int)  F(brokerAsset)   A((string assetSymbol,var *pPrice,var *pSpread,var *pVol));
C R(var)  F(brokerCommand) A((int command,DWORD parameter));

// panel
C R(int)    F0(panel)    A((int rows,int cols,zcolor color,int size));
C R(int)    F1(panel)    A((string Filename,zcolor color,int size));
C R(string) F(panelGet)  A((int row,int col));
C R(int)    F(panelSet)  A((int row,int col,string text,zcolor color,int style,int type VA));
C R(int)    F(panelSave) A((string filename));
C R(int)    F(panelLoad) A((string filename));

// date/time
C R(int) F(year)          A((int offset VA));           // current year of the simulation
C R(int) F(month)         A((int offset VA));           // current month of the simulation, 1 = January
C R(int) F(week)          A((int offset VA));           // current week number 
C R(int) F(day)           A((int offset VA));           // current day (1..31)
C R(int) F(dom)           A((int offset VA));           // number of days of the current month, 28..31
C R(int) F(tdm)           A((int offset VA));           // trading day of the current month, 1..23
C R(int) F(tom)           A((int offset VA));           // number of trading days of the current month, 20..23
C R(int) F(dow)           A((int offset VA));           // current day of the week: 1 = Monday, to 7 = Sunday.
C R(int) F(ldow)          A((int zone, int offset VA)); // local day of the week
C R(int) F(hour)          A((int offset VA));           // current hour
C R(int) F(lhour)         A((int zone,int offset VA));  // local hour in the given time zone
C R(int) F(minute)        A((int offset VA));           // current minute
C R(var) F(second)        A(());                        // current second
C R(int) F(dst)           A((int zone,int offset VA));  // daylight saving (1 or 0)
C R(int) F(workday)       A((int offset VA));
C R(int) F(minutesAgo)    A((int offset));
C R(var) F(minutesWithin) A((int offset));
C R(int) F(timeOffset)    A((int zone,int days,int hour,int minute));
C R(int) F(market)        A((int zone,int offset));
C R(int) F1(market)       A((int zone));
C R(int) F0(date)         A((int offset));
C R(int) F1(date)         A(());
C R(int) F(tod)           A((int offset));
C R(int) F1(tod)          A(());
C R(int) F(ltod)          A((int zone,int offset));
C R(int) F1(ltod)         A((int zone));
C R(int) F(tow)           A((int offset));
C R(int) F1(tow)          A(());
C R(int) F(ltow)          A((int zone,int offset));
C R(int) F1(ltow)         A((int zone));
C R(var) F(wdate)         A((int offset));
C R(var) F1(wdate)        A(());
C R(var) F(wdateBar)      A((int n));
C R(var) F(wdatef)        A((const char* format,const char* dateTime));

C R(BOOL) F(frame)      A((int offset));
C R(int)  F(frameSync)  A((int period));

//saving/loading
C R(void) F(loadStatus) A((string name));
C R(void) F(saveStatus) A((string name));
C R(var)  F(getvar)     A((string fileName,string varName));
C R(void) F(putvar)     A((string fileName,string varName,var value));

// string/file
C R(var)    F(strvar)   A((string str,string name,var val));
C R(string) F(strtext)  A((string str,string name,string text));
C R(string) F0(strdate) A((string format,int offset));
C R(string) F1(strdate) A((string format,var date));
C R(string) F(strf)     A((const char* format VA));
C R(string) F(strx)     A((char* str,const char* orig,const char* repl));
C R(string) F(strxc)    A((char* str,char orig,char repl));
C R(string) F(strmid)   A((string str,int first,int count));
C R(int)    F(strcount) A((string str,char c));
C R(short*) F(strw)     A((const char* in));

// file
C R(string) F(file_content) A((string name));
C R(long)   F(file_read)    A((string name,string content,long size));
C R(long)   F0(file_append) A((string name,string content));
C R(long)   F1(file_append) A((string name,void* content,long size));
C R(long)   F(file_write)   A((string name,string content,long size));
C R(long)   F(file_copy)    A((string dest,string src));
C R(int)    F(file_delete)  A((string name));
C R(long)   F(file_length)  A((string name));
C R(long)   F(file_date)    A((string name));
C R(string) F(file_select)  A((string dir,string filter));

// internet 
C R(string) F(http_transfer) A((string url,string data));
C R(int)    F(http_send)     A((string url,string data,string header));
C R(int)    F(http_post)     A((string url,string data));
C R(int)    F(http_proxy)    A((string proxy,int port));
C R(long)   F(http_status)   A((int id));
C R(long)   F(http_result)   A((int id,string content,long size));
C R(int)    F(http_free)     A((int id));
C R(int)    F(ftp_download)  A((string url, string path, string username, string password));
C R(int)    F(ftp_upload)    A((string url, string path, string username, string password));
C R(int)    F(ftp_getdate)   A((string url, string username, string password));
C R(void)   F(ftp_stop)      A(());
C R(long)   F(ftp_size)      A(());
C R(long)   F(ftp_sent)      A(());
C R(long)   F(ftp_timestamp) A(());
C R(int)    F(ftp_status)    A(());
C R(int)    F(ftp_log)       A((int mode));

// dataset
C R(int)    F(dataDownload) A((const char* code,int mode,int period));
C R(int)    F0(dataParse)   A((int handle,const char* format,const char* fileName));
C R(void)   F(dataSave)     A((int handle,string fileName,int start,int num VA));
C R(void)   F(dataSaveCSV)  A((int handle,char* format,char* name,int start,int num VA));
C R(int)    F(dataLoad)     A((int handle,string fileName,int fields));
C R(float*) F(dataNew)      A((int handle,int records,int fields));
C R(void)   F(dataSort)     A((int handle));
C R(int)    F(dataMerge)    A((int handle1,int handle2));
C R(int)    F(dataAppend)   A((int handle1,int handle2,int start,int num VA));
C R(int)    F(dataFind)     A((int handle,var date));
C R(void)   F0(dataSet)     A((int handle,int row,int col,var value));
C R(void)   F1(dataSet)     A((int handle,int row,int col,int value));
C R(var)    F(dataVar)      A((int handle,int row,int col));
C R(int)    F(dataInt)      A((int handle,int row,int col));
C R(string) F(dataStr)      A((int handle,int row,int col));

// optimize
C R(var)   F(optimize)     A((var val,var start,var end,var step,var tolerance));
C R(char*) F0(loop)        A((void* p1 VA));
C R(var)   F0(adviseLong)  A((int method,var objective,var s0,var s1,var s2,var s3,var s4,var s5,var s6,var s7,var s8,var s9,var s10,var s11,var s12,var s13,var s14,var s15,var s16,var s17,var s18,var s19 VA));
C R(var)   F1(adviseLong)  A((int method,var objective,var* signals,long numSignals));
C R(var)   F0(adviseShort) A((int method,var objective,var s0,var s1,var s2,var s3,var s4,var s5,var s6,var s7,var s8,var s9,var s10,var s11,var s12,var s13,var s14,var s15,var s16,var s17,var s18,var s19 VA));
C R(var)   F1(adviseShort) A((int method,var objective,var* signals,long numSignals));

// series
C R(var*) F0(series)   A((var value,int length VA));
C R(void) F(shift)     A((var* data,var value,int length));
C R(var*) F(rev)       A((var* data,int length VA));
C R(void) F(sortData)  A((var* data,int length));
C R(int*) F(sortIdx)   A((var* data,int length));
C R(var)  F(randomize) A((int method,var *out,var *in,int length));

// math
C R(var)    F0(random)  A(());
C R(var)    F1(random)  A((var limit));
C R(void)   F(seed)     A((int s));
C R(var)    F(roundto)  A((var val,var step));
C R(var)    F(cdf)      A((var x));
C R(var)    F(qnorm)    A((var x));
C R(var)    F0(sign)    A((var a));
C R(int)    F1(sign)    A((int a));
C R(var)    F0(ifelse)  A((BOOL c,var a,var b));
C R(int)    F1(ifelse)  A((BOOL c,int a,int b));
C R(string) F2(ifelse)  A((BOOL c,string a,string b));
C R(var)    F0(clamp)   A((var a,var l,var h));
C R(var)    F1(clamp)   A((int a,int l,int h));
C R(BOOL)   F0(between) A((var a,var l,var h));
C R(BOOL)   F1(between) A((int a,int l,int h));

// curves
C R(BOOL) F(peak)        A((vars a));
C R(BOOL) F(valley)      A((vars a));
C R(BOOL) F0(crossOver)  A((vars a,vars b));
C R(BOOL) F1(crossOver)  A((vars a,var b));
C R(BOOL) F0(crossUnder) A((vars a,vars b));
C R(BOOL) F1(crossUnder) A((vars a,var b));
C R(BOOL) F(rising)      A((vars a));
C R(BOOL) F(falling)     A((vars a));
C R(var)  F(concave)     A((vars a));

// fuzzy
C R(BOOL) F(fuzzy)        A((var a));
C R(BOOL) F(eq)           A((var a,var b));
C R(var)  F(betweenF)     A((var a,var l,var h));
C R(var)  F(andF)         A((var a,var b));
C R(var)  F(orF)          A((var a,var b));
C R(var)  F(notF)         A((var a));
C R(var)  F(equalF)       A((var a,var b));
C R(var)  F(aboveF)       A((var a,var b));
C R(var)  F(belowF)       A((var a,var b));
C R(var)  F(peakF)        A((var* a));
C R(var)  F(valleyF)      A((var* a));
C R(var)  F(risingF)      A((var* a));
C R(var)  F(fallingF)     A((var* a));
C R(var)  F0(crossOverF)  A((var* a,var* b));
C R(var)  F1(crossOverF)  A((var* a,var b));
C R(var)  F0(crossUnderF) A((var* a,var* b));
C R(var)  F1(crossUnderF) A((var* a,var b));

// matrix
C R(mat) F(matrix)   A((int rows,int cols VA));
C R(mat) F(matTrans) A((mat m,mat a));
C R(mat) F0(matSet)  A((mat m,mat a));
C R(mat) F1(matSet)  A((mat m,int row,int col,mat a));
C R(mat) F2(matSet)  A((mat m,var c));
C R(mat) F(matAdd)   A((mat m,mat a,mat b));
C R(mat) F(matSub)   A((mat m,mat a,mat b));
C R(mat) F(matMul)   A((mat m,mat a,mat b));
C R(mat) F(matScale) A((mat m,var c));

// normalize
C R(var) F(center)    A((var x,int timePeriod));
C R(var) F(compress)  A((var x,int timePeriod));
C R(var) F(scale)     A((var x,int timePeriod));
C R(var) F(normalize) A((var x,int timePeriod));
C R(var) F(zscore)    A((var x,int timePeriod));
C R(var) F(diff)      A((var val));

// analysis
C R(int) F(predict)           A((int type,vars data,int timePeriod,var threshold));
C R(var) F(polyfit)           A((var* a,vars data,int timePeriod,int n,var weight));
C R(var) F(polynom)           A((var* a,int n));
C R(var) F(frechet)           A((vars data,int timePeriod,var factor,var* pattern));
C R(var) F(verify)            A((vars data,int length,var depth,int width,int horizon));
C R(var) F0(markowitz)        A((var* covMatrix,var* means,int n,var* caps));
C R(var) F1(markowitz)        A((var* covMatrix,var* means,int n,var cap));
C R(var) F(markowitzReturn)   A((var* weights,var vVariance));
C R(var) F(markowitzVariance) A((var* weights,var vReturn));

// filters
C R(var) F(Gauss)          A((vars data,int length));
C R(var) F(Median)         A((vars data,int length));
C R(var) F(Percentile)     A((vars data,int length,var percent));
C R(var) F(PercentRank)    A((vars data,int length,var value));
C R(var) F(DominantPeriod) A((vars data,int period));
C R(var) F(DominantPhase)  A((vars data,int period));
C R(var) F(HighPass1)      A((vars data,int cutoff));
C R(var) F(HighPass)       A((vars data,int cutoff));
C R(var) F0(LowPass)       A((vars data,int cutoff));
C R(var) F1(LowPass)       A((vars buffer,var Val,int period));
C R(var) F(BandPass)       A((vars data,int period,var delta));
C R(var) F(Spectrum)       A((vars data,int timePeriod,int samplePeriod));
C R(var) F1(Spectrum)      A((vars data,int timePeriod));

// TA-LIB
C R(var) F(ADX)         A((int timePeriod));
C R(var) F(ADXR)        A((int timePeriod));
C R(var) F(Amplitude)   A((vars data,int timePeriod));
C R(var) F(APO)         A((vars data,int fastPeriod,int slowPeriod,int MAType));
C R(var) F(Aroon)       A((int timePeriod));
C R(var) F(AroonOsc)    A((int timePeriod));
C R(var) F0(ATR)        A((int timePeriod));
C R(var) F1(ATR)        A((vars open,vars high,vars low,vars close,int timePeriod));
C R(var) F(AvgPrice)    A(());
C R(var) F(BBands)      A((vars data,int timePeriod,var nbDevUp,var nbDevDn,int MAType));
C R(var) F(Beta)        A((vars data,vars data2,int timePeriod));
C R(var) F(BOP)         A(());
C R(var) F(CCI)         A((int timePeriod));
C R(var) F(CMO)         A((vars data,int timePeriod));
C R(var) F(Correlation) A((vars data,vars Data2,int timePeriod));
C R(var) F(Covariance)  A((vars data,vars Data2,int timePeriod));
C R(var) F(DEMA)        A((vars data,int timePeriod));
C R(var) F(DX)          A((int timePeriod));
C R(var) F0(EMA)        A((vars data,int timePeriod));
C R(var) F1(EMA)        A((vars data,var alpha));
C R(var) F(HTDcPeriod)  A((vars data));
C R(var) F(HTDcPhase)   A((vars data));
C R(var) F(HTPhasor)    A((vars data));
C R(var) F(HTSine)      A((vars data));
C R(var) F(HTTrendline) A((vars data));
C R(int) F(HTTrendMode) A((vars data));
C R(var) F(KAMA)        A((vars data,int timePeriod));
C R(var) F(LinearReg)   A((vars data,int timePeriod));
C R(var) F(LinearRegAngle) A((vars data,int timePeriod));
C R(var) F(LinearRegIntercept) A((vars data,int timePeriod));
C R(var) F(LinearRegSlope) A((vars data,int timePeriod));
C R(var) F(MovingAverage) A((vars data,int timePeriod,int MAType));
C R(var) F(MACD)        A((vars data,int fastPeriod,int slowPeriod,int signalPeriod));
C R(var) F(MACDExt)     A((vars data,int fastPeriod,int fastMAType,int slowPeriod,int slowMAType,int signalPeriod,int signalMAType));
C R(var) F(MACDFix)     A((vars data,int signalPeriod));
C R(var) F(MAMA)        A((vars data,var fastLimit,var slowLimit));
C R(var) F(MovingAverageVariablePeriod) A((vars data,vars data2,int minPeriod,int maxPeriod,int MAType));
C R(var) F(MaxVal)      A((vars data,int timePeriod));
C R(int) F(MaxIndex)    A((vars data,int timePeriod));
C R(var) F(MedPrice)    A(());
C R(var) F(MidPoint)    A((vars data,int timePeriod));
C R(var) F(MidPrice)    A((int timePeriod));
C R(var) F(MinVal)      A((vars data,int timePeriod));
C R(int) F(MinIndex)    A((vars data,int timePeriod));
C R(var) F(MinMax)      A((vars data,int timePeriod));
C R(int) F(MinMaxIndex) A((vars data,int timePeriod));
C R(var) F0(MinusDI)    A((int timePeriod));
C R(var) F1(MinusDI)    A((vars open,vars high,vars low,vars close,int timePeriod));
C R(var) F0(MinusDM)    A((int timePeriod));
C R(var) F1(MinusDM)    A((vars open,vars high,vars low,vars close,int timePeriod));
C R(var) F(Mom)         A((vars data,int timePeriod));
C R(var) F(NATR)        A((int timePeriod));
C R(var) F0(PlusDI)     A((int timePeriod));
C R(var) F1(PlusDI)     A((vars open,vars high,vars low,vars close,int timePeriod));
C R(var) F0(PlusDM)     A((int timePeriod));
C R(var) F1(PlusDM)     A((vars open,vars high,vars low,vars close,int timePeriod));
C R(var) F(PPO)         A((vars data,int fastPeriod,int slowPeriod,int MAType));
C R(var) F(ROC)         A((vars data,int timePeriod));
C R(var) F(ROCP)        A((vars data,int timePeriod));
C R(var) F(ROCR)        A((vars data,int timePeriod));
C R(var) F(ROCL)        A((vars data,int timePeriod));
C R(var) F(ROCR100)     A((vars data,int timePeriod));
C R(var) F(RSI)         A((vars data,int timePeriod));
C R(var) F(SMA)         A((vars data,int timePeriod));
C R(var) F(StdDev)      A((vars data,int timePeriod));
C R(var) F0(Stoch)      A((int fastK_Period,int slowK_Period,int slowK_MAType,int slowD_Period,int slowD_MAType));
C R(var) F1(Stoch)      A((vars open,vars high,vars low,vars close,int fastK_Period,int slowK_Period,int slowK_MAType,int slowD_Period,int slowD_MAType));
C R(var) F(StochF)      A((int fastK_Period,int fastD_Period,int fastD_MAType));
C R(var) F(StochRSI)    A((vars data,int timePeriod,int fastK_Period,int fastD_Period,int fastD_MAType));
C R(var) F(Sum)         A((vars data,int timePeriod));
C R(var) F(T3)          A((vars data,int timePeriod,var vFactor));
C R(var) F(TEMA)        A((vars data,int timePeriod));
C R(var) F(TrueRange)   A(());
C R(var) F(Trima)       A((vars data,int timePeriod));
C R(var) F(Trix)        A((vars data,int timePeriod));
C R(var) F(TSF)         A((vars data,int timePeriod));
C R(var) F(TypPrice)    A(());
C R(var) F(UltOsc)      A((int timePeriod1,int timePeriod2,int timePeriod3));
C R(var) F(Variance)    A((vars data,int timePeriod));
C R(var) F(WCLPrice)    A(());
C R(var) F(WillR)       A((int timePeriod));
C R(var) F(WMA)         A((vars data,int timePeriod));

// TA_LIB CDL
C R(int) F(CDL2Crows)           A(());
C R(int) F(CDL3BlackCrows)      A(());
C R(int) F(CDL3Inside)          A(());
C R(int) F(CDL3LineStrike)      A(());
C R(int) F(CDL3Outside)         A(());
C R(int) F(CDL3StarsInSouth)    A(());
C R(int) F(CDL3WhiteSoldiers)   A(());
C R(int) F(CDLAbandonedBaby)    A((var penetration));
C R(int) F(CDLAdvanceBlock)     A(());
C R(int) F(CDLBeltHold)         A(());
C R(int) F(CDLBreakaway)        A(());
C R(int) F(CDLClosingMarubozu)  A(());
C R(int) F(CDLConcealBabysWall) A(());
C R(int) F(CDLCounterAttack)    A(());
C R(int) F(CDLDarkCloudCover)   A((var penetration));
C R(int) F(CDLDoji)             A(());
C R(int) F(CDLDojiStar)         A(());
C R(int) F(CDLDragonflyDoji)    A(());
C R(int) F(CDLEngulfing)        A(());
C R(int) F(CDLEveningDojiStar)  A((var penetration));
C R(int) F(CDLEveningStar)      A((var penetration));
C R(int) F(CDLGapSideSideWhite) A(());
C R(int) F(CDLGravestoneDoji)   A(());
C R(int) F(CDLHammer)           A(());
C R(int) F(CDLHangingMan)       A(());
C R(int) F(CDLHarami)           A(());
C R(int) F(CDLHaramiCross)      A(());
C R(int) F(CDLHignWave)         A(());
C R(int) F(CDLHikkake)          A(());
C R(int) F(CDLHikkakeMod)       A(());
C R(int) F(CDLHomingPigeon)     A(());
C R(int) F(CDLIdentical3Crows)  A(());
C R(int) F(CDLInNeck)           A(());
C R(int) F(CDLInvertedHammer)   A(());
C R(int) F(CDLKicking)          A(());
C R(int) F(CDLKickingByLength)  A(());
C R(int) F(CDLLadderBottom)     A(());
C R(int) F(CDLLongLeggedDoji)   A(());
C R(int) F(CDLLongLine)         A(());
C R(int) F(CDLMarubozu)         A(());
C R(int) F(CDLMatchingLow)      A(());
C R(int) F(CDLMatHold)          A((var penetration));
C R(int) F(CDLMorningDojiStar)  A((var penetration));
C R(int) F(CDLMorningStar)      A((var penetration));
C R(int) F(CDLOnNeck)           A(());
C R(int) F(CDLPiercing)         A(());
C R(int) F(CDLRickshawMan)      A(());
C R(int) F(CDLRiseFall3Methods) A(());
C R(int) F(CDLSeperatingLines)  A(());
C R(int) F(CDLShootingStar)     A(());
C R(int) F(CDLShortLine)        A(());
C R(int) F(CDLSpinningTop)      A(());
C R(int) F(CDLStalledPattern)   A(());
C R(int) F(CDLStickSandwhich)   A(());
C R(int) F(CDLTakuri)           A(());
C R(int) F(CDLTasukiGap)        A(());
C R(int) F(CDLThrusting)        A(());
C R(int) F(CDLTristar)          A(());
C R(int) F(CDLUnique3River)     A(());
C R(int) F(CDLUpsideGap2Crows)  A(());
C R(int) F(CDLXSideGap3Methods) A(());

// indicators.c
C R(var) F(AC)               A((vars data));
C R(var) F(ADO)              A(());
C R(var) F0(AGC)             A((vars data, var alpha));
C R(var) F1(AGC)             A((vars data, int period));
C R(var) F0(ALMA)            A((vars data, int timePeriod, int sigma, var offset));
C R(var) F1(ALMA)            A((vars data, int timePeriod));
C R(var) F(AO)               A((vars data));
C R(var) F(ATRS)             A((int period));
C R(var) F(Alligator)        A((vars data));
C R(var) F(BBOsc)            A((vars data,int period,var nbDev,int MAType));
C R(var) F(Butterworth)      A((vars data,int cutoff));
C R(var) F(CGOsc)            A((vars data,int period));
C R(var) F(CI)               A((int timePeriod));
C R(var) F(ChandelierLong)   A((int timePeriod,var multipl));
C R(var) F(ChandelierShort)  A((int timePeriod,var multipl));
C R(var) F(Chikou)           A((int shift));
C R(var) F(Coral)            A((vars data));
C R(var) F(DCOsc)            A((vars data,int period));
C R(var) F(DChannel)         A((int period));
C R(var) F(DPO)              A((vars data, int timePeriod));
C R(var) F(Decycle)          A((vars data,int period));
C R(var) F(FIR3)             A((vars data));
C R(var) F(FIR4)             A((vars data));
C R(var) F(FIR6)             A((vars data));
C R(var) F(Fisher)           A((vars data));
C R(var) F(FisherInv)        A((vars data));
C R(var) F(FisherN)          A((vars data,int period));
C R(var) F(FractalDimension) A((vars data,int period));
C R(var) F(FractalHigh)      A((vars data,int period));
C R(var) F(FractalLow)       A((vars data,int period));
C R(var) F(HAClose)          A(());
C R(var) F(HAHigh)           A(());
C R(var) F(HALow)            A(());
C R(var) F(HAOpen)           A(());
C R(var) F(HH)               A((int period,int offset));
C R(var) F(HMA)              A((vars data,int period));
C R(var) F(HighPass2)        A((vars data,int cutoffPeriod)); 
C R(var) F(Hurst)            A((vars data,int period));
C R(var) F(IBS)              A(());
C R(var) F(Ichimoku)         A((int periodTenkan,int periodKijun,int periodSenkou,int offset));
C R(var) F(Keltner)          A((vars data, int timePeriod, var factor));
C R(var) F(LL)               A((int period,int offset)); 
C R(var) F(Laguerre)         A((vars data, var alpha));
C R(var) F(MMI)              A((vars data,int timePeriod));
C R(var) F(Moment)           A((vars data,int period,int n));
C R(var) F(Normalize)        A((vars data,int period));
C R(int) F(NumInRange)       A((vars low,vars high,var vMin,var vMax,int period));
C R(int) F(NumRiseFall)      A((vars data,int period));
C R(int) F(NumWhiteBlack)    A((var vBody,int offset,int period));
C R(var) F(ProfitFactor)     A((vars data,int length));
C R(var) F(RVI)              A((int period));
C R(var) F(Roof)             A((vars data,int cutOffLow,int cutOffHigh));
C R(var) F(SAR)              A((var AFstep,var AFmin,var AFmax));
C R(var) F(SIROC)            A((vars data, int timePeriod, int EMAPeriod)); 
C R(var) F(SMom)             A((vars data,int period,int cutoff));
C R(var) F(ShannonEntropy)   A((vars data,int length,int patternSize));
C R(var) F(ShannonGain)      A((vars data,int period));
C R(var) F(Smooth)           A((vars data,int cutoff));
C R(var) F(Spearman)         A((vars data,int period));
C R(var) F(StochEhlers)      A((vars data,int timePeriod,int cutOffLow,int cutOffHigh));
C R(var) F(TSI)              A((vars data,int period));
C R(var) F(UO)               A((vars data,int cutoff));
C R(var) F(Volatility)       A((vars data,int period));
C R(var) F(VolatilityC)      A((int timePeriod,int EMAPeriod));
C R(var) F(VolatilityMM)     A((vars data,int timePeriod,int EMAPeriod));
C R(var) F(ZMA)              A((vars data,int period));
C R(var) F(ZigZag)           A((vars data,var depth,int length,zcolor color));

C R(var)   F(ccyStrength) A((char* currency));
C R(void)  F(ccySet)      A((var strength));
C R(void)  F(ccyReset)    A(());
C R(char*) F(ccyMin)      A(());
C R(char*) F(ccyMax)      A(());
C R(var)   F(dayClose)    A((int zone,int day));
C R(var)   F(dayHigh)     A((int zone,int day));
C R(var)   F(dayLow)      A((int zone,int day));
C R(var)   F(dayOpen)     A((int zone,int day));
C R(var)   F(dayPivot)    A((int zone,int day));
C R(var)   F(genNoise)    A(());
C R(var)   F(genSine)     A((var period1, var period2));
C R(var)   F(genSquare)   A((var period1, var period2));
C R(var)   F(move)        A((vars data,int length,int movePeriod,var percent));
C R(var)   F(season)      A((vars data,int timePeriod,int horizon,int mode));

C R(int)   F(stridx)      A((const char* name));
C R(char*) F(strxid)      A((int index));
C R(int)   F1(dataParse)  A((int handle,const char* format,const char* fileName,int start,int num));
C R(int)   F2(dataParse)  A((int handle,const char* format,const char* fileName,const char* filter));

#undef F
#undef F0
#undef F1
#undef F2
#undef F3
#undef C
#undef R
#undef A
