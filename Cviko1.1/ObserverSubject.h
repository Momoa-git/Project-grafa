#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Observer.h"

class ObserverSubject {
public:
	virtual ~ObserverSubject() {};
	virtual void Attach(Observer* observer) = 0;
	virtual void Detach(Observer* observer) = 0;
	virtual void Notify() = 0;
};