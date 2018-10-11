#ifndef _LEVEL4_H
#define _LEVEL4_H
#include "level.h"

class Level4: public Level {
	private:
		int seed;
		bool ifseed;
	public:
		void setseed(int s);
		Level4();
		Block *generateBlock() override;
};
#endif

