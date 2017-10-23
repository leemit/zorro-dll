///////////////////////////////////////////////////////
// Header for DLL-based Zorro strategies
///////////////////////////////////////////////////////
#pragma once

#include "zorro/zorro_common.h"

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
