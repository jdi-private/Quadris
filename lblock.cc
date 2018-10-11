#include "lblock.h"
#include <stdexcept>
#include <string>
#include "grid.h"

using namespace std;

LBlock::LBlock(int shape):Block{0,'L'} { }

void LBlock::init(Grid &g) {
    try{
        g.setCell(4, 0, 'L');
        g.setCell(3, 2, 'L');
        g.setCell(4, 1, 'L');
        g.setCell(4, 2, 'L');
        relatedCell.emplace_back(g.getCell(4,0));
        relatedCell.emplace_back(g.getCell(4,1));
        relatedCell.emplace_back(g.getCell(4,2));
        relatedCell.emplace_back(g.getCell(3,2));
    } catch (...) { 
        string s = "Game Over";
        throw s;
    }
}
std::vector<Cell *> LBlock::config0(bool ccw, Grid &g) {
        vector<Cell *> temp;

        int r0 = relatedCell[0]->getInfo().x_cor;
		int c0 = relatedCell[0]->getInfo().y_cor;
		//int r1 = relatedCell[1]->getInfo().x_cor;
		//int c1 = relatedCell[1]->getInfo().y_cor;
		//int r2 = relatedCell[2]->getInfo().x_cor;
		//int c2 = relatedCell[2]->getInfo().y_cor;
		//int r3 = relatedCell[3]->getInfo().x_cor;
		
		if (!ccw){
		try{
        		temp.emplace_back(g.getCell(r0-1,c0-1));
        		temp.emplace_back(g.getCell(r0-1,c0));
        		temp.emplace_back(g.getCell(r0-1,c0+1));
        		temp.emplace_back(g.getCell(r0-2, c0+1));
		} catch(...) {
			temp = relatedCell;
			return temp;}
        } else {
		try {
        		temp.emplace_back(g.getCell(r0+1,c0-1));
        		temp.emplace_back(g.getCell(r0+1,c0));
        		temp.emplace_back(g.getCell(r0+1,c0+1));
        		temp.emplace_back(g.getCell(r0, c0+1));
        	} catch(...) {
			temp = relatedCell;
			return temp;;}}
        return temp;
}

std::vector<Cell *> LBlock::config1(bool ccw, Grid &g) {
        vector<Cell *> temp;

        int r0 = relatedCell[0]->getInfo().x_cor;
		int c0 = relatedCell[0]->getInfo().y_cor;
		//int r1 = relatedCell[1]->getInfo().x_cor;
		//int c1 = relatedCell[1]->getInfo().y_cor;
		//int r2 = relatedCell[2]->getInfo().x_cor;
		//int c2 = relatedCell[2]->getInfo().y_cor;
		int r3 = relatedCell[3]->getInfo().x_cor;
		int c3 = relatedCell[3]->getInfo().y_cor;
		if (!ccw){
		try{
        	temp.emplace_back(g.getCell(r0-1, c0+1));
        	temp.emplace_back(g.getCell(r0, c0+1));
        	temp.emplace_back(g.getCell(r0+1, c0+1));
        	temp.emplace_back(g.getCell(r0+1, c0+2));
		} catch(...){
			temp = relatedCell;
			return temp;}
        } else{
		try{
        	temp.emplace_back(g.getCell(r0, c0-1));
        	temp.emplace_back(g.getCell(r0+1, c0-1));
        	temp.emplace_back(g.getCell(r0+2, c0-1));
 	temp.emplace_back(g.getCell(r3+1, c3+2));
		} catch(...){
			temp = relatedCell;
			return temp;
		}
        }
        return temp;
}

