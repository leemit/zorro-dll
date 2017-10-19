
#pragma once

ZORRO_NAMESPACE_OPEN

///////////////////////////////////////////////////////
// Declare function pointers
#define F(x) (*x)
#define F0(x) (*x##0)
#define F1(x) (*x##1)
#define F2(x) (*x##2)
#define F3(x) (*x##3)
#ifdef ZORRO_IMPL
#define C
#else
#define C extern
#endif
#include "litec/functions.h"

///////////////////////////////////////////////////////
// convenience definitions for overloaded functions
inline TRADE* enterLong(int lots=0,var entry=0, var stop=0, var takeprofit=0, var trail=0, var trailslope=0, var traillock=0, var trailstep=0)
{ return enterLong0(lots,entry,stop,takeprofit,trail,trailslope,traillock,trailstep,0); }
inline TRADE* enterShort(int lots=0,var entry=0, var stop=0, var takeprofit=0, var trail=0, var trailslope=0, var traillock=0, var trailstep=0)
{ return enterShort0(lots,entry,stop,takeprofit,trail,trailslope,traillock,trailstep,0); }
template <typename FUNCTION> 
inline TRADE* enterLong(FUNCTION f=0,var v0=0,var v1=0,var v2=0,var v3=0,var v4=0,var v5=0,var v6=0,var v7=0)
{ return enterLong0(reinterpret_cast<DWORD>(f),v0,v1,v2,v3,v4,v5,v6,v7); }
template <typename FUNCTION> 
inline TRADE* enterShort(FUNCTION f=0,var v0=0,var v1=0,var v2=0,var v3=0,var v4=0,var v5=0,var v6=0,var v7=0)
{ return enterShort0(reinterpret_cast<DWORD>(f),v0,v1,v2,v3,v4,v5,v6,v7); }
inline void exitLong(string Name=0,var Limit=0,int nLots=0)
{ exitLong0(Name,Limit,nLots); }
inline void exitShort(string Name=0,var Limit=0,int nLots=0)
{ exitShort0(Name,Limit,nLots); }
inline int exitTrade(TRADE* tr,var Limit=0,int nLots=0)
{ exitTrade0(tr,Limit,nLots); }
inline char* loop(void* p0=0,void* p1=0,void* p2=0,void* p3=0,void* p4=0,void* p5=0,void* p6=0,void* p7=0,void* p8=0,void* p9=0,void* p10=0,void* p11=0,void* p12=0,void* p13=0,void* p14=0,void* p15=0,void* p16=0,void* p17=0,void* p18=0,void* p19=0,
	void* p20=0,void* p21=0,void* p22=0,void* p23=0,void* p24=0,void* p25=0,void* p26=0,void* p27=0,void* p28=0,void* p29=0,void* p30=0,void* p31=0,void* p32=0,void* p33=0,void* p34=0,void* p35=0,void* p36=0,void* p37=0,void* p38=0,void* p39=0)
{ return loop0(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,
	p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,p37,p38,p39); }
inline var adviseLong(int Method=0,var Objective=0,var v0=NIL,var v1=NIL,var v2=NIL,var v3=NIL,var v4=NIL,var v5=NIL,var v6=NIL,var v7=NIL,var v8=NIL,var v9=NIL,var v10=NIL,var v11=NIL,var v12=NIL,var v13=NIL,var v14=NIL,var v15=NIL,var v16=NIL,var v17=NIL,var v18=NIL,var v19=NIL)
{ return adviseLong0(Method,Objective,v0,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16,v17,v18,v19); }
inline var adviseLong(int Method,var Objective,var *Signals,long NumSignals)
{ return adviseLong1(Method,Objective,Signals,NumSignals); }
inline var adviseShort(int Method=0,var Objective=0,var v0=NIL,var v1=NIL,var v2=NIL,var v3=NIL,var v4=NIL,var v5=NIL,var v6=NIL,var v7=NIL,var v8=NIL,var v9=NIL,var v10=NIL,var v11=NIL,var v12=NIL,var v13=NIL,var v14=NIL,var v15=NIL,var v16=NIL,var v17=NIL,var v18=NIL,var v19=NIL)
{ return adviseShort0(Method,Objective,v0,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16,v17,v18,v19); }
inline var adviseShort(int Method,var Objective,var *Signals,long NumSignals)
{ return adviseShort1(Method,Objective,Signals,NumSignals); }
inline int dataParse(int Handle,const char* Format,const char* FileName)
{ return dataParse1(Handle,Format,FileName,0,0); }
inline int dataParse(int Handle,const char* Format,const char* FileName,int Start=0,int Num=0)
{ return dataParse1(Handle,Format,FileName,Start,Num); }

