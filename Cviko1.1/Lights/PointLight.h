#pragma once
#include "LightBase.h"
#include "LightAttenuation.h"
class PointLight : public LightBase, public LightAttenuation
{
public:
	glm::vec3 position;


	PointLight();
	PointLight(glm::vec3 position);
	//PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 direction);
	void setPositionUni(GLint location);

};