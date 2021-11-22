#pragma once
#include <iostream>
#include <list>
#include <string>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

class ObserverSkyBox 
{
public:
	virtual ~ObserverSkyBox() {};
	virtual void update(glm::vec3 position) = 0;

};
