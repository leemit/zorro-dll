
#pragma once

#include "zorro/var.h"

#define long_trades     forTrade(4); g->bFor; forTrade(5) // asset/algo trades only
#define short_trades    forTrade(12); g->bFor; forTrade(13) // asset/algo trades only
#define current_trades  forTrade(20); g->bFor; forTrade(21) // asset/algo trades only
#define open_trades     forTrade(0); g->bFor; forTrade(1) // open trades only
#define all_trades      forTrade(2); g->bFor; forTrade(3) // all trades

#define ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
struct S##name##Variable : ::z::SVariableBaseDef<type> { \
	inline type& get() const { return (link); } \
	inline void set(const type& value) { (link) = value; } \
};
#define ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
struct S##name##Expression : ::z::SVariableBaseDef<type> { \
	inline type get() const { return (link); } \
};

#ifdef ZORRO_IMPL
#define ZORRO_BUILD_VARIABLE(type, name, link) \
	ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
	::z::CVariable<S##name##Variable>& name = ::z::CVariable<S##name##Variable>::getInstance();
#define ZORRO_BUILD_EXPRESSION(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	::z::CExpression<S##name##Expression>& name = ::z::CExpression<S##name##Expression>::getInstance();
#define ZORRO_BUILD_VARPOINTER(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	::z::CVarPointer<S##name##Expression>& name = ::z::CVarPointer<S##name##Expression>::getInstance();
#else
#define ZORRO_BUILD_VARIABLE(type, name, link) \
	ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
	extern ::z::CVariable<S##name##Variable>& name;
#define ZORRO_BUILD_EXPRESSION(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	extern ::z::CExpression<S##name##Expression>& name;
#define ZORRO_BUILD_VARPOINTER(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	extern ::z::CVarPointer<S##name##Expression>& name;
#endif

inline bool TradeFlag(ETradeFlag flag) { return ((g->tr->flags & flag) != 0); }
inline bool TradeIs  (ETradeFlag flag) { return ((g->tr->flags & flag) == flag); }

#include "variables_list.h"

#if defined ZORRO_IMPL && defined _DEBUG
void ZorroForceCompileVariableMethods()
{
	// This piece just forces the compiler to not optimize away the variable get method,
	// which is needed to inspect the variable if we want to see it in a debugger's watch
#define ZORRO_BUILD_VARIABLE(type, name, link) name.get();
#define ZORRO_BUILD_EXPRESSION(type, name, link) name.get();
#define ZORRO_BUILD_VARPOINTER(type, name, link) name.get();
#include "zorro/variables_list.h"
}
#endif

#undef ZORRO_BUILD_VARIABLE_TYPE
#undef ZORRO_BUILD_EXPRESSION_TYPE
