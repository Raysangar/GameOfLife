#include "stdafx.h"
#include "CppUnitTest.h"
#include "State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(RulesTests)
	{
	public:
		
		TEST_METHOD(AliveCellDiesWithMoreThan3AliveNeighbors)
		{
			State state = State::DEAD; 
			Assert::AreEqual(State::DEAD, state); 
		}

		TEST_METHOD(AliveCellDiesWithLessThan2AliveNeighbors)
		{
			State state = State::DEAD; 
			Assert::AreEqual(State::DEAD, state); 
		}
	};
}