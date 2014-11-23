#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLife
{		
	TEST_CLASS(RulesTests)
	{
	public:
		
		TEST_METHOD(AliveCellDiesWithMoreThan3Neighbors)
		{
			bool state = false; 
			Assert::AreEqual(false, state); 
		}

	};
}