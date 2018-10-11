#include "level4.h"
#include <time.h>
#include <cstdlib>
using namespace std;


Level4::Level4():Level{4}, seed{-1}, ifseed{false} {}

void Level4::setseed(int s) {
        seed = s;
        ifseed = true;
}




Block* Level4::generateBlock(){
	Block *b = nullptr;
	if (ifseed) {
                srand(seed);
        } else {
                srand(time(NULL));
        }
        int blockNum = rand() % 9;
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
        else if (blockNum < 7){
                b = new SBlock{};
        }
        else if (blockNum < 9){
                b = new ZBlock{};
        }
        return b;
}
