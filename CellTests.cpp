#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(CellTests)
	{
	public:
		
		TEST_METHOD(CellKeepsAliveOnNextGeneration)
		{
			std::list<Cell> neighbors (3, Cell(State::ALIVE, std::list<Cell>()));
			Cell cell (State::ALIVE, neighbors);
			cell.nextGeneration();
			Assert::AreEqual(State::ALIVE, cell.getState()); 
		}

		TEST_METHOD(CellDiesOnNextGeneration)
		{
			std::list<Cell> neighbors (1, Cell(State::ALIVE, std::list<Cell>()));
			Cell cell (State::ALIVE, neighbors);
			cell.nextGeneration();
			Assert::AreEqual(State::DEAD, cell.getState()); 
		}

		TEST_METHOD(CellKeepsDeadOnNextGeneration)
		{
			Cell cell (State::DEAD, std::list<Cell>());
			cell.nextGeneration();
			Assert::AreEqual(State::DEAD, cell.getState()); 
		}

		TEST_METHOD(CellResurrectsOnNextGeneration)
		{
			std::list<Cell> neighbors (3, Cell(State::ALIVE, std::list<Cell>()));
			Cell cell (State::DEAD, neighbors);
			cell.nextGeneration();
			Assert::AreEqual(State::ALIVE, cell.getState()); 
		}
	};
}