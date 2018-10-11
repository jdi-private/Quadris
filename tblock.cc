#include "tblock.h"
#include "grid.h"
#include <stdexcept>
#include <string>
using namespace std;
TBlock::TBlock(int shape):Block{shape,'T'} { }


void TBlock::init(Grid &g) {
	try{
        g.setCell(3, 0, 'T');
        g.setCell(3, 1, 'T');
        g.setCell(3, 2, 'T');
        g.setCell(4, 1, 'T');
		relatedCell.emplace_back(g.getCell(3,0));
		relatedCell.emplace_back(g.getCell(3,1));
		relatedCell.emplace_back(g.getCell(3,2));
		relatedCell.emplace_back(g.getCell(4,1));
	} catch(...) {
		string s = "Game Over";
		throw s;
	}
	}
/* a valid Tblock must have the following order of releated Cell

				  							 
	012	  0	         3	        2
	 3   or  31  or  	210       or    13
                  2				0
   config0      config1      config2         config3

*/

std::vector<Cell *> TBlock::config0(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x,y+1));
	temp.emplace_back(g.getCell(x,y+2));
	temp.emplace_back(g.getCell(x+1 ,y + 1));
	
	return temp;
}

std::vector<Cell *> TBlock::config1(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x + 1,y));
	temp.emplace_back(g.getCell(x + 2,y));
	temp.emplace_back(g.getCell(x +1 ,y - 1));

	return temp;
}

std::vector<Cell *> TBlock::config2(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x,y - 1));
	temp.emplace_back(g.getCell(x,y - 2));
	temp.emplace_back(g.getCell(x - 1,y - 1));

	return temp;
}

std::vector<Cell *> TBlock::config3(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x - 1,y));
	temp.emplace_back(g.getCell(x - 2,y));
	temp.emplace_back(g.getCell(x - 1,y + 1));
    
    return temp;
}

void TBlock::clockWise(Grid &g) {
	vector<Cell *> temp;
	Info ifo = relatedCell[0]->getInfo();
	if (shape == 0) {
		try {
			Cell *c = g.getCell(ifo.x_cor-1, ifo.y_cor + 1);
			temp = config1(c,g);
		} catch(...) {return; }
		shape = 1;
	} else if (shape == 1) {
		try {
			Cell *c = g.getCell(ifo.x_cor + 1, ifo.y_cor + 1);
			temp = config2(c,g);
		} catch(...) {return; }
		shape=2;
	} else if (shape == 2) {
		try {
			Cell *c = g.getCell(ifo.x_cor + 1, ifo.y_cor - 1);
			temp = config3(c,g);
		} catch(...) {return; }
		shape=3;
	} else {
		try {
			Cell *c = g.getCell(ifo.x_cor - 1, ifo.y_cor-1);
			temp = config0(c,g);
		} catch(...) {return; }
		shape=0;
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
		g.setCell(related_info.x_cor, related_info.y_cor, 'T');
	}

	//mutate shape

	cout<<shape;
}

void TBlock::counterClockWise(Grid &g) {
	vector<Cell *> temp;
	Info ifo = relatedCell[0]->getInfo();
	if (shape == 0) {
		try {
			Cell *c = g.getCell(ifo.x_cor +1, ifo.y_cor+1);
			temp = config3(c,g);
		} catch(...) {return; }
		shape=3;
	} else if (shape == 1) {
		try {
			Cell *c = g.getCell(ifo.x_cor+1, ifo.y_cor - 1);
			temp = config0(c,g);
		} catch(...) {return; }
		shape=0;
	} else if (shape == 2) {
		try {
			Cell *c = g.getCell(ifo.x_cor - 1, ifo.y_cor - 1);
			temp = config1(c,g);
		} catch(...) {return; }
		shape=1;
	} else {
		try {
			Cell *c = g.getCell(ifo.x_cor - 1, ifo.y_cor + 1);
			temp = config2(c,g);
		} catch(...) {return; }
		shape=2;
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
		g.setCell(related_info.x_cor, related_info.y_cor, 'T');
	}

	//mutate shape
}

void TBlock::hint() { }

