
#ifndef ZORRO_COMMON_H_
#define ZORRO_COMMON_H_

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
#define ZORRO_CPP 11
#elif __cplusplus >= 199711L || _MSVC_LANG >= 199711L
#define ZORRO_CPP 03
#endif

#if defined(ZORRO_CPP) && !defined(ZORRO_FORCE_LITEC)
#define ZORRO_CPP_PURE
#endif

#define ZORRO_CALL __cdecl

#ifdef ZORRO_CPP
#define ZORRO_EXPORT extern "C" __declspec(dllexport)
#define ZORRO_NAMESPACE zptr::
#define ZORRO_NAMESPACE_OPEN namespace zptr {
#define ZORRO_NAMESPACE_CLOSE }
#else
#define ZORRO_EXPORT __declspec(dllexport)
#define ZORRO_NAMESPACE
#define ZORRO_NAMESPACE_OPEN
#define ZORRO_NAMESPACE_CLOSE
#endif

#endif // ZORRO_COMMON_H_
