#include "stdafx.h"
#include "CppUnitTest.h"
#include "State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(RulesTests)
	{
	private:
		State getNextState(State actualState, int aliveNeighbors) {
			if (State::ALIVE == actualState)
				if ((aliveNeighbors == 2) || (aliveNeighbors == 3))
					return State::ALIVE;
			return State::DEAD;
		}
	public:
		
		TEST_METHOD(AliveCellDiesWithMoreThan3AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, getNextState(State::ALIVE, 4)); 
		}

		TEST_METHOD(AliveCellDiesWithLessThan2AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, getNextState(State::ALIVE, 1)); 
		}

		TEST_METHOD(AliveCellSurviveWith2AliveNeighbors)
		{
			Assert::AreEqual(State::ALIVE, getNextState(State::ALIVE, 2)); 
		}

		TEST_METHOD(AliveCellSurviveWith3AliveNeighbors)
		{
			Assert::AreEqual(State::ALIVE, getNextState(State::ALIVE, 3)); 
		}

		TEST_METHOD(DeadCellKeepsDeadWith2AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, getNextState(State::DEAD, 2)); 
		}
	};
}