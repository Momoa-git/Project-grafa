#pragma once
#include "LightBase.h"
class DirectionalLight :
	public LightBase
{
public:
	glm::vec3 direction;

	DirectionalLight();
	DirectionalLight(glm::vec3 direction);
	DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 direction);
	void setDirectionUni(GLint location);
};
