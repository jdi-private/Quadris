#ifndef _LEVEL_H
#define _LEVEL_H
#include <fstream>
#include <string>
#include "block.h"
#include "sblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "tblock.h"
#include "zblock.h"
#include "nullblock.h"


class Level {
	int levelNum;
	
	// std::ifstream levelFile;
	// std::string source;
	// bool hasFile;
public:
	Level(int num);
	virtual Block *generateBlock() = 0;
	int getLevelNum();

	Block *getnullblock();
	
	virtual ~Level() = default;
};
#endif
