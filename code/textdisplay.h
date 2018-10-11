#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include "observer.h"


class Subject;
class TextDisplay:public Observer {
	std::vector<std::vector<char>> theDisplay; //the display is 10 * 18
public:
	TextDisplay();

	//void notify(Info frominfo) override;
    void notify(Info frominfo) override;

	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
