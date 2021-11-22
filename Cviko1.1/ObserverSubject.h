#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Observer.h"
#include "ObserverSkyBox.h"

class ObserverSubject {
public:
	virtual ~ObserverSubject() {};
	virtual void registerObserver(Observer* observer) = 0;
	virtual void unregisterObserver(Observer* observer) = 0;
	virtual void registerObserver(ObserverSkyBox* observer) = 0;
	virtual void unregisterObserver(ObserverSkyBox* observer) = 0;
	virtual void notify() = 0;
};