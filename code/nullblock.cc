#include "nullblock.h"
#include "grid.h"
#include <stdexcept>
#include <string>

NullBlock::NullBlock(int shape):Block{shape, '*'} { }

void NullBlock::init(Grid &g) {
	try {
		g.setCell(3,5,'*');
		relatedCell.emplace_back(g.getCell(3,5));
	} catch (...) {
		string s;
		throw s;
	}
}

void NullBlock::clockWise(Grid &) { }
void NullBlock::counterClockWise(Grid &){ }
void NullBlock::hint() { }
