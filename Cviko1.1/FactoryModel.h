#pragma once
#include <iostream>
#include <list>
#include <string>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include "Shader.h"
#include "Model.h"

using namespace::std;

class FactoryModel
{
public:
	string modelTitle;

	FactoryModel();
	 Model* newModel(string modelTitle);



};
