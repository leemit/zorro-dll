///////////////////////////////////////////////////////
// Common code for DLL-based Zorro strategies
// Include this file once in a cpp file
///////////////////////////////////////////////////////
#pragma once

#include "zorro/zorro_common.h"

GLOBALS* g;

////////////////////////////////////////////////////////
// Default DllMain

#ifdef ZORRO_DLLMAIN
BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
)
{
	(void)hinstDLL;
	(void)fdwReason;
	(void)lpvReserved;

	return TRUE;
}
#endif // ZORRO_DLL



////////////////////////////////////////////////////////
// Define function pointers
#define F(x) (*x)
#define F0(x) (*x##0)
#define F1(x) (*x##1)
#define F2(x) (*x##2)
#define F3(x) (*x##3)
#define C
#include "zorro/functions.h"

ZORRO_EXPORT int ZORRO_CALL zorro(GLOBALS* Globals)
{
	g = Globals;
	int N = 0;
// Populate the list of function pointers
#define F(x) (DWORD&)x = g->Functions[N++];
#define F0(x) (DWORD&)x##0 = g->Functions[N++];
#define F1(x) (DWORD&)x##1 = g->Functions[N++];
#define F2(x) (DWORD&)x##2 = g->Functions[N++];
#define F3(x) (DWORD&)x##3 = g->Functions[N++];
#include "zorro/func_list.h"

	return SCRIPT_VERSION;
}

////////////////////////////////////////////////////////
// Define variables

#include "zorro/var.h"

#define ZORRO_BUILD_VARIABLE(type, name, link) \
struct S##name##Variable : SVariableBaseDef<type> { \
	inline type& get() const { return (link); } \
	inline void set(const type& value) { (link) = value; } \
}; \
CVariable<S##name##Variable>& name = CVariable<S##name##Variable>::getInstance();

#define ZORRO_BUILD_EXPRESSION(type, name, link) \
struct S##name##Expression : SVariableBaseDef<type> { \
	inline TType get() const { return (link); } \
}; \
CExpression<S##name##Expression>& name = CExpression<S##name##Expression>::getInstance();

#include "zorro/variables_cpp.h"
