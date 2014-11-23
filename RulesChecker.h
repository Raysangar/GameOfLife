#include "State.h"

class RulesChecker
{
public:
	static State getNextState(State actualState, int aliveNeighbors);
};