std::vector<Cell *> LBlock::config2(bool ccw, Grid &g) {
        vector<Cell *> temp;
        int r0 = relatedCell[0]->getInfo().x_cor;
		int c0 = relatedCell[0]->getInfo().y_cor;
		int r1 = relatedCell[1]->getInfo().x_cor;
		int c1 = relatedCell[1]->getInfo().y_cor;
		int r2 = relatedCell[2]->getInfo().x_cor;
		int c2 = relatedCell[2]->getInfo().y_cor;
		int r3 = relatedCell[3]->getInfo().x_cor;
		int c3 = relatedCell[3]->getInfo().y_cor;
		if (!ccw){
        		try{
				temp.emplace_back(g.getCell(r0,c0+1));
        			temp.emplace_back(g.getCell(r1-1, c1));
        			temp.emplace_back(g.getCell(r2-2, c2-1));
        			temp.emplace_back(g.getCell(r3-1, c3-2));
			}catch(...) {
				temp = relatedCell;
				return temp;
			}
        } else {
		try{
        		temp.emplace_back(g.getCell(r3,c3+2));
        		temp.emplace_back(g.getCell(r3, c3+1));
       		 	temp.emplace_back(g.getCell(r3, c3));
        		temp.emplace_back(g.getCell(r3+1, c3));
    		} catch(...) {
			temp = relatedCell;
         		return temp;
		}
	}
    return temp;
}

std::vector<Cell *> LBlock::config3(bool ccw, Grid &g) {
	vector<Cell *> temp;
	
        //int r0 = relatedCell[0]->getInfo().x_cor;
        //int c0 = relatedCell[0]->getInfo().y_cor;
        int r1 = relatedCell[1]->getInfo().x_cor;
        int c1 = relatedCell[1]->getInfo().y_cor;
        int r2 = relatedCell[2]->getInfo().x_cor;
        int c2 = relatedCell[2]->getInfo().y_cor;
        int r3 = relatedCell[3]->getInfo().x_cor;
        int c3 = relatedCell[3]->getInfo().y_cor;
        if (!ccw){
        	try{
        		temp.emplace_back(g.getCell(r3+1,c3+1));
        		temp.emplace_back(g.getCell(r1+1, c1));
       	 		temp.emplace_back(g.getCell(r2, c2+1));
       			temp.emplace_back(g.getCell(r2, c2));
       		} catch(...) {
       			temp = relatedCell;
       			return temp;
       		}
       	} else {
       		try{
       	 		temp.emplace_back(g.getCell(r1+1,c1));
        		temp.emplace_back(g.getCell(r1, c1));
        		temp.emplace_back(g.getCell(r1-1, c1));
        		temp.emplace_back(g.getCell(r1-1, c1-1));
        	} catch(...) {
        		temp = relatedCell;
        		return temp;
        	}
    }
        return temp;
}

void LBlock::clockWise(Grid &g) {
        vector<Cell *> temp;
        if (shape == 0) {
                try {
                        temp = config1(false,g);
                        shape=1;
                } catch(...) { return; }
        } else if (shape == 1) {
                try {
                        temp = config2(false,g);
                        shape=2;
                } catch(...) { return; }
        } else if (shape == 2) {
                try {
                        temp = config3(false,g);
                        shape=3;
                } catch(...) { return; }
        } else {
                try {
                        temp = config0(false,g);
                        shape = 0;
                } catch(...) { return; }
        }

        for (auto c : temp) {
                Info temp_info = c->getInfo();
                if ((! inBlock(c)) && g.isOccupied(temp_info.x_cor, temp_info.y_cor)) {
                        return;
                }
        }

        relatedCell.swap(temp);
	
        for(auto c : temp) {
                Info temp_info = c->getInfo();
		 cout<<temp_info.x_cor<<temp_info.y_cor<<endl;

                g.setCell(temp_info.x_cor, temp_info.y_cor, ' ');
        }
	for (auto c : relatedCell) {
                Info related_info = c->getInfo();
                g.setCell(related_info.x_cor, related_info.y_cor, 'L');
        }
}

void LBlock::counterClockWise(Grid &g) {
        vector<Cell *> temp;
        if (shape == 0) {
                try {
                        temp = config3(true,g);
                        shape=3;
                } catch(...) { return; }
        } else if (shape == 1) {
                try {
                        temp = config0(true,g);
                        shape=0;
                } catch(...) { return; }
        } else if (shape == 2) {
                try {
                        temp = config1(true,g);
                        shape=1;
                } catch(...) { return; }
        } else {
                try {
                        temp = config2(true,g);
                        shape = 2;
                } catch(...) { return; }
        }

        for (auto c : temp) {
                Info temp_info = c->getInfo();
                if ((! inBlock(c)) && g.isOccupied(temp_info.x_cor, temp_info.y_cor)) {
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
                g.setCell(related_info.x_cor, related_info.y_cor, 'L');
        }
}

void LBlock::hint(){}

