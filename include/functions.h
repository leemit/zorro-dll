/////////////////////////////////////////////////////////////////////
// Trading functions
// (c) oP group 2017
/////////////////////////////////////////////////////////////////////
#ifndef functions_h
#define functions_h

#ifndef F	// header for lite-C
#define F(x) x
#define F0(x) x
#define F1(x) x
#define F2(x) x
#define F3(x) x
#define C
#endif

// system functions
C int F(print)(int to,const char* format,...);
C int F(msg)(const char* format,...);
C HWND F(window)(const char* title);
C void F(keys)(const char* format,...);
C int F(mouse)(int* x,int* y,HWND hwnd);
C int F(hit)(int key);
C int F(progress)(int n1,int n2);
C var F0(slider)(int N,int Pos,int Lower,int Upper,string Name,string Tooltip,...);
C void F(sound)(const char* filename);

C int F(login)(int mode);
C int F(exec)(const char* name,const char* args,int mode);
C void F(quit)(string text,...);
C int F(memory)(int mode);
C int F(wait)(int ms);
C var F(timer)();
C int F(lock)();
C void F(unlock)();
C var F(version)();
C int F0(is)(long Flag);
C int F1(is)(long Mode,long Flag);
C void F0(set)(long Flag);
C void F1(set)(long* Mode, long Flag);
C void F0(reset)(long Flag);
C void F1(reset)(long* Mode,long Flag);
C int F(mode)(long flag);
C var F(xtest)(var value);
C void* F(ytest)(void* ptr,int mode);
C long F(checkLookBack)(long num);
// chart
C void F(plot)(string name,var val,int type,int color);
C void F(plotBar)(string name,int num,var label,var val,int type,int color);
C void F(plotGraph)(string name,var num,var val,int type,int color);
C DATA* F(plotData)(string name);
C DWORD F(color)(var Value,DWORD color1,DWORD color2,DWORD color3,DWORD color4,...);
C DWORD F(colorScale)(DWORD Color,var Factor);

