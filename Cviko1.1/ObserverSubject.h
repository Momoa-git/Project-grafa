#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Observer.h"

class ObserverSubject {
public:
	virtual ~ObserverSubject() {};
	virtual void registerObserver(Observer* observer) = 0;
	virtual void unregisterObserver(Observer* observer) = 0;
	virtual void notify() = 0;
};