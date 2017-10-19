
#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>
#include <wtypes.h>
#include <stdio.h>
#include <math.h>

#define ZORRO_CALL __cdecl
#define ZORRO_EXPORT extern "C" __declspec(dllexport)
#define ZORRO_NAMESPACE z

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
#define ZORRO_CPP 11
#elif __cplusplus >= 199711L || _MSVC_LANG >= 199711L
#define ZORRO_CPP 03
#endif

// Zorro specific header files
#pragma pack(push, 4)

#ifdef ZORRO_CPP
#include "trading_cpp.h"
#else
#include "trading.h"
#endif

#pragma pack(pop)

#ifdef ZORRO_IMPL
GLOBALS* g;
#else
extern GLOBALS* g;
#endif

#define ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
struct S##name##Variable : SVariableBaseDef<type> { \
	inline type& get() const { return (link); } \
	inline void set(const type& value) { (link) = value; } \
};

#define ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
struct S##name##Expression : SVariableBaseDef<type> { \
	inline TType get() const { return (link); } \
};
