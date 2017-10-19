///////////////////////////////////////////////////////
// Header for DLL-based Zorro strategies
///////////////////////////////////////////////////////
#pragma once

#include "zorro/zorro_common.h"
#include "zorro/functions_cpp.h"

///////////////////////////////////////////////////////
// Declare variables
#include "zorro/var.h"
#define ZORRO_BUILD_VARIABLE(type, name, link) \
	ZORRO_BUILD_VARIABLE_TYPE(type, name, link) \
	extern CVariable<S##name##Variable>& name;
#define ZORRO_BUILD_EXPRESSION(type, name, link) \
	ZORRO_BUILD_EXPRESSION_TYPE(type, name, link) \
	extern CExpression<S##name##Expression>& name;
#include "zorro/variables_cpp.h"

#undef ZORRO_BUILD_VARIABLE_TYPE
#undef ZORRO_BUILD_EXPRESSION_TYPE
