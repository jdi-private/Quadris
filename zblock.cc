#include "zblock.h"
#include "grid.h"
#include <stdexcept>
#include <string>
ZBlock::ZBlock(int shape):Block{shape,'Z'} { }

void ZBlock::init(Grid &g) {
	try{
        g.setCell(3, 0, 'Z');
        g.setCell(3, 1, 'Z');
        g.setCell(4, 1, 'Z');
        g.setCell(4, 2, 'Z');
	relatedCell.emplace_back(g.getCell(3,0));
	relatedCell.emplace_back(g.getCell(3,1));
	relatedCell.emplace_back(g.getCell(4,1));
	relatedCell.emplace_back(g.getCell(4,2));
	} catch (...){
		string s = "Game Over";
		throw s;
	}
}
/* a valid Tblock must have the following order of releated Cell
				  							 
	01			  0
	 23   or     2 1
				3			
   config0      config1  
*/
std::vector<Cell *> ZBlock::config0(Grid &g, Cell *position_0) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;
	int y = info_0.y_cor;
	int x = info_0.x_cor;
	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x,y + 1));
	temp.emplace_back(g.getCell(x + 1,y + 1));
	temp.emplace_back(g.getCell(x + 1,y + 2));
	return temp;
}
std::vector<Cell *> ZBlock::config1(Grid &g, Cell *position_0) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;
	int y = info_0.y_cor;
	int x = info_0.x_cor;
	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x + 1,y));
	temp.emplace_back(g.getCell(x+1,y - 1));
	temp.emplace_back(g.getCell(x+2,y-1));
	return temp;
}


void ZBlock::clockWise(Grid &g) {
	vector<Cell *> temp;
	Info ifo = relatedCell[0]->getInfo();
	if (shape == 0) {
		try {
			Cell *c = g.getCell(ifo.x_cor-1, ifo.y_cor+1);
			temp = config1(g,c);
		} catch (...){return; }
	} else if (shape == 1) {
		try {
			Cell *c = g.getCell(ifo.x_cor+1, ifo.y_cor-1);
			temp = config0(g,c);
		} catch (...){return; }
	}
	// catch occupied
	for (auto c : temp) {
		Info temp_info = c->getInfo();
		if ((! inBlock(c)) && g.isOccupied(temp_info.x_cor, temp_info.y_cor)) {
			return;
		}
	}
	//if not occupied, swap temp and related cell
	relatedCell.swap(temp);
	//set cells in temp to be empty block
	for(auto c : temp) {
		Info temp_info = c->getInfo();
		g.setCell(temp_info.x_cor, temp_info.y_cor, ' ');
	}
	//set cell in relatedCell to JBlock
	for (auto c : relatedCell) {
		Info related_info = c->getInfo();
		g.setCell(related_info.x_cor, related_info.y_cor, 'Z');
	}
	//mutate shape
	shape = (shape == 1) ? 0:1; 
}


void ZBlock::counterClockWise(Grid &g) {
	vector<Cell *> temp;
	Info ifo = relatedCell[0]->getInfo();
	if (shape == 0) {
		try {
			Cell *c = g.getCell(ifo.x_cor-1, ifo.y_cor +1);
			temp = config1(g,c);
		} catch (...){return; }
	} else if (shape == 1) {
		try {
			Cell *c = g.getCell(ifo.x_cor+1, ifo.y_cor-1);
			temp = config0(g,c);
		} catch (...){return; }
	} 
	// catch occupied
	for (auto c : temp) {
		Info temp_info = c->getInfo();
		if ((! inBlock(c)) && g.isOccupied(temp_info.x_cor, temp_info.y_cor)) {
			return;
		}
	}
	//if not occupied, swap temp and related cell
	relatedCell.swap(temp);
	//set cells in temp to be empty block
	for(auto c : temp) {
		Info temp_info = c->getInfo();
		g.setCell(temp_info.x_cor, temp_info.y_cor, ' ');
	}
	//set cell in relatedCell to JBlock
	for (auto c : relatedCell) {
		Info related_info = c->getInfo();
		g.setCell(related_info.x_cor, related_info.y_cor, 'Z');
	}
	//mutate shape
	shape = (shape == 1) ? 0:1; 
}
void ZBlock::hint() { }
