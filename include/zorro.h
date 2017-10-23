///////////////////////////////////////////////////////
// Header for DLL-based Zorro strategies
///////////////////////////////////////////////////////
#pragma once

#include "zorro/zorro_common.h"

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <wtypes.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>

#pragma pack(push, 4)

#ifdef ZORRO_CPP_PURE
#include "zorro/trading_cpp.h"
#else
#include "zorro/litec/trading.h"
#endif

#pragma pack(pop)

ZORRO_NAMESPACE_OPEN
#ifdef ZORRO_IMPL
GLOBALS* g;
#else
extern GLOBALS* g;
#endif
ZORRO_NAMESPACE_CLOSE

#include "zorro/functions_cpp.h"

#ifdef ZORRO_CPP_PURE
#include "zorro/variables_cpp.h"
#else
#include "zorro/litec/variables.h"
#endif

ZORRO_NAMESPACE_OPEN
#include "zorro/litec/default.h"
ZORRO_NAMESPACE_CLOSE
