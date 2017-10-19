
#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <wtypes.h>
#include <stdio.h>
#include <math.h>

#define ZORRO_CALL __cdecl
#define ZORRO_EXPORT extern "C" __declspec(dllexport)

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
#define ZORRO_CPP 11
#elif __cplusplus >= 199711L || _MSVC_LANG >= 199711L
#define ZORRO_CPP 03
#endif

#ifdef ZORRO_NAMESPACE
#define ZORRO_NAMESPACE_OPEN namespace ZORRO_NAMESPACE {
#define ZORRO_NAMESPACE_CLOSE };
#else
#define ZORRO_NAMESPACE
#define ZORRO_NAMESPACE_OPEN
#define ZORRO_NAMESPACE_CLOSE
#endif

#pragma pack(push, 4)

#ifdef ZORRO_CPP
#include "trading_cpp.h"
#else
#include "litec/trading.h"
#endif

#pragma pack(pop)

#ifdef ZORRO_IMPL
ZORRO_NAMESPACE::GLOBALS* g;
#else
extern ZORRO_NAMESPACE::GLOBALS* g;
#endif

#include "functions_cpp.h"

#ifdef ZORRO_CPP
#include "variables_cpp.h"
#else
#include "litec/variables.h"
#endif
