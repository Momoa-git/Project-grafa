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
	string model_title;

	FactoryModel();
	 Model* newModel(string model_title);



};
