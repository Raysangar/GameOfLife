#include "stdafx.h"
#include "CppUnitTest.h"
#include "State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(RulesTests)
	{
	private:
		State getNextState(int aliveNeighbors) {
			return State::DEAD;
		}
	public:
		
		TEST_METHOD(AliveCellDiesWithMoreThan3AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, getNextState(4)); 
		}

		TEST_METHOD(AliveCellDiesWithLessThan2AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, getNextState(1)); 
		}
	};
}