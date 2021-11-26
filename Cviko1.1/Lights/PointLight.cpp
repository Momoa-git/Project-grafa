#include "PointLight.h"

PointLight::PointLight(glm::vec3 position) : LightBase(), LightAttenuation()
{
	this->position = position;
	
}/*
PointLight::PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position) : position(position), LightBase(ambient, diffuse, specular) 
{
	
}*/
void PointLight::setPositionUni(GLint location)
{
	glUniform3fv(location, 1, glm::value_ptr(this->position));
}
