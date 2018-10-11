#include "block.h"

class Grid;


class OBlock: public Block {
public:
	void init(Grid &g) override;
	OBlock(int shape = 0);
	void clockWise(Grid &) override;
	void counterClockWise(Grid &) override;
	void hint() override;
};
