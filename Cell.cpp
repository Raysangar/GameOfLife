#include <list>
#include "RulesChecker.h"


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
			neighborsStateList.push_back(neighborsIterator->getState());
		return neighborsStateList;
	}

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
	Cell(State state, std::list<Cell> neighbors) : state(state), neighbors(neighbors) {}
	virtual ~Cell() {}

	State getState() const
	{
		return state;
	}

	void nextGeneration()
	{
		state = RulesChecker::getNextState(state, getAliveNeighbors(getNeighborsState()));
	}
};