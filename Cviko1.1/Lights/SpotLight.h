#pragma once
#include "PointLight.h"
class SpotLight :
	public PointLight
{
public:
	float cutOff;
	float outerCutOff;
	glm::vec3 direction;

	SpotLight(glm::vec3 direction, glm::vec3 position);
	SpotLight(glm::vec3 direction, float cutOff, float outerCutOff, glm::vec3 position);
	SpotLight(glm::vec3 direction, float cutOff, float outerCutOff, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position);
	void setCutOffUni(GLint location);
	void setOuterCutOffUni(GLint location);
	void setDirectionUni(GLint location);
	void setDirection(glm::vec3 direction);
};
