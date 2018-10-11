#ifndef _LEVEL1_H
#define _LEVEL1_H
#include "level.h"
class Level1: public Level {
	private:
		int seed;
		bool ifseed;
	public:
		void setseed(int s);
		Level1();
		Block *generateBlock() override;
};
#endif
