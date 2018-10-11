#include "grid.h"
#include "textdisplay.h"
#include <cstdlib>
using namespace std;
#include <time.h>
#include "graphicsdisplay.h"

 void Grid::setObserver(GraphicsDisplay *sOb){
         ob = sOb;
 }

bool Grid::isOccupied(int r, int c) {
    
	if(theGrid[r][c].getInfo().type == ' ' || r > 17 || c < 0 || c > 10)
		return false;
	return true;
}

Cell* Grid::getCell(int r, int c) {
	string s = "Range out of bound";
	if (r<0 || r> 17||(c<0|| c>10))
		throw s;
	else
		return &theGrid[r][c];
}

void Grid::init() {
	theGrid.clear();
	if (td)
		delete td;
	if(ob)
		delete ob;
	td = new TextDisplay{};
	GraphicsDisplay *gD = new GraphicsDisplay{};
	setObserver(gD);
	for (int i = 0;  i< 18; i++){
		vector<Cell> newRow;
		for (int j =0; j < 11; j++){
			Cell newCell{{i,j,' '}};
			newCell.attach(td);
			newCell.attach(ob);
			newRow.emplace_back(newCell);
		}
		theGrid.emplace_back(newRow);
	}
}

void Grid::setCell(int r, int c, char type_char){
	//char t = theGrid[r][c].getInfo().type;
	if (r >=0 && r<18 && c>=0 && c<18) {
        theGrid[r][c].setinfo({r, c, type_char});
        theGrid[r][c].notifyObservers();
    } else {
        string s = "Invalid Position!";
		throw s;
	}
}

void Grid::setNext(Block* next){
	nextBlock = next;
}

bool Grid::endGame() {
	char s = nextBlock->getletter();
	if (s == 'Z') {
		if(theGrid[3][0].getInfo().type != ' ') return true;
		if(theGrid[3][1].getInfo().type != ' ') return true;
		if(theGrid[4][1].getInfo().type != ' ') return true;
		if(theGrid[4][2].getInfo().type != ' ') return true;
	} else if(s == 'I') {
		if(theGrid[3][0].getInfo().type != ' ') return true;
		if(theGrid[3][1].getInfo().type != ' ') return true;
		if(theGrid[3][2].getInfo().type != ' ') return true;
		if(theGrid[3][3].getInfo().type != ' ') return true;
	} else if(s == 'J') {
		if(theGrid[3][0].getInfo().type != ' ') return true;
		if(theGrid[4][0].getInfo().type != ' ') return true;
		if(theGrid[4][1].getInfo().type != ' ') return true;
		if(theGrid[4][2].getInfo().type != ' ') return true;
	} else if(s == 'L') {
		if(theGrid[3][2].getInfo().type != ' ') return true;
		if(theGrid[4][0].getInfo().type != ' ') return true;
		if(theGrid[4][1].getInfo().type != ' ') return true;
		if(theGrid[4][2].getInfo().type != ' ') return true;
	} else if(s == 'O') {
		if(theGrid[3][0].getInfo().type != ' ') return true;
		if(theGrid[3][1].getInfo().type != ' ') return true;
		if(theGrid[4][0].getInfo().type != ' ') return true;
		if(theGrid[4][1].getInfo().type != ' ') return true;
	} else if(s == 'S') {
		if(theGrid[3][1].getInfo().type != ' ') return true;
		if(theGrid[3][2].getInfo().type != ' ') return true;
		if(theGrid[4][0].getInfo().type != ' ') return true;
		if(theGrid[4][1].getInfo().type != ' ') return true;
	} else if(s == 'T') {
		if(theGrid[3][0].getInfo().type != ' ') return true;
		if(theGrid[3][1].getInfo().type != ' ') return true;
		if(theGrid[3][2].getInfo().type != ' ') return true;
		if(theGrid[4][1].getInfo().type != ' ') return true;
	}
	return false;
}

int Grid::checkRows() {
	int rowCleared = 0;
	int flag = 1;
	for (int i = 3; i<18; i++){
		for (int j = 0; j<11; j++){
			if (theGrid[i][j].getInfo().type == ' ')
				flag = 0;
		}
		if (flag){
			rowCleared+=1;
			dropRow(i);
		}
		flag = 1;
	}
	return rowCleared;
}

void Grid::dropRow(int r) {
	int i = r;
	while (i>=3) {
		for(int j = 0; j<11; j++){
            Cell *temp = getCell(i-1, j);
            setCell(i,j,temp->getInfo().type);
//            theGrid[i][j].setinfo({i, j, (theGrid[i-1][j].getInfo().type)});
//            td->notify(theGrid[i-1][j].getInfo());
		}
		i-=1;
	}
}
//void generateBlock(char type_char){
//	if (type_char == 'I')
//		nextBlock = new IBlock;
//	else if (type_char == 'J')
//		nextBlock = new JBlock;
//	else if (type_char == "L")
//		nextBlock = new LBlock;
//	else if (type_char == "O")
//		nextBlock = new OBlock;
//	else if (type_char == "S")
//		nextBlock = new SBlock;
//	else if (type_char == "Z")
//		nextBlock = new ZBlock;
//	else if (type_char == "T")
//		nextBlock = new TBlock;
//}

//void generateBlock(){
//	srand(time(NULL));
//	int blockNum = rand() % 12;
//	if (blockNum < 2){
//		nextBlock = new IBlock;
//		return;
//	}
//	else if (blockNum < 4 ){
//		nextBlock = new JBlock;
//		return;
//	}
//	else if (blockNum < 6 ){
//		nextBlock = new JBlock;
//		return;
//	}
//	else if (blockNum < 8){
//		nextBlock = new JBlock;
//		return;
//	}
//	else if (blockNum < 10){
//		nextBlock = new JBlock;
//		return;
//	}
//	else if (blockNum < 11){
//		nextBlock = new JBlock;
//		return;
//	}
//	else if (blockNum < 12){
//		nextBlock = new JBlock;
//		return;
//	}
//}


ostream &operator<< (std::ostream &out, const Grid &g){
	out << *g.td;
	return out;
}

Grid::~Grid() {
	delete td;
	delete ob;
}

//void Grid::levelChange(int i){
//	if (level)
//		delete level;
//	if (i == 0){
//		//level = new Level0;
//	} else if (i == 1){
//		//level = new Level1;
//	} else if (i == 2){
//	//	level = new Level2;
//	} 
//	else if (i == 3){
//	//	level = new Level3;
//	}
//	else if (i == 4){
//	//	level = new Level4;
///	}
///	else if (i == 5){
//	//	level = new Level5;
////	}
