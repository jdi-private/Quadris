#ifndef _LEVEL3_H
#define _LEVEL3_H
#include "level.h"

class Level3: public Level {
	private:
		int seed;
		bool ifseed;
	public:
		void setseed(int s);
		Level3();
		Block *generateBlock() override;
};
#endif
