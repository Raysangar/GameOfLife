#include "stdafx.h"
#include "CppUnitTest.h"
#include <list>
#include "State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(AliveNeighborsCountTests)
	{
	private:

		int getAliveNeighbors(std::list<State> neighborsStateList) 
		{
			int aliveNeighbors = 0;
			std::list<State>::const_iterator iterator;
			for (iterator = neighborsStateList.begin(); iterator != neighborsStateList.end(); ++iterator)
			{
				if (State::ALIVE == (*iterator))
					++aliveNeighbors;
			}
			return aliveNeighbors;
		}
	public:
		
		TEST_METHOD(ThreeAliveNeighbors)
		{
			std::list<State> neighborsStateList (3, ALIVE);
			Assert::AreEqual(3, getAliveNeighbors(neighborsStateList));
		}

		TEST_METHOD(TwoAliveNeighbors)
		{
			std::list<State> neighborsStateList (2, ALIVE);
			Assert::AreEqual(2, getAliveNeighbors(neighborsStateList));
		}
	};
}