#include "stdafx.h"
#include "CppUnitTest.h"
#include "RulesChecker.h"

State RulesChecker::getNextState(State actualState, int aliveNeighbors)
{
	if (3 == aliveNeighbors)
		return State::ALIVE;
	if (2 == aliveNeighbors)
		return actualState;
	return State::DEAD;
}