///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////

#define ZORRO_DLLMAIN                 // defines a dll entry point for this strategy
#define ZORRO_NAMESPACE YourNamespace // wraps all zorro symbols in the given namespace
#define ZORRO_EXPECT_ALL_FUNCTIONS    // asserts at runtime if the strategy is not using all functions from zorro
#define ZORRO_FORCE_LITEC             // forces the lite-c preprocessor defines instead of c++ variables/enums
#include "zorro_impl.h"

using namespace YourNamespace;

ZORRO_EXPORT void ZORRO_CALL run()
{
	if (is(INITRUN))
	{
		// your zorro code ...
	}
}
