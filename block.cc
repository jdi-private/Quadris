#include "block.h"
#include "grid.h"
#include "cell.h"

bool Block::inBlock(Cell *c) {
	for (auto temp : relatedCell) {
		if (temp == c) {
			return true;
		}
	}
	return false;
}

Block::Block(int shape, char letter): shape{shape}, letter{letter} { }

void Block::attachCell(Cell *c) {
	relatedCell.emplace_back(c);
}
void Block::unset(Grid &g) {
	for (auto temp : relatedCell) {
		g.setCell(temp->getInfo().x_cor, temp->getInfo().y_cor, ' ');
	}
}

void Block::left(Grid &g) {
	//check whether can move left
	for (Cell *c : relatedCell) {
		Info info = c->getInfo();
		if (info.y_cor - 1 < 0) return;
		Cell *left_cell = g.getCell(info.x_cor, info.y_cor - 1);
		if ((! inBlock(left_cell)) && g.isOccupied(info.x_cor, info.y_cor - 1)) {
			return;
		}
	}
    
	//move the Cell
    char t = relatedCell[0]->getInfo().type;
    for (Cell *c : relatedCell) {
        Info info = c->getInfo();
        g.setCell(info.x_cor, info.y_cor, ' ');
    }
    
    for (Cell *c : relatedCell) {
        Info info = c->getInfo();
        g.setCell(info.x_cor, info.y_cor - 1, t);
        //add the new related cells to reletedCell
        Cell *temp = g.getCell(info.x_cor,info.y_cor - 1);
        relatedCell.emplace_back(temp);
    }
	//earse the old 4 related cells.
	relatedCell.erase(relatedCell.begin(),relatedCell.begin()+4);
}

void Block::right(Grid &g) {
	//check whether can move right
	for (Cell *c : relatedCell) {
		Info info = c->getInfo();
		if (info.y_cor + 1 > 10) return;
		Cell *right_cell = g.getCell(info.x_cor, info.y_cor + 1);
		if ((! inBlock(right_cell)) && g.isOccupied(info.x_cor, info.y_cor + 1)) {
			return;
		}
	}
    char t = relatedCell[0]->getInfo().type;
    for (Cell *c : relatedCell) {
        Info info = c->getInfo();
        g.setCell(info.x_cor, info.y_cor, ' ');
    }
    
	for (Cell *c : relatedCell) {
		Info info = c->getInfo();
		g.setCell(info.x_cor, info.y_cor + 1, t);
		//add the new related cells to reletedCell
		Cell *temp = g.getCell(info.x_cor,info.y_cor + 1);
		relatedCell.emplace_back(temp);
	}
	//earse the old 4 related cells.
	relatedCell.erase(relatedCell.begin(),relatedCell.begin()+4);
}

bool Block::down(Grid &g) {
	//check whether can move down
	for (Cell *c : relatedCell) {
		Info info = c->getInfo();
		if (info.x_cor + 1 < 0) return false;
        Cell *down_cell;
        try {
            down_cell = g.getCell(info.x_cor + 1, info.y_cor);
        } catch(...) {
            return false;
        }
		if ((! inBlock(down_cell)) && g.isOccupied(info.x_cor + 1, info.y_cor)) {
			return false;
		}
	}
    //move the Cell
    char t = relatedCell[0]->getInfo().type;
    for (Cell *c : relatedCell) {
        Info info = c->getInfo();
        g.setCell(info.x_cor, info.y_cor, ' ');
    }
    
    for (Cell *c : relatedCell) {
        Info info = c->getInfo();
        g.setCell(info.x_cor + 1, info.y_cor, t);
        //add the new related cells to reletedCell
        Cell *temp = g.getCell(info.x_cor + 1,info.y_cor);
        relatedCell.emplace_back(temp);
    }
//    for (Cell *c : relatedCell) {
//        Info info = c->getInfo();
//        g.setCell(info.x_cor + 1, info.y_cor, info.type);
//        g.setCell(info.x_cor, info.y_cor, ' ');
//        //add the new related cells to reletedCell
//        Cell *temp = g.getCell(info.x_cor + 1, info.y_cor);
//        relatedCell.emplace_back(temp);
//    }
	//earse the old 4 related cells.
	if (relatedCell.size() < 4) { relatedCell.erase(relatedCell.begin(),relatedCell.begin()+1);
	} else { relatedCell.erase(relatedCell.begin(),relatedCell.begin()+4); }
	return true; 
}

void Block::drop(Grid &g) {
	while(down(g)) { }
}


char Block::getletter() {
	return letter;
}
