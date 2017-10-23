/////////////////////////////////////////////////////////////////////
// Trading functions
// (c) oP group 2017
/////////////////////////////////////////////////////////////////////
#ifndef functions_h
#define functions_h

#define F(x) x
#define F0(x) x
#define F1(x) x
#define F2(x) x
#define F3(x) x
#define C
#define R(x) x
#define A(x) x
#define D(x) ;
#define I(param,value) param
#define VA ,...

#ifdef ZORRO_CPP
#include "functions_list.h"
#else
#include <functions_list.h>
#endif

#endif // functions_h