// price
C var F(price)(int offset,...);
C var F(priceOpen)(int offset,...);
C var F(priceClose)(int offset,...);
C var F(priceHigh)(int offset,...);
C var F(priceLow)(int offset,...);
C int F(priceSet)(int offset,var Open, var High, var Low, var Close);
C int F(priceQuote)(var Timestamp,var Quote);
C var F(marketVal)(int offset,...);
C var F(marketVol)(int offset,...);
// trading
C TRADE* F0(enterLong)(function f,var v0,var v1,var v2,var v3,var v4,var v5,var v6,var v7,...);
C TRADE* F0(enterShort)(function f,var v0,var v1,var v2,var v3,var v4,var v5,var v6,var v7,...);
C void F0(exitLong)(string name,var Limit,int lots,...);	
C void F0(exitShort)(string name,var Limit,int lots,...); 
C int F0(exitTrade)(TRADE* tr,var Limit,int lots,...); 
C void F(cancelTrade)(int id);	
C TRADE* F(forTrade)(int mode);	
C TRADE* F(findTrade)(string name);	
// options / futures
C CONTRACT* F0(contract)(int Type,int Days,var Strike);
C CONTRACT* F1(contract)(CONTRACT* c);
C CONTRACT* F2(contract)(TRADE* tr);
C CONTRACT* F3(contract)(int N);
C int F(contractUpdate)(string Name,int Handle,int Mode);
C var F0(contractDays)(CONTRACT* c);
C var F1(contractDays)(TRADE* tr);
C var F0(contractPrice)(CONTRACT* c);
C var F1(contractPrice)(TRADE* tr);
C int F0(contractPosition)(CONTRACT* c);
C int F1(contractPosition)(TRADE* tr);
C int F(contractCheck)(TRADE* tr);
C void F(contractExercise)(TRADE* tr,var Price,...);
// algo / asset
C int F(algo)(string Name);		
C int F(asset)(string Name);		
C int F(assetType)(string Name);
C void F(assetAdd)(string Name,var vPrice,var vSpread,var vRollLong,var vRollShort,var vPip,var vPipCost,var vMarginCost,var vLeverage,var vLotAmount,var vCommission,string sSymbol);
C int F(assetList)(string Filename);
C int F(assetHistory)(string Name,int Mode);
C int F(brokerAsset)(string AssetSymbol,var *pPrice,var *pSpread,var *pVol);
C var F(brokerCommand)(int command,DWORD Parameter);
// panel
C int F0(panel)(int rows,int cols,int color,int size);
C int F1(panel)(string Filename,int color,int size);
C string F(panelGet)(int row,int col);
C int F(panelSet)(int row,int col,string text,int color,int style,int type,...);
C int F(panelSave)(string Filename);
C int F(panelLoad)(string Filename);
// date/time
C int F(year)(int offset,...);	// current year of the simulation
C int F(month)(int offset,...);	// current month of the simulation, 1 = January
C int F(week)(int offset,...);	// current week number 
C int F(day)(int offset,...);	// current day (1..31)
C int F(dom)(int offset,...);	// number of days of the current month, 28..31
C int F(tdm)(int offset,...);	// trading day of the current month, 1..23
C int F(tom)(int offset,...);	// number of trading days of the current month, 20..23
C int F(dow)(int offset,...);	// current day of the week: 1 = Monday, to 7 = Sunday.
C int F(ldow)(int zone, int offset,...); // local day of the week
C int F(hour)(int offset,...);	// current hour
C int F(lhour)(int zone,int offset,...);	// local hour in the given time zone
C int F(minute)(int offset,...);	// current minute
C var F(second)();					// current second
C int F(dst)(int zone,int offset,...);		// daylight saving (1 or 0)
C int F(workday)(int offset,...);
C int F(minutesAgo)(int offset);
C var F(minutesWithin)(int offset);
C int F(timeOffset)(int zone,int days,int hour,int minute);	
C int F(market)(int zone,int offset);
C int F1(market)(int zone);
C int F0(date)(int offset);
C int F1(date)();
C int F(tod)(int offset);
C int F1(tod)();
C int F(ltod)(int zone,int offset);
C int F1(ltod)(int zone);
C int F(tow)(int offset);
C int F1(tow)();
C int F(ltow)(int zone,int offset);
C int F1(ltow)(int zone);
C var F(wdate)(int offset);
C var F1(wdate)();
C var F(wdateBar)(int n);
C var F(wdatef)(const char* Format,const char* DateTime);
 
