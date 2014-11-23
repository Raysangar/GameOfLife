#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "RulesChecker.h"

class CellImplementation
{
public:
	State state;
	std::list<Cell> neighbors;

	CellImplementation() : state(State::DEAD), neighbors(std::list<Cell>()) {}
	CellImplementation(State state, std::list<Cell> neighbors) : state(state), neighbors(neighbors) {}

	std::list<State> getNeighborsState()
	{
		std::list<State> neighborsStateList;
		for (std::list<Cell>::const_iterator neighborsIterator = neighbors.begin(); neighborsIterator != neighbors.end(); ++neighborsIterator)
			neighborsStateList.push_back(neighborsIterator->getState());
		return neighborsStateList;
	}

	int getAliveNeighbors() 
	{
		std::list<State> neighborsStateList = getNeighborsState();
		int aliveNeighbors = 0;
		for (std::list<State>::const_iterator iterator = neighborsStateList.begin(); iterator != neighborsStateList.end(); ++iterator)
			if (State::ALIVE == (*iterator)) ++aliveNeighbors;
		return aliveNeighbors;
	}
};

Cell::Cell() : cellImpl(new CellImplementation) {}
Cell::Cell(State state, std::list<Cell> neighbors) : cellImpl(new CellImplementation(state, neighbors)) {}
Cell::~Cell() {}

State Cell::getState() const
{
	return cellImpl->state;
}

void Cell::nextGeneration()
{
	cellImpl->state = RulesChecker::getNextState(cellImpl->state, cellImpl->getAliveNeighbors());
}