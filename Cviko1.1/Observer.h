#pragma once
#include <iostream>
#include <list>
#include <string>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>



class Observer 
{
public:
	virtual ~Observer() {};
	virtual void updateShader(glm::mat4 viewMat, glm::mat4 projMat, glm::vec3 cameraPos) = 0;
}; 
