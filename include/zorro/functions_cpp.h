
#pragma once

#include <stdarg.h>

ZORRO_NAMESPACE_OPEN

///////////////////////////////////////////////////////
// Declare function pointers
#define F(x)  (ZORRO_CALL* x##_ptr)
#define F0(x) (ZORRO_CALL* x##0_ptr)
#define F1(x) (ZORRO_CALL* x##1_ptr)
#define F2(x) (ZORRO_CALL* x##2_ptr)
#define F3(x) (ZORRO_CALL* x##3_ptr)
#define R(x) x
#define A(x) x
#define D(x)
#define I(x)
#define VA ,...
#ifdef ZORRO_IMPL
#define C
#else
#define C extern
#endif
#include "litec/functions_list.h"

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
#define DF(x)  x##_ptr
#define DF0(x) x##0_ptr
#define DF1(x) x##1_ptr
#define DF2(x) x##2_ptr
#define DF3(x) x##3_ptr
#define I(x) =x
#define VA
#include "litec/functions_list.h"

template <typename FUNCTION> 
inline TRADE* enterLong(FUNCTION f=0,var v0=0,var v1=0,var v2=0,var v3=0,var v4=0,var v5=0,var v6=0,var v7=0) {
	return enterLong0_ptr(reinterpret_cast<function>(f),v0,v1,v2,v3,v4,v5,v6,v7);
}
template <typename FUNCTION> 
inline TRADE* enterShort(FUNCTION f=0,var v0=0,var v1=0,var v2=0,var v3=0,var v4=0,var v5=0,var v6=0,var v7=0) {
	return enterShort0_ptr(reinterpret_cast<function>(f),v0,v1,v2,v3,v4,v5,v6,v7);
}

ZORRO_NAMESPACE_CLOSE
