#include "iblock.h"
#include <stdexcept>
#include <string>
#include "grid.h"

using namespace std;
IBlock::IBlock(int shape): Block(shape, 'I') {  }

void IBlock::init(Grid &g) {
        try {
        g.setCell(3, 0, 'I');
        g.setCell(3, 1, 'I');
        g.setCell(3, 2, 'I');
        g.setCell(3, 3, 'I');

                relatedCell.emplace_back(g.getCell(3,0));
                relatedCell.emplace_back(g.getCell(3,1));
                relatedCell.emplace_back(g.getCell(3,2));
                relatedCell.emplace_back(g.getCell(3,3));
        } catch(...) {
                string s = "Game Over";
                throw s;
        }
}

/* a valid Iblock must have the following order of releated Cell
        0
        1
        2
        3    or         0123
 config1    config0
the realated cell is (3,0), (3,1), (3,3), (3,3) has config 0
the realated cell is (3,0), (2,0), (1,0), (0,0) has config 1
*/


std::vector<Cell *> IBlock::config0(Grid &g, Cell *position_0) {
        Info info_0 = position_0->getInfo();
        vector<Cell *> temp;
        int y = info_0.y_cor;
        int x = info_0.x_cor;

        temp.emplace_back(g.getCell(x,y));
        temp.emplace_back(g.getCell(x,y + 1));
         temp.emplace_back(g.getCell(x,y + 2));
        temp.emplace_back(g.getCell(x,y + 3));

        return temp;
}



//config0 consumes a posititon0 on config1, return the related cells
//      of config0
std::vector<Cell *> IBlock::config1(Grid &g, Cell *position_0) {
        Info info_0 = position_0->getInfo();
        vector<Cell *> temp;
        int y = info_0.y_cor;
        int x = info_0.x_cor;

        temp.emplace_back(g.getCell(x,y));
        temp.emplace_back(g.getCell(x + 1,y));
        temp.emplace_back(g.getCell(x + 2,y));
        temp.emplace_back(g.getCell(x + 3,y));

        return temp;
}

void IBlock::clockWise(Grid &g) {
        vector<Cell *> temp;
        Info inf = relatedCell[0]->getInfo();
        if (shape == 0) {
        try {
            Cell *c = g.getCell(inf.x_cor-3,inf.y_cor);
            temp = config1(g, c);
        } catch (...) {
            return;
        }
        } else {
                try {
                Cell *c = g.getCell(inf.x_cor+3, inf.y_cor);
                temp = config0(g, c);
                } catch(...) {return;}
                
        }
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
                g.setCell(related_info.x_cor, related_info.y_cor, 'I');
        }  
        //mutate shape
        shape = (shape == 1) ? 0 : 1;
}


void IBlock::counterClockWise(Grid &g) {
    vector<Cell *>temp;
    Info inf = relatedCell[0]->getInfo();
    if (shape == 0) {
        try {
            Cell *c = g.getCell(inf.x_cor-3, inf.y_cor);
            temp = config1(g, c);
        } catch (...) {
            return;
        }
        //check cells are empty
        for (int i = 0; i < 3; i++) {
            if ((temp[i]->getInfo()).type != ' ') {
                return;
            }
        }
        //swap the related Cells
        relatedCell.swap(temp);
        //clean old cells
        for (int i = 0; i < 4; i++) {
            Info info_temp = temp[i]->getInfo();
            g.setCell(info_temp.x_cor, info_temp.y_cor, ' ');
        }
        //set new cells
        for (int i = 0; i < 4; i++) {
            Info info_temp = relatedCell[i]->getInfo();
            g.setCell(info_temp.x_cor, info_temp.y_cor, 'I');
        }
        shape = 1;
    } else {
         try {
              Cell *c = g.getCell(inf.x_cor+3, inf.y_cor);
              temp = config0(g,c);
             } catch (...){return; }
        //check cells are empty
        for (int i = 1; i < 4; i++) {
            if ((temp[i]->getInfo()).type != ' ') {
                return;
            }
        }
        //swap the related Cells
        relatedCell.swap(temp);
        //clean old cells
        for (int i = 0; i < 4; i++) {
            Info info_temp = temp[i]->getInfo();
            g.setCell(info_temp.x_cor, info_temp.y_cor, ' ');
        }
        //set new cells
        for (int i = 0; i < 4; i++) {
            Info info_temp = relatedCell[i]->getInfo();
            g.setCell(info_temp.x_cor, info_temp.y_cor, 'I');
        }
        shape = 0;
	}
}


void IBlock::hint() {

}



