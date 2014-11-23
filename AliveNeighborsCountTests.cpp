#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{	
	TEST_CLASS(AliveNeighborsCountTests)
	{
	public:
		
		TEST_METHOD(ThreeAliveNeighbors)
		{
			int aliveNeighbors = 3;
			Assert::AreEqual(3, aliveNeighbors);
		}
	};
}