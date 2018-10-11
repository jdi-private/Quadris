#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "info.h"
#include "observer.h"
class Subject{
	std::vector<Observer *> observers;
public:
	void attach(Observer *o);
	void notifyObservers();
	virtual Info getInfo() = 0;
};
#endif
