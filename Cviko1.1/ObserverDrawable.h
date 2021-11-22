#pragma once
#include <iostream>
#include <list>
#include <string>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

class ObserverDrawable
{
public:
	virtual ~ObserverDrawable() {};
	virtual void draw() {};

};
