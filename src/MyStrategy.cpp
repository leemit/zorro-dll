///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////

#define ZORRO_DLLMAIN                 // defines a dll entry point for this strategy
#define ZORRO_NAMESPACE YourNamespace // wraps all zorro symbols in the given namespace
#define ZORRO_EXPECT_ALL_FUNCTIONS    // asserts at runtime if the strategy is not using all functions from zorro
#include "zorro_impl.h"

using namespace YourNamespace;

ZORRO_EXPORT void ZORRO_CALL run()
{
	if (is(EStatusFlag::INITRUN))
	{
		// your zorro code ...
	}
}
