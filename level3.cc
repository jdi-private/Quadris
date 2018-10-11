#include "level3.h"
#include <time.h>
#include <cstdlib>
using namespace std;


Level3::Level3():Level{3}, seed{-1}, ifseed{false} {}




void Level3::setseed(int s) {
        seed = s;
        ifseed = true;
}





Block* Level3::generateBlock(){
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
