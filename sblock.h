#ifndef _sblock_
#define _sblock_
#include "block.h"
class Grid;
class SBlock: public Block {
        std::vector<Cell *> config0(Grid &g, Cell *position_0);
        std::vector<Cell *> config1(Grid &g, Cell *position_0);
public:
        SBlock(int shape=0);
        void clockWise(Grid &) override;
        void counterClockWise(Grid &) override;
        void hint() override;
        void init(Grid &g) override;
};

#endif
