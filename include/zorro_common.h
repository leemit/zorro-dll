
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

// Zorro specific header files
#pragma pack(push,4)
#include "trading.h"
#include "variables.h"
#pragma pack(pop)

#define ZORRO_CALL __cdecl
#define ZORRO_EXPORT extern "C" __declspec(dllexport)
