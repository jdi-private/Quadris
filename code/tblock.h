#ifndef TBLOCK__H
#define TBLOCK__H
#include "block.h"

class Grid;

class TBlock: public Block {
	std::vector<Cell *> config0(Cell *position_0, Grid &g);
	std::vector<Cell *> config1(Cell *position_0, Grid &g);
	std::vector<Cell *> config2(Cell *position_0, Grid &g);
	std::vector<Cell *> config3(Cell *position_0, Grid &g);

public:
	TBlock(int shape = 0);
	void clockWise(Grid &) override;
	void counterClockWise(Grid &) override;
	void hint() override;
	void init(Grid &g) override;
};

#endif
