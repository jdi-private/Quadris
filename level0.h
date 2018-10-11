#ifndef _LEVEL0_H
#define _LEVEL0_H
#include "level.h"
#include <string.h>

class Level0: public Level {
	std::ifstream levelFile;
	std::string source;
public:
	Level0(std::string source, int num = 0);
	Block *generateBlock() override;
};


#endif
