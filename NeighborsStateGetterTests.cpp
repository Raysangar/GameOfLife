#include "stdafx.h"
#include "CppUnitTest.h"
#include <list>
#include "State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	class Cell
	{
	private:
		State state;
		std::list<Cell> neighbors;

		std::list<State> getNeighborsState()
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
		Cell(State state, std::list<Cell> neighbors) : state(state), neighbors(neighbors) {}
		virtual ~Cell() {}

		State getState() const
		{
			return state;
		}
	};

	TEST_CLASS(NeighborsStateGetterTests)
	{
	private:
		
	public:
		
		TEST_METHOD(OneAliveNeighborsOnTheListBegin)
		{
			std::list<State> neighborsStateList;
			neighborsStateList.push_back(State::ALIVE);
			neighborsStateList.push_back(State::DEAD);
			neighborsStateList.push_back(State::ALIVE);
			Assert::AreEqual(State::ALIVE, (*neighborsStateList.begin()));
		}

		TEST_METHOD(OneDeadNeighborsOnTheListBegin)
		{
			std::list<State> neighborsStateList;
			neighborsStateList.push_back(State::DEAD);
			neighborsStateList.push_back(State::ALIVE);
			neighborsStateList.push_back(State::ALIVE);
			Assert::AreEqual(State::DEAD, (*neighborsStateList.begin()));
		}
	};
}