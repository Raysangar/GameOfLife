#ifndef CELL_H

#define CELL_H

#include "State.h"
#include <list>
class CellImplementation;

class Cell
{
private:
	CellImplementation* cellImpl;

public:
	Cell();
	Cell(State state, std::list<Cell> neighbors);
	virtual ~Cell();
	State getState() const;
	void nextGeneration();
};

#endif