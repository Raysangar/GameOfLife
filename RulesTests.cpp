#include "stdafx.h"
#include "CppUnitTest.h"
#include "RulesChecker.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(RulesTests)
	{
	public:
		
		TEST_METHOD(AliveCellDiesWithMoreThan3AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, RulesChecker::getNextState(State::ALIVE, 4)); 
		}

		TEST_METHOD(AliveCellDiesWithLessThan2AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, RulesChecker::getNextState(State::ALIVE, 1)); 
		}

		TEST_METHOD(AliveCellSurviveWith2AliveNeighbors)
		{
			Assert::AreEqual(State::ALIVE, RulesChecker::getNextState(State::ALIVE, 2)); 
		}

		TEST_METHOD(AliveCellSurviveWith3AliveNeighbors)
		{
			Assert::AreEqual(State::ALIVE, RulesChecker::getNextState(State::ALIVE, 3)); 
		}

		TEST_METHOD(DeadCellKeepsDeadWith2AliveNeighbors)
		{
			Assert::AreEqual(State::DEAD, RulesChecker::getNextState(State::DEAD, 2)); 
		}

		TEST_METHOD(DeadCellResurrectWith3AliveNeighbors)
		{
			Assert::AreEqual(State::ALIVE, RulesChecker::getNextState(State::DEAD, 3)); 
		}
	};
}