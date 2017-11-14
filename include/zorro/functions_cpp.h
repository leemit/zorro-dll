
#ifndef ZORRO_FUNCTIONS_CPP_H_
#define ZORRO_FUNCTIONS_CPP_H_

#include <stdarg.h>

///////////////////////////////////////////////////////
// Declare or define function pointers
#define F(x)  (ZORRO_CALL* x)
#define F0(x) (ZORRO_CALL* x##0)
#define F1(x) (ZORRO_CALL* x##1)
#define F2(x) (ZORRO_CALL* x##2)
#define F3(x) (ZORRO_CALL* x##3)
#define R(x) x
#define A(x) x
#define I(param,value) param
#define VA ,...
#ifdef ZORRO_IMPL
#define C
#define D(x) = 0;
#else
#define C extern
#define D(x) ;
#endif
ZORRO_NAMESPACE_OPEN
#include "litec/functions_list.h"
ZORRO_NAMESPACE_CLOSE


#ifdef ZORRO_CPP
///////////////////////////////////////////////////////
// Define inline functions to wrap the function pointers

#define F(x) x
#define F0(x) x
#define F1(x) x
#define F2(x) x
#define F3(x) x
#define C inline
#define R(x) x
#define A(x) x
#define D(x) x
#define DF(x)  ZORRO_NAMESPACE x
#define DF0(x) ZORRO_NAMESPACE x##0
#define DF1(x) ZORRO_NAMESPACE x##1
#define DF2(x) ZORRO_NAMESPACE x##2
#define DF3(x) ZORRO_NAMESPACE x##3
#define I(param,value) param=value
#define VA
#include "litec/functions_list.h"

///////////////////////////////////////////////////////
// Special function overloads

template <typename FUNCTION> 
inline TRADE* enterLong(FUNCTION f=0,var v0=0,var v1=0,var v2=0,var v3=0,var v4=0,var v5=0,var v6=0,var v7=0) {
	return ZORRO_NAMESPACE enterLong0(reinterpret_cast<int>(f),v0,v1,v2,v3,v4,v5,v6,v7);
}
template <typename FUNCTION> 
inline TRADE* enterShort(FUNCTION f=0,var v0=0,var v1=0,var v2=0,var v3=0,var v4=0,var v5=0,var v6=0,var v7=0) {
	return ZORRO_NAMESPACE enterShort0(reinterpret_cast<int>(f),v0,v1,v2,v3,v4,v5,v6,v7);
}
template <> 
inline TRADE* enterLong(long f,var v0,var v1,var v2,var v3,var v4,var v5,var v6,var v7) {
	return ZORRO_NAMESPACE enterLong0(static_cast<int>(f),v0,v1,v2,v3,v4,v5,v6,v7);
}
template <> 
inline TRADE* enterShort(long f,var v0,var v1,var v2,var v3,var v4,var v5,var v6,var v7) {
	return ZORRO_NAMESPACE enterShort0(static_cast<int>(f),v0,v1,v2,v3,v4,v5,v6,v7);
}

inline var brokerCommand(EBrokerCmd command, int parameter) {
	return ZORRO_NAMESPACE brokerCommand(command, static_cast<DWORD>(parameter));
}
inline var brokerCommand(EBrokerCmd command, string text) {
	return ZORRO_NAMESPACE brokerCommand(command, reinterpret_cast<DWORD>(text));
}
inline var brokerCommand(EBrokerCmd command, cvars parameters) {
	return ZORRO_NAMESPACE brokerCommand(command, reinterpret_cast<DWORD>(parameters));
}

#ifdef ZORRO_CPP_PURE

inline int is(ETrainFlag* mode,int flag) {
	return ZORRO_NAMESPACE is1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(ETrainFlag)*>(mode),flag);
}
inline int is(ETradeFlag* mode,int flag) {
	return ZORRO_NAMESPACE is1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(ETradeFlag)*>(mode),flag);
}
inline int is(EPlotMode* mode,int flag) {
	return ZORRO_NAMESPACE is1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(EPlotMode)*>(mode),flag);
}
inline void set(ETrainFlag* mode,int flag) {
	ZORRO_NAMESPACE set1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(ETrainFlag)*>(mode),flag);
}
inline void set(ETradeFlag* mode,int flag) {
	ZORRO_NAMESPACE set1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(ETradeFlag)*>(mode),flag);
}
inline void set(EPlotMode* mode,int flag) {
	ZORRO_NAMESPACE set1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(EPlotMode)*>(mode),flag);
}
inline void reset(ETrainFlag* mode,int flag) {
	ZORRO_NAMESPACE reset1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(ETrainFlag)*>(mode),flag);
}
inline void reset(ETradeFlag* mode,int flag) {
	ZORRO_NAMESPACE reset1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(ETradeFlag)*>(mode),flag);
}
inline void reset(EPlotMode* mode,int flag) {
	ZORRO_NAMESPACE reset1(reinterpret_cast<ZORRO_ENUM_UNDERLYING_TYPE(EPlotMode)*>(mode),flag);
}
#endif // ZORRO_CPP_PURE
#endif // ZORRO_CPP

#endif // ZORRO_FUNCTIONS_CPP_H_
