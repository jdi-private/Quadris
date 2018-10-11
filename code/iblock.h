#ifndef _I_BLOCK_H_
#define _I_BLOCK_H_
#include "block.h"

class Grid;

class IBlock: public Block {
        std::vector<Cell *> config0(Grid &g, Cell *position_0);
        std::vector<Cell *> config1(Grid &g, Cell *position_0);
public:
        void init(Grid &) override;
        IBlock(int shape=0);
        void clockWise(Grid &) override;
        void counterClockWise(Grid &) override;
        void hint() override;
};

#endif

