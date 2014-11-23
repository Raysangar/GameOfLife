#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "RulesChecker.h"
#include "State.h"

Cell::Cell(State state, std::list<Cell> neighbors) : state(state), neighbors(neighbors) {}
Cell::~Cell() {}

State Cell::getState() const
{
	return state;
}

void Cell::nextGeneration()
{
	state = RulesChecker::getNextState(state, getAliveNeighbors(getNeighborsState()));
}

std::list<State> Cell::getNeighborsState()
{
	std::list<State> neighborsStateList;
	for (std::list<Cell>::const_iterator neighborsIterator = neighbors.begin(); neighborsIterator != neighbors.end(); ++neighborsIterator)
		neighborsStateList.push_back(neighborsIterator->getState());
	return neighborsStateList;
}

int Cell::getAliveNeighbors(std::list<State> neighborsStateList) 
{
	int aliveNeighbors = 0;
	for (std::list<State>::const_iterator iterator = neighborsStateList.begin(); iterator != neighborsStateList.end(); ++iterator)
		if (State::ALIVE == (*iterator)) ++aliveNeighbors;
	return aliveNeighbors;
}