#include "stdafx.h"

enum State {
	DEAD,
	ALIVE
};

namespace Microsoft
{ 
    namespace VisualStudio
    { 
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<State>(const State& t) { RETURN_WIDE_STRING(t); }
        }
    }
}

