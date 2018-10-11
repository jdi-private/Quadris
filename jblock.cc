#include "jblock.h"
#include "grid.h"
#include <string>
#include <stdexcept>
using namespace std;
JBlock::JBlock(int shape):Block{0,'J'} { }
void JBlock::init(Grid &g) {
	try{
        g.setCell(4, 0, 'J');
        g.setCell(3, 0, 'J');
        g.setCell(4, 1, 'J');
        g.setCell(4, 2, 'J');
		relatedCell.emplace_back(g.getCell(4,0));
		relatedCell.emplace_back(g.getCell(3,0));
		relatedCell.emplace_back(g.getCell(4,1));
		relatedCell.emplace_back(g.getCell(4,2));
	} catch(...) {
		string s = "Game Over";
		throw s;
	}
}
/* a valid Jblock must have the following order of releated Cell

				0 1							 3
	1			2			320				 2
	023   or     3    or  	  1       or    1 0

   config0      config1      config2         config3

*/

std::vector<Cell *> JBlock::config0(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;
    
    temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x - 1,y));
	temp.emplace_back(g.getCell(x,y + 1));
	temp.emplace_back(g.getCell(x,y + 2));

	return temp;
}

std::vector<Cell *> JBlock::config1(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x,y));
	temp.emplace_back(g.getCell(x, y + 1));
	temp.emplace_back(g.getCell(x + 1, y));
	temp.emplace_back(g.getCell(x + 2, y));

	return temp;
}

std::vector<Cell *> JBlock::config2(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x, y));
	temp.emplace_back(g.getCell(x + 1, y));
	temp.emplace_back(g.getCell(x, y - 1));
	temp.emplace_back(g.getCell(x, y - 2));

	return temp;
}

std::vector<Cell *> JBlock::config3(Cell *position_0, Grid &g) {
	Info info_0 = position_0->getInfo();
	vector<Cell *> temp;

	int y = info_0.y_cor;
	int x = info_0.x_cor;

	temp.emplace_back(g.getCell(x, y));
	temp.emplace_back(g.getCell(x, y - 1 ));
	temp.emplace_back(g.getCell(x - 1, y));
	temp.emplace_back(g.getCell(x - 2, y));

	return temp;
}
void JBlock::clockWise(Grid &g) {
	vector<Cell *> temp;
	Info ifo = relatedCell[0]->getInfo();
	if (shape == 0) {
		try {
			Cell *c= g.getCell(ifo.x_cor - 1, ifo.y_cor);
			temp = config1(c,g);
		} catch(...) { return; }
	} else if (shape == 1) {
		try {
			Cell *c= g.getCell(ifo.x_cor + 1, ifo.y_cor + 2);
			temp = config2(c,g);
		} catch(...)  { return; }
	} else if (shape == 2) {
		try {
			Cell *c= g.getCell(ifo.x_cor + 1, ifo.y_cor - 1);
			temp = config3(c,g);
		} catch(...)  { return; }
	} else {
		try {
			Cell *c= g.getCell(ifo.x_cor - 1, ifo.y_cor - 1);
			temp = config0(c,g);
		} catch(...)  { return; }
	}

	for (auto c : temp) {
		Info temp_info = c->getInfo();
		if ((! inBlock(c)) && g.isOccupied(temp_info.y_cor, temp_info.x_cor)) {
			return;
		}
	}

	relatedCell.swap(temp);

	for(auto c : temp) {
		Info temp_info = c->getInfo();
		g.setCell(temp_info.x_cor, temp_info.y_cor, ' ');
	}

	for (auto c : relatedCell) {
		Info related_info = c->getInfo();
		g.setCell(related_info.x_cor, related_info.y_cor, 'J');
	}

	shape = ((shape + 1) <= 3) ? (shape + 1):0;
}
/* a valid Jblock must have the following order of releated Cell
 
              0 1                            3
 1            2            320               2
 023   or     3    or        1       or    1 0
 
 config0      config1      config2         config3
 
 */
void JBlock::counterClockWise(Grid &g) {
    vector<Cell *> temp;
    Info ifo = relatedCell[0]->getInfo();
    if (shape == 0) {
        try {
            Cell *c= g.getCell(ifo.x_cor + 1 , ifo.y_cor + 1);
            temp = config3(c,g);
        } catch(...) { return; }
    } else if (shape == 1) {
        try {
            Cell *c= g.getCell(ifo.x_cor + 1, ifo.y_cor);
            temp = config0(c,g);
        } catch(...)  { return; }
    } else if (shape == 2) {
        try {
            Cell *c= g.getCell(ifo.x_cor - 1, ifo.y_cor - 2);
            temp = config1(c,g);
        } catch(...)  { return; }
    } else {
        try {
            Cell *c= g.getCell(ifo.x_cor - 1, ifo.y_cor + 1);
            temp = config2(c,g);
        } catch(...)  { return; }
    }
    
    for (auto c : temp) {
        Info temp_info = c->getInfo();
        if ((! inBlock(c)) && g.isOccupied(temp_info.y_cor, temp_info.x_cor)) {
            return;
        }
    }
    
    relatedCell.swap(temp);
    
    for(auto c : temp) {
        Info temp_info = c->getInfo();
        g.setCell(temp_info.x_cor, temp_info.y_cor, ' ');
    }
    
    for (auto c : relatedCell) {
        Info related_info = c->getInfo();
        g.setCell(related_info.x_cor, related_info.y_cor, 'J');
    }
    
    shape = ((shape - 1) >= 0) ? (shape - 1):3;
}

void JBlock::hint() {  }



