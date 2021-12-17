#pragma once
#include <iostream>
#include <list>
#include <string>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include "Shader.h"
#include "Object.h"
#include <string>

class FactoryObject
{
public:
	
	FactoryObject();
	Object* newObject(Model* model, Shader* shader);
	Object* newObjectWithID(Model* model, Shader* shader, GLint objectID);



};
