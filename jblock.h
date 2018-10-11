#ifndef _J_BLOCK_H_
#define _J_BLOCK_H_
#include "block.h"

class Grid;

class JBlock: public Block {
	std::vector<Cell *> config0(Cell *position_0, Grid &g);
	std::vector<Cell *> config1(Cell *position_0, Grid &g);
	std::vector<Cell *> config2(Cell *position_0, Grid &g);
	std::vector<Cell *> config3(Cell *position_0, Grid &g);
public:
	void init(Grid &g) override;
	JBlock(int shape = 0);
	void clockWise(Grid &) override;
	void counterClockWise(Grid &) override;
	void hint() override;
};
#endif