C BOOL F(frame)(int offset);
C int F(frameSync)(int Period);
//saving/loading
C void F(loadStatus)(string name);
C void F(saveStatus)(string name);
C var F(getvar)(string FileName,string VarName);
C void F(putvar)(string FileName,string VarName,var Value);
// string/file
C var F(strvar)(string str,string name,var val);
C string F(strtext)(string str,string name,string text);
C string F0(strdate)(string format,int offset);
C string F1(strdate)(string format,var date);
C string F(strf)(const char* format,...);
C string F(strx)(char* str,const char* orig,const char* repl);
C string F(strxc)(char* str,char orig,char repl);
C string F(strmid)(string str,int first,int count);
C int F(strcount)(string str,char c);
C short* F(strw)(const char* in);
// file
C string F(file_content)(string name);
C long F(file_read)(string name,string content,long size);
C long F0(file_append)(string name,string content);
C long F1(file_append)(string name,void* content,long size);
C long F(file_write)(string name,string content,long size);
C long F(file_copy)(string dest,string src);
C int F(file_delete)(string name);
C long F(file_length)(string name);
C long F(file_date)(string name);
C string F(file_select)(string dir,string filter);
// internet 
C string F(http_transfer)(string url,string data);
C int F(http_send)(string url,string data,string header);
C int F(http_post)(string url,string data);
C int F(http_proxy)(string proxy,int port);
C long F(http_status)(int id);
C long F(http_result)(int id,string content,long size);
C int F(http_free)(int id);
C int F(ftp_download)(string url, string path, string username, string password);
C int F(ftp_upload)(string url, string path, string username, string password);
C int F(ftp_getdate)(string url, string username, string password);
C void F(ftp_stop)();
C long F(ftp_size)();
C long F(ftp_sent)();
C long F(ftp_timestamp)();
C int F(ftp_status)();
C int F(ftp_log)(int mode);
// dataset
C int F(dataDownload)(const char* Code,int Mode,int Period);
C int F0(dataParse)(int Handle,const char* Format,const char* FileName);
C void F(dataSave)(int Handle,string FileName,int Start,int Num,...);
C void F(dataSaveCSV)(int Handle,char* Format,char* Name,int Start,int Num,...);
C int F(dataLoad)(int Handle,string FileName,int Fields);
C float* F(dataNew)(int Handle,int Records,int Fields);
C void F(dataSort)(int Handle);
C int F(dataMerge)(int Handle1,int Handle2);
C int F(dataAppend)(int Handle1,int Handle2,int Start,int Num,...);
C int F(dataFind)(int Handle,var Date);
C void F0(dataSet)(int Handle,int Row,int Col,var Value);
C void F1(dataSet)(int Handle,int Row,int Col,int Value);
C var F(dataVar)(int Handle,int Row,int Col);
C int F(dataInt)(int Handle,int Row,int Col);
C string F(dataStr)(int Handle,int Row,int Col);
// optimize
C var F(optimize)(var val,var start,var end,var step,var tolerance);
C char* F0(loop)(void* p1,...);
C var F0(adviseLong)(int Method,var Objective,var s0,var s1,var s2,var s3,var s4,var s5,var s6,var s7,var s8,var s9,var s10,var s11,var s12,var s13,var s14,var s15,var s16,var s17,var s18,var s19,...);
C var F1(adviseLong)(int Method,var Objective,var* Signals,long NumSignals);
C var F0(adviseShort)(int Method,var Objective,var s0,var s1,var s2,var s3,var s4,var s5,var s6,var s7,var s8,var s9,var s10,var s11,var s12,var s13,var s14,var s15,var s16,var s17,var s18,var s19,...);
C var F1(adviseShort)(int Method,var Objective,var* Signals,long NumSignals);
// series
C var* F0(series)(var value,int length,...);
C void F(shift)(var* Data,var value,int length);
C var* F(rev)(var* Data,int length,...);
C void F(sortData)(var* Data,int length);
C int* F(sortIdx)(var* Data,int length);
C var F(randomize)(int Method,var *Out,var *In,int Length);
// math
C var F0(random)();	
C var F1(random)(var limit);
C void F(seed)(int s);
C var F(roundto)(var val,var step);
C var F(cdf)(var x);
C var F(qnorm)(var x);
C var F0(sign)(var a);
C int F1(sign)(int a);
C var F0(ifelse)(BOOL c,var a,var b);
C int F1(ifelse)(BOOL c,int a,int b);
C string F2(ifelse)(BOOL c,string a,string b);
C var F0(clamp)(var a,var l,var h);
C var F1(clamp)(int a,int l,int h);
C BOOL F0(between)(var a,var l,var h);
C BOOL F1(between)(int a,int l,int h);
// curves
C BOOL F(peak)(vars a);
C BOOL F(valley)(vars a);
C BOOL F0(crossOver)(vars a,vars b);
C BOOL F1(crossOver)(vars a,var b);
C BOOL F0(crossUnder)(vars a,vars b);
C BOOL F1(crossUnder)(vars a,var b);
C BOOL F(rising)(vars a);
C BOOL F(falling)(vars a);
C var F(concave)(vars a);
// fuzzy
C BOOL F(fuzzy)(var a);
C BOOL F(eq)(var a,var b);
C var F(betweenF)(var a,var l,var h);
C var F(andF)(var a,var b);
C var F(orF)(var a,var b);
C var F(notF)(var a);
C var F(equalF)(var a,var b);
C var F(aboveF)(var a,var b);
C var F(belowF)(var a,var b);
C var F(peakF)(var* a);
C var F(valleyF)(var* a);
C var F(risingF)(var* a);
C var F(fallingF)(var* a);
C var F0(crossOverF)(var* a,var* b);
C var F1(crossOverF)(var* a,var b);
C var F0(crossUnderF)(var* a,var* b);
C var F1(crossUnderF)(var* a,var b);
// matrix
C mat F(matrix)(int rows,int cols,...);
C mat F(matTrans)(mat M,mat A);
C mat F0(matSet)(mat M,mat A);
C mat F1(matSet)(mat M,int row,int col,mat A);
C mat F2(matSet)(mat M,var c);
C mat F(matAdd)(mat M,mat A,mat B);
C mat F(matSub)(mat M,mat A,mat B);
C mat F(matMul)(mat M,mat A,mat B);
C mat F(matScale)(mat M,var c);
// normalize
C var F(center)(var x,int TimePeriod);
C var F(compress)(var x,int TimePeriod);
C var F(scale)(var x,int TimePeriod);
C var F(normalize)(var x,int TimePeriod);
C var F(zscore)(var x,int TimePeriod);
C var F(diff)(var val);
// analysis
C int F(predict)(int type,vars Data,int TimePeriod,var Threshold);
C var F(polyfit)(var* a,vars Data,int TimePeriod,int n,var weight);
C var F(polynom)(var* a,int n);
C var F(frechet)(vars Data,int TimePeriod,var factor,var* pattern);
C var F(verify)(vars Data,int Length,var Depth,int Width,int Horizon);
C var F0(markowitz)(var* CovMatrix,var* Means,int N,var* Caps);
C var F1(markowitz)(var* CovMatrix,var* Means,int N,var Cap);
C var F(markowitzReturn)(var* Weights,var Variance);
C var F(markowitzVariance)(var* Weights,var Return);
// filters
C var F(Gauss)(vars Data,int Length);
C var F(Median)(vars Data,int Length);
C var F(Percentile)(vars Data,int Length,var Percent);
C var F(PercentRank)(vars Data,int length,var value);
C var F(DominantPeriod)(vars Data,int Period);
C var F(DominantPhase)(vars Data,int Period);
C var F(HighPass1)(vars Data,int Cutoff);
C var F(HighPass)(vars Data,int Cutoff);
C var F0(LowPass)(vars Data,int Cutoff);
C var F1(LowPass)(vars Buffer,var Val,int Period);
C var F(BandPass)(vars Data,int Period,var Delta);
C var F(Spectrum)(vars Data,int TimePeriod,int SamplePeriod);
C var F1(Spectrum)(vars Data,int TimePeriod);
// TA-LIB
C var F(ADX)(int TimePeriod);
C var F(ADXR)(int TimePeriod);
C var F(Amplitude)(vars Data,int TimePeriod);
C var F(APO)(vars Data,int FastPeriod,int SlowPeriod,int MAType);
C var F(Aroon)(int TimePeriod);
C var F(AroonOsc)(int TimePeriod);
C var F0(ATR)(int TimePeriod);
C var F1(ATR)(vars Open,vars High,vars Low,vars Close,int TimePeriod);
C var F(AvgPrice)();
C var F(BBands)(vars Data,int TimePeriod,var NbDevUp,var NbDevDn,int MAType);
C var F(Beta)(vars Data,vars Data2,int TimePeriod);
C var F(BOP)();
C var F(CCI)(int TimePeriod);
C var F(CMO)(vars Data,int TimePeriod);
C var F(Correlation)(vars Data,vars Data2,int TimePeriod);
C var F(Covariance)(vars Data,vars Data2,int TimePeriod);
C var F(DEMA)(vars Data,int TimePeriod);
C var F(DX)(int TimePeriod);
C var F0(EMA)(vars Data,int TimePeriod);
C var F1(EMA)(vars Data,var alpha);
C var F(HTDcPeriod)(vars Data);
C var F(HTDcPhase)(vars Data);
C var F(HTPhasor)(vars Data);
C var F(HTSine)(vars Data);
C var F(HTTrendline)(vars Data);
C int F(HTTrendMode)(vars Data);
C var F(KAMA)(vars Data,int TimePeriod);
C var F(LinearReg)(vars Data,int TimePeriod);
C var F(LinearRegAngle)(vars Data,int TimePeriod);
C var F(LinearRegIntercept)(vars Data,int TimePeriod);
C var F(LinearRegSlope)(vars Data,int TimePeriod);
C var F(MovingAverage)(vars Data,int TimePeriod,int MAType);
C var F(MACD)(vars Data,int FastPeriod,int SlowPeriod,int SignalPeriod);
C var F(MACDExt)(vars Data,int FastPeriod,int FastMAType,int SlowPeriod,int SlowMAType,int SignalPeriod,int SignalMAType);
C var F(MACDFix)(vars Data,int SignalPeriod);
C var F(MAMA)(vars Data,var FastLimit,var SlowLimit);
C var F(MovingAverageVariablePeriod)(vars Data,vars Data2,int MinPeriod,int MaxPeriod,int MAType);
C var F(MaxVal)(vars Data,int TimePeriod);
C int F(MaxIndex)(vars Data,int TimePeriod);
C var F(MedPrice)();
C var F(MidPoint)(vars Data,int TimePeriod);
C var F(MidPrice)(int TimePeriod);
C var F(MinVal)(vars Data,int TimePeriod);
C int F(MinIndex)(vars Data,int TimePeriod);
C var F(MinMax)(vars Data,int TimePeriod);
C int F(MinMaxIndex)(vars Data,int TimePeriod);
C var F0(MinusDI)(int TimePeriod);
C var F1(MinusDI)(vars Open,vars High,vars Low,vars Close,int TimePeriod);
C var F0(MinusDM)(int TimePeriod);
C var F1(MinusDM)(vars Open,vars High,vars Low,vars Close,int TimePeriod);
C var F(Mom)(vars Data,int TimePeriod);
C var F(NATR)(int TimePeriod);
C var F0(PlusDI)(int TimePeriod);
C var F1(PlusDI)(vars Open,vars High,vars Low,vars Close,int TimePeriod);
C var F0(PlusDM)(int TimePeriod);
C var F1(PlusDM)(vars Open,vars High,vars Low,vars Close,int TimePeriod);
C var F(PPO)(vars Data,int FastPeriod,int SlowPeriod,int MAType);
C var F(ROC)(vars Data,int TimePeriod);
C var F(ROCP)(vars Data,int TimePeriod);
C var F(ROCR)(vars Data,int TimePeriod);
C var F(ROCL)(vars Data,int TimePeriod);
C var F(ROCR100)(vars Data,int TimePeriod);
C var F(RSI)(vars Data,int TimePeriod);
C var F(SMA)(vars Data,int TimePeriod);
C var F(StdDev)(vars Data,int TimePeriod);
C var F0(Stoch)(int FastK_Period,int SlowK_Period,int SlowK_MAType,int SlowD_Period,int SlowD_MAType);
C var F1(Stoch)(vars Open,vars High,vars Low,vars Close,int FastK_Period,int SlowK_Period,int SlowK_MAType,int SlowD_Period,int SlowD_MAType);
C var F(StochF)(int FastK_Period,int FastD_Period,int FastD_MAType);
C var F(StochRSI)(vars Data,int TimePeriod,int FastK_Period,int FastD_Period,int FastD_MAType);
C var F(Sum)(vars Data,int TimePeriod);
C var F(T3)(vars Data,int TimePeriod,var VFactor);
C var F(TEMA)(vars Data,int TimePeriod);
C var F(TrueRange)();
C var F(Trima)(vars Data,int TimePeriod);
C var F(Trix)(vars Data,int TimePeriod);
C var F(TSF)(vars Data,int TimePeriod);
C var F(TypPrice)();
C var F(UltOsc)(int TimePeriod1,int TimePeriod2,int TimePeriod3);
C var F(Variance)(vars Data,int TimePeriod);
C var F(WCLPrice)();
C var F(WillR)(int TimePeriod);
C var F(WMA)(vars Data,int TimePeriod);
// TA_LIB CDL
C int F(CDL2Crows)();
C int F(CDL3BlackCrows)();
C int F(CDL3Inside)();
C int F(CDL3LineStrike)();
C int F(CDL3Outside)();
C int F(CDL3StarsInSouth)();
C int F(CDL3WhiteSoldiers)();
C int F(CDLAbandonedBaby)(var Penetration);
C int F(CDLAdvanceBlock)();
C int F(CDLBeltHold)();
C int F(CDLBreakaway)();
C int F(CDLClosingMarubozu)();
C int F(CDLConcealBabysWall)();
C int F(CDLCounterAttack)();
C int F(CDLDarkCloudCover)(var Penetration);
C int F(CDLDoji)();
C int F(CDLDojiStar)();
C int F(CDLDragonflyDoji)();
C int F(CDLEngulfing)();
C int F(CDLEveningDojiStar)(var Penetration);
C int F(CDLEveningStar)(var Penetration);
C int F(CDLGapSideSideWhite)();
C int F(CDLGravestoneDoji)();
C int F(CDLHammer)();
C int F(CDLHangingMan)();
C int F(CDLHarami)();
C int F(CDLHaramiCross)();
C int F(CDLHignWave)();
C int F(CDLHikkake)();
C int F(CDLHikkakeMod)();
C int F(CDLHomingPigeon)();
C int F(CDLIdentical3Crows)();
C int F(CDLInNeck)();
C int F(CDLInvertedHammer)();
C int F(CDLKicking)();
C int F(CDLKickingByLength)();
C int F(CDLLadderBottom)();
C int F(CDLLongLeggedDoji)();
C int F(CDLLongLine)();
C int F(CDLMarubozu)();
C int F(CDLMatchingLow)();
C int F(CDLMatHold)(var Penetration);
C int F(CDLMorningDojiStar)(var Penetration);
C int F(CDLMorningStar)(var Penetration);
C int F(CDLOnNeck)();
C int F(CDLPiercing)();
C int F(CDLRickshawMan)();
C int F(CDLRiseFall3Methods)();
C int F(CDLSeperatingLines)();
C int F(CDLShootingStar)();
C int F(CDLShortLine)();
C int F(CDLSpinningTop)();
C int F(CDLStalledPattern)();
C int F(CDLStickSandwhich)();
C int F(CDLTakuri)();
C int F(CDLTasukiGap)();
C int F(CDLThrusting)();
C int F(CDLTristar)();
C int F(CDLUnique3River)();
C int F(CDLUpsideGap2Crows)();
C int F(CDLXSideGap3Methods)();
// indicators.c
C var F(AC)(vars Data);
C var F(ADO)();
C var F0(AGC)(vars Data, var alpha);
C var F1(AGC)(vars Data, int Period);
C var F0(ALMA)(vars Data, int TimePeriod, int sigma, var offset);
C var F1(ALMA)(vars Data, int TimePeriod);
C var F(AO)(vars Data);
C var F(ATRS)(int Period);
C var F(Alligator)(vars Data);
C var F(BBOsc)(vars Data,int Period,var NbDev,int MAType);
C var F(Butterworth)(vars Data,int Cutoff);
C var F(CGOsc)(vars Data,int Period);
C var F(CI)(int TimePeriod);
C var F(ChandelierLong)(int TimePeriod,var Multipl);
C var F(ChandelierShort)(int TimePeriod,var Multipl);
C var F(Chikou)(int Shift);
C var F(Coral)(vars Data);
C var F(DCOsc)(vars Data,int Period);
C var F(DChannel)(int Period);
C var F(DPO)(vars Data, int TimePeriod);
C var F(Decycle)(vars Data,int Period);
C var F(FIR3)(vars Data);
C var F(FIR4)(vars Data);
C var F(FIR6)(vars Data);
C var F(Fisher)(vars Data);
C var F(FisherInv)(vars Data);
C var F(FisherN)(vars Data,int Period);
C var F(FractalDimension)(vars Data,int Period);
C var F(FractalHigh)(vars Data,int Period);
C var F(FractalLow)(vars Data,int Period);
C var F(HAClose)();
C var F(HAHigh)();
C var F(HALow)();
C var F(HAOpen)();
C var F(HH)(int Period,int Offset);
C var F(HMA)(vars Data,int Period);
C var F(HighPass2)(vars Data,int CutoffPeriod); 
C var F(Hurst)(vars Data,int Period);
C var F(IBS)();
C var F(Ichimoku)(int PeriodTenkan,int PeriodKijun,int PeriodSenkou,int Offset);
C var F(Keltner)(vars Data, int TimePeriod, var Factor);
C var F(LL)(int Period,int Offset); 
C var F(Laguerre)(vars Data, var alpha);
C var F(MMI)(vars Data,int TimePeriod);
C var F(Moment)(vars Data,int Period,int n);
C var F(Normalize)(vars Data,int Period);
C int F(NumInRange)(vars Low,vars High,var vMin,var vMax,int Period);
C int F(NumRiseFall)(vars Data,int Period);
C int F(NumWhiteBlack)(var vBody,int Offset,int Period);
C var F(ProfitFactor)(vars Data,int Length);
C var F(RVI)(int Period);
C var F(Roof)(vars Data,int CutOffLow,int CutOffHigh);
C var F(SAR)(var AFstep,var AFmin,var AFmax);
C var F(SIROC)(vars Data, int TimePeriod, int EMAPeriod); 
C var F(SMom)(vars Data,int Period,int Cutoff);
C var F(ShannonEntropy)(vars Data,int Length,int PatternSize);
C var F(ShannonGain)(vars Data,int Period);
C var F(Smooth)(vars Data,int Cutoff);
C var F(Spearman)(vars Data,int Period);
C var F(StochEhlers)(vars Data,int TimePeriod,int CutOffLow,int CutOffHigh);
C var F(TSI)(vars Data,int Period);
C var F(UO)(vars Data,int Cutoff);
C var F(Volatility)(vars Data,int Period);
C var F(VolatilityC)(int TimePeriod,int EMAPeriod);
C var F(VolatilityMM)(vars Data,int TimePeriod,int EMAPeriod);
C var F(ZMA)(vars Data,int Period);
C var F(ZigZag)(vars Data,var Depth,int Length,long Color);
 
C var F(ccyStrength)(char* Currency);
C void F(ccySet)(var Strength);
C void F(ccyReset)();
C char* F(ccyMin)();
C char* F(ccyMax)();
C var F(dayClose)(int zone,int day);
C var F(dayHigh)(int zone,int day);
C var F(dayLow)(int zone,int day);
C var F(dayOpen)(int zone,int day);
C var F(dayPivot)(int zone,int day);
C var F(genNoise)();
C var F(genSine)(var Period1, var Period2);
C var F(genSquare)(var Period1, var Period2);
C var F(move)(vars Data,int Length,int MovePeriod,var Percent);
C var F(season)(vars Data,int TimePeriod,int Horizon,int Mode);

// new functions at the end
C int F(stridx)(const char* Name);
C char* F(strxid)(int Index);
C int F1(dataParse)(int Handle,const char* Format,const char* FileName,int Start,int Num);
C int F2(dataParse)(int Handle,const char* Format,const char* FileName,const char* Filter);

#undef F
#undef F0
#undef F1
#undef F2
#undef F3
#undef C
#endif
