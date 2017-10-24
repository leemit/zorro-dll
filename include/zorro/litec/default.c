/////////////////////////////////////////////////////////////////////
// Default trading headers and functions
// (c) oP group 2012
/////////////////////////////////////////////////////////////////////
#ifndef default_c
#define default_c

#define PRAGMA_ZERO	// initialize local variables to zero
#define PRAGMA_POINTER // no pointer autodetection

#include <litec.h>	// common language header
#include <trading.h> // trading-specific structs
#include <variables.h> // trading variable re-definitions
#include <functions.h> // trading and technical analysis functions

extern GLOBALS* g; // global variables struct

/////////////////////////////////////////////////////////////////////
//dummy function to preset external structs for CS_GetVar() and sizeof()
void lcStructs()
{
	RECT* r = 0; r->left = 0;
	TICK* t = 0; t->time = 0;
	T1* t1 = 0; t1->time = 0;
	T2* t2 = 0; t2->time = 0;
	T6* t6 = 0; t6->time = 0;
	THL* thl = 0; thl->time = 0;
	BAR* b = 0; b->time_base = 0;
	DATA* d = 0; d->Data = 0;
	DATASET* ds = 0; ds->fData = 0;
	MATRIX* m = 0; m->dat = 0;
	CONTRACT* c = 0; c->time = 0;
}

// lite-C internal functions
int compareStrings(char* p1,char* p2);
void paraNumber(long type,long num);

// overloaded functions
var abs(var a);
int abs(int a);
var max(var a,var b);
int max(int a,int b);
var min(var a,var b);
int min(int a,int b);
void watch(string text,...);

#include <default.h>

var objective()
{
	return objectivePRR();
}

#endif // default_c
