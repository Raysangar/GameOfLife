#ifndef RULES_CHECKER_H

#define RULES_CHECKER_H

#include "State.h"

class RulesChecker
{
public:
	static State getNextState(State actualState, int aliveNeighbors);
};

#endif