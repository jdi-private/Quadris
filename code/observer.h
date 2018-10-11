#ifndef _OBSERVER_H
#define _OBSERVER_H
#include "info.h"



class Observer{
public:
	virtual void notify(Info inf) = 0;
    //virtual void notify(Subject &whoNitified) = 0;
	virtual ~Observer() = default;
};

#endif
