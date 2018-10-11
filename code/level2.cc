#include "level2.h"
#include <time.h>
#include <cstdlib>
using namespace std;


Level2::Level2():Level{2}, seed{-1}, ifseed{false}{}

void Level2::setseed(int s) {
        seed = s;
        ifseed = true;
}

Block* Level2::generateBlock(){
	Block *b = nullptr;
	if (ifseed) {
                srand(seed);
        } else {
                srand(time(NULL));
        }
        int blockNum = rand() % 7;
        if (blockNum < 1){
                b = new IBlock{};
        }
        else if (blockNum < 2){
                b = new JBlock{};
        }
        else if (blockNum < 3){
                b = new OBlock{};
        }
        else if (blockNum < 4){
                b = new LBlock{};
        }
        else if (blockNum < 5){
                b = new TBlock{};
        }
        else if (blockNum < 6){
                b = new SBlock{};
        }
        else if (blockNum < 7){
                b = new ZBlock{};
        }
        return b;
}
