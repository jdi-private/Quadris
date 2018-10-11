#ifndef _zblock_
#define _zblock_
#include "block.h"
class Grid;
class ZBlock: public Block {
	std::vector<Cell *> config0(Grid &g, Cell *position_0);
	std::vector<Cell *> config1(Grid &g, Cell *position_0);
public:
	ZBlock(int shape=0);
	void clockWise(Grid &) override;
	void counterClockWise(Grid &) override;
	void hint() override;
	void init(Grid &g) override;
};

#endif
