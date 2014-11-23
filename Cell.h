#ifndef CELL_H

#define CELL_H

#include "State.h"
#include <list>

class Cell
{
private:
	State state;
	std::list<Cell> neighbors;

	std::list<State> getNeighborsState();
	int getAliveNeighbors(std::list<State> neighborsStateList);
public:
	Cell(State state, std::list<Cell> neighbors);
	virtual ~Cell();
	State getState() const;
	void nextGeneration();
};

#endif