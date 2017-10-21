
#ifndef trading_types_h
#define trading_types_h

// convenience definitions C/C++ -> lite-C
typedef double      var;
typedef var*        vars;
typedef const var*  cvars;
typedef const char* string;
typedef long        function;
typedef DWORD       zcolor;
#ifdef ZORRO_CPP
typedef const wchar_t* wstring;
#else
typedef const short* wstring;
#endif

#endif // trading_types_h
