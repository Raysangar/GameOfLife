#include "stdafx.h"

enum State {
	DEAD,
	ALIVE
};


//These method is necessary to overwrite when using a class or enum as comparable value on Asserts
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

