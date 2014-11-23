#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(NeighborsStateGetterTests)
	{
	private:
		std::list<State> getNeighborsState(std::list<Cell> neighbors)
		{
			std::list<State> neighborsStateList;
			std::list<State>::const_iterator neighborsStateIterator;
			std::list<Cell>::const_iterator neighborsIterator;
			for (neighborsIterator = neighbors.begin(); neighborsIterator != neighbors.end(); ++neighborsIterator)
			{
				neighborsStateList.push_back(neighborsIterator->getState());
			}
			return neighborsStateList;
		}
	public:
		
		TEST_METHOD(OneAliveNeighborsOnTheListBegin)
		{
			std::list<Cell> neighbors;
			neighbors.push_back(Cell(State::ALIVE, std::list<Cell>()));
			neighbors.push_back(Cell(State::DEAD, std::list<Cell>()));
			neighbors.push_back(Cell(State::ALIVE, std::list<Cell>()));
			Assert::AreEqual(State::ALIVE, (*getNeighborsState(neighbors).begin()));
		}

		TEST_METHOD(OneDeadNeighborsOnTheListBegin)
		{
			std::list<Cell> neighbors;
			neighbors.push_back(Cell(State::DEAD, std::list<Cell>()));
			neighbors.push_back(Cell(State::DEAD, std::list<Cell>()));
			neighbors.push_back(Cell(State::ALIVE, std::list<Cell>()));
			Assert::AreEqual(State::DEAD, (*getNeighborsState(neighbors).begin()));
		}
	};
}