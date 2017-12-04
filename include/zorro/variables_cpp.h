
#ifndef ZORRO_VARIABLES_CPP_H_
#define ZORRO_VARIABLES_CPP_H_

#include "zorro/var.h"

#define long_trades     forTrade(4); g->bFor; forTrade(5) // asset/algo trades only
#define short_trades    forTrade(12); g->bFor; forTrade(13) // asset/algo trades only
#define current_trades  forTrade(20); g->bFor; forTrade(21) // asset/algo trades only
#define open_trades     forTrade(0); g->bFor; forTrade(1) // open trades only
#define all_trades      forTrade(2); g->bFor; forTrade(3) // all trades

inline bool TradeFlag(ETradeFlag flag) { return ((g->tr->flags & flag) != 0); }
inline bool TradeIs  (ETradeFlag flag) { return ((g->tr->flags & flag) == flag); }

#define ZORRO_VARIABLE_TYPE(type, name, link) \
namespace z { \
struct S##name##Variable : SVariableBaseDef<type> { \
	inline type& get() const { return (link); } \
	inline void set(const type& value) { (link) = value; } \
}; \
}

#define ZORRO_EXPRESSION_TYPE(type, name, link) \
namespace z { \
struct S##name##Expression : SVariableBaseDef<type> { \
	inline type get() const { return (link); } \
}; \
}

#define ZORRO_VARIABLE(type, name, link) \
	ZORRO_VARIABLE_TYPE(type, name, link) \
	ZORRO_DEFINE_GLOBAL(::z::CVariable<::z::S##name##Variable>, name)

#define ZORRO_EXPRESSION(type, name, link) \
	ZORRO_EXPRESSION_TYPE(type, name, link) \
	ZORRO_DEFINE_GLOBAL(::z::CExpression<::z::S##name##Expression>, name)

#define ZORRO_VARPOINTER(type, name, link) \
	ZORRO_EXPRESSION_TYPE(type, name, link) \
	ZORRO_DEFINE_GLOBAL(::z::CVarPointer<::z::S##name##Expression>, name)

#include "variables_list.h"

#if defined ZORRO_IMPL && defined _DEBUG
namespace z {
void ForceCompileVariableMethods()
{
	// This piece just forces the compiler to not optimize away the variable get method,
	// which is needed to inspect the variable if we want to see it in a debugger's watch
#define ZORRO_VARIABLE(type, name, link) name.get();
#define ZORRO_EXPRESSION(type, name, link) name.get();
#define ZORRO_VARPOINTER(type, name, link) name.get();
#include "variables_list.h"
}
} // namespace z
#endif

#undef ZORRO_VARIABLE_TYPE
#undef ZORRO_EXPRESSION_TYPE

#endif // ZORRO_VARIABLES_CPP_H_
