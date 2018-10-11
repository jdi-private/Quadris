#ifndef _L_BLOCK_H_
#define _L_BLOCK_H_
#include "block.h"

class Grid;

class LBlock: public Block {
        std::vector<Cell *> config0(bool ccw, Grid &g);
        std::vector<Cell *> config1(bool ccw, Grid &g);
        std::vector<Cell *> config2(bool ccw, Grid &g);
        std::vector<Cell *> config3(bool ccw, Grid &g);
public:
		void init(Grid &g) override;
        LBlock(int shape = 0);
        void clockWise(Grid &) override;
        void counterClockWise(Grid &) override;
        void hint() override;
};
#endif
