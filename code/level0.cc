#include "level0.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Level0::Level0(string source, int num): Level{num}, source{source} {
    levelFile.open(source);
	if (! levelFile.is_open()) {
		throw invalid_argument("wrong source file");
	}
}

Block *Level0::generateBlock() {
	char c;
	if (levelFile.eof()) {
		levelFile.close();
		levelFile.clear();
		levelFile.open(source);
	}
	levelFile >> c;
	Block *b = nullptr;
    if ( c == 'I') {
        b = new IBlock{};
    } else if ( c == 'J') {
        b = new JBlock{};
    } else if ( c == 'L') {
        b = new LBlock{};
    }
    else if ( c == 'O') {
        b = new OBlock{};
    }
    else if ( c == 'T') {
        b = new TBlock{};
    }else if ( c == 'Z') {
        b = new ZBlock{};
    } else {
        b = new SBlock{};
    }
	return b;
}

