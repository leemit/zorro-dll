
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
#define ZORRO_NAMESPACE z::
#define ZORRO_NAMESPACE_OPEN namespace z {
#define ZORRO_NAMESPACE_CLOSE }
#else
#define ZORRO_EXPORT __declspec(dllexport)
#define ZORRO_NAMESPACE
#define ZORRO_NAMESPACE_OPEN
#define ZORRO_NAMESPACE_CLOSE
#endif // ZORRO_CPP

#ifdef ZORRO_CPP
#define ZORRO_DEFINE_GLOBAL_A(type, name, args) \
namespace z { \
namespace global { \
template <class> struct name { \
	static type instance; \
}; \
template <> \
type name<void>::instance args; \
}} \
static type& name = z::global::name<void>::instance;

#define ZORRO_DEFINE_GLOBAL(type, name) \
        ZORRO_DEFINE_GLOBAL_A(type, name, )
#else
#ifdef ZORRO_IMPL
#define ZORRO_DEFINE_GLOBAL(type, name)         type name;
#define ZORRO_DEFINE_GLOBAL_A(type, name, args) type name args;
#else
#define ZORRO_DEFINE_GLOBAL(type, name)         extern type name;
#define ZORRO_DEFINE_GLOBAL_A(type, name, args) extern type name;
#endif // ZORRO_IMPL
#endif // ZORRO_CPP

#endif // ZORRO_COMMON_H_
