///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////
#define ZORRO_DLLMAIN
#define ZORRO_NAMESPACE YourNamespace
#include "zorro_impl.h"

using namespace YourNamespace;

ZORRO_EXPORT void ZORRO_CALL run()
{
	if (is(EStatusFlag::INITRUN))
	{
		// your zorro code ...
	}
}
