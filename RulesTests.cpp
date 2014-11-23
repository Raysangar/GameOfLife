#include "stdafx.h"
#include "CppUnitTest.h"
#include "State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(RulesTests)
	{
	public:
		
		TEST_METHOD(AliveCellDiesWithMoreThan3Neighbors)
		{
			State state = State::DEAD; 
			Assert::AreEqual(State::DEAD, state); 
		}

	};
}