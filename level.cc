#include "level.h"

Level::Level(int num): levelNum{num} { }

int Level::getLevelNum() {
	return levelNum;
}

Block *Level::getnullblock() {
	Block *b = new NullBlock{};
	return b;
}
