#include "level1.h"
#include <time.h>
#include <cstdlib>
using namespace std;


Level1::Level1():Level{1}, seed{-1}, ifseed{false}{}

void Level1::setseed(int s) {
	seed = s;
	ifseed = true;
}

Block* Level1::generateBlock(){
	Block *b = nullptr;
	if (ifseed) {
		srand(seed);
	} else {
		srand(time(NULL));
	}
    int blockNum = rand() % 12;
    if (blockNum < 2){
            b = new IBlock{};
    }
    else if (blockNum < 4){
            b = new JBlock{};
    }
    else if (blockNum < 6){
            b = new OBlock{};
    }
    else if (blockNum < 8){
            b = new LBlock{};
    }
    else if (blockNum < 10){
            b = new TBlock{};
    }
    else if (blockNum < 11){
            b = new SBlock{};
    }
    else if (blockNum < 12){
            b = new ZBlock{};
    }
        return b;
}
