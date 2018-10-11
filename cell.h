#ifndef _CELL_H
#define _CELL_H
#include "info.h"
#include "subject.h"

class Cell:public Subject{
	Info info;
public:
    Cell(Info ifo):info{ifo} {}
    
	Info getInfo() override;
    
	void setinfo(Info inf);
};

#endif
