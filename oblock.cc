#include "block.h"
#include "grid.h"
#include <stdexcept>
#include <string>

using namespace std;
OBlock::OBlock(int shape): Block{shape, 'O'} { }
void OBlock::init(Grid &g) {
	try{
        g.setCell(3, 0, 'O');
        g.setCell(3, 1, 'O');
        g.setCell(4, 0, 'O');
        g.setCell(4, 1, 'O');
		relatedCell.emplace_back(g.getCell(3,0));
		relatedCell.emplace_back(g.getCell(3,1));
		relatedCell.emplace_back(g.getCell(4,0));
		relatedCell.emplace_back(g.getCell(4,1));
	}
	catch(...) { 
		string s = "Game Over";
		throw s;
	}
}
//OBlock has no clockwise and counterClockWise.
void OBlock::clockWise(Grid &) {  }
void OBlock::counterClockWise(Grid &) {  }
void OBlock::hint() {  }
