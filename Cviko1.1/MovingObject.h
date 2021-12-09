#pragma once
#include "Object.h"
#include "Way.h"

class MovingObject : public Object
{
public:
	Way way;
//	MovingObject();
	MovingObject(Model* model, Shader* shader, GLint objectID = 0);
	void draw();

};

