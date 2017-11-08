
#pragma once

#define ZORRO_CALL __cdecl
#define ZORRO_EXPORT extern "C" __declspec(dllexport)

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
#define ZORRO_CPP 11
#elif __cplusplus >= 199711L || _MSVC_LANG >= 199711L
#define ZORRO_CPP 03
#else
#error Zorro DLL works for C++ only
#endif

#if defined(ZORRO_CPP) && !defined(ZORRO_FORCE_LITEC)
#define ZORRO_CPP_PURE
#endif
