#ifndef _LEVEL2_H
#define _LEVEL2_H
#include "level.h"

class Level2: public Level {
	private:
		int seed;
		bool ifseed;
	public:
		void setseed(int s);
		Level2();
		Block *generateBlock() override;
};
#endif