inline var slider(int N,int Pos=0,int Lower=0,int Upper=0,char* Name=0,char* Tooltip=0)
{ return slider0(N,Pos,Lower,Upper,Name,Tooltip); }
inline vars series(var val=0,int size=0) { return series0(val,size); }
inline int is(long Flag) { return is0(Flag); }
inline int is(long Mode, long Flag) { return is1(Mode,Flag); }
inline void set(long Flag) { return set0(Flag); }
inline void set(long* Mode, long Flag) { return set1(Mode,Flag); }
inline void reset(long Flag) { return reset0(Flag); }
inline void reset(long* Mode, long Flag) { return reset1(Mode,Flag); }
inline BOOL crossOver(vars a,var b) { return crossOver1(a,b); }
inline BOOL crossUnder(vars a,var b) { return crossUnder1(a,b); }
inline CONTRACT* contract(int Type,int Days,var Strike) { return contract0(Type,Days,Strike); }
inline CONTRACT* contract(CONTRACT* c) { return contract1(c); }
inline CONTRACT* contract(TRADE* tr) { return contract2(tr); }
inline CONTRACT* contract(int N) { return contract3(N); }
inline string strdate(string format,int offset) { return strdate0(format,offset); }
inline string strdate(string format,var date) { return strdate1(format,date); }
inline long file_append(string name,string content) { return file_append0(name,content); }
inline long file_append(string name,void* content,long size) { return file_append1(name,content,size); }
inline void dataSet(int Handle,int Row,int Col,var Value) { dataSet0(Handle,Row,Col,Value); }
inline void dataSet(int Handle,int Row,int Col,int Value) { dataSet1(Handle,Row,Col,Value); }
inline var random() { return random0(); }
inline var random(var limit) { return random1(limit); }
inline var sign(var a) { return sign0(a); }
inline int sign(int a) { return sign1(a); }
inline var ifelse(BOOL c,var a,var b) { return ifelse0(c,a,b); }
inline int ifelse(BOOL c,int a,int b) { return ifelse1(c,a,b); }
inline string ifelse(BOOL c,string a,string b) { return ifelse2(c,a,b); }
inline var clamp(var a,var l,var h) { return clamp0(a,l,h); }
inline var clamp(int a,int l,int h) { return clamp1(a,l,h); }
inline BOOL between(var a,var l,var h) { return between0(a,l,h); }
inline BOOL between(int a,int l,int h) { return between1(a,l,h); }
inline mat matSet(mat M,mat A) { return matSet0(M,A); }
inline mat matSet(mat M,int row,int col,mat A) { return matSet1(M,row,col,A); }
inline mat matSet(mat M,var c) { return matSet2(M,c); }
inline var markowitz(var* CovMatrix,var* Means,int N,var* Caps) { return markowitz0(CovMatrix,Means,N,Caps); }
inline var markowitz(var* CovMatrix,var* Means,int N,var Cap) { return markowitz1(CovMatrix,Means,N,Cap); }
inline var LowPass(vars Data,int Cutoff) { return LowPass0(Data,Cutoff); }
inline var LowPass(var* Buffer,var Val,int Cutoff) { return LowPass(Buffer,Val,Cutoff); }
inline var ATR(int TimePeriod) { return ATR0(TimePeriod); }
inline var ATR(vars Open,vars High,vars Low,vars Close,int TimePeriod) { return ATR1(Open,High,Low,Close,TimePeriod); }
inline var MinusDI(int TimePeriod) { return MinusDI0(TimePeriod); }
inline var MinusDI(vars Open,vars High,vars Low,vars Close,int TimePeriod) { return MinusDI1(Open,High,Low,Close,TimePeriod); }
inline var MinusDM(int TimePeriod) { return MinusDM0(TimePeriod); }
inline var MinusDM(vars Open,vars High,vars Low,vars Close,int TimePeriod) { return MinusDM1(Open,High,Low,Close,TimePeriod); }
inline var PlusDI(int TimePeriod) { return PlusDI0(TimePeriod); }
inline var PlusDI(vars Open,vars High,vars Low,vars Close,int TimePeriod) { return PlusDI1(Open,High,Low,Close,TimePeriod); }
inline var PlusDM(int TimePeriod) { return PlusDM0(TimePeriod); }
inline var PlusDM(vars Open,vars High,vars Low,vars Close,int TimePeriod) { return PlusDM1(Open,High,Low,Close,TimePeriod); }
inline var EMA(vars Data,int TimePeriod) { return  EMA0(Data,TimePeriod); }
inline var EMA(vars Data,var alpha) { return EMA1(Data,alpha); }
inline var Stoch(int FastK_Period,int SlowK_Period,int SlowK_MAType,int SlowD_Period,int SlowD_MAType) 
{ return Stoch0(FastK_Period,SlowK_Period,SlowK_MAType,SlowD_Period,SlowD_MAType); }
inline var Stoch(vars Open,vars High,vars Low,vars Close,int FastK_Period,int SlowK_Period,int SlowK_MAType,int SlowD_Period,int SlowD_MAType) 
{ return Stoch1(Open,High,Low,Close,FastK_Period,SlowK_Period,SlowK_MAType,SlowD_Period,SlowD_MAType); }
inline var AGC(vars Data, var alpha) { return AGC0(Data,alpha); }
inline var AGC(vars Data, int Period) { return AGC1(Data,Period); }
inline var ALMA(vars Data, int TimePeriod, int sigma, var offset) { return ALMA0(Data,TimePeriod,sigma,offset); }
inline var ALMA(vars Data, int TimePeriod) { return ALMA1(Data,TimePeriod); }

ZORRO_NAMESPACE_CLOSE
