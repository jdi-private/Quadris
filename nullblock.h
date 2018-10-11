#ifndef _NULLBLOCK_H_
#define _NULLBLOCK_H_

#include "block.h"

class NullBlock: public Block {
	public:
	void init(Grid &g) override;
	NullBlock(int shape = 0);
	void clockWise(Grid &) override;
	void counterClockWise(Grid &) override;
	void hint() override;
};

#endif
