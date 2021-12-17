#include "SpotLight.h"

SpotLight::SpotLight(glm::vec3 direction, glm::vec3 position) : LightBase(), LightAttenuation() 
{
	this->position = position;
	this->direction = direction;
	this->cutOff = glm::cos(glm::radians(12.5f));
	this->outerCutOff = glm::cos(glm::radians(15.f));
}
SpotLight::SpotLight(glm::vec3 direction, float cutOff, float outerCutOff, glm::vec3 position) : LightBase(), LightAttenuation() 
{
	this->direction = direction;
	this->cutOff = cutOff;
	this->outerCutOff = outerCutOff;
}

void SpotLight::setCutOffUni(GLint location) 
{
	glUniform1f(location, this->cutOff);
}
void SpotLight::setOuterCutOffUni(GLint location) 
{
	glUniform1f(location, this->outerCutOff);
}
void SpotLight::setDirectionUni(GLint location) 
{
	glUniform3fv(location, 1, glm::value_ptr(this->direction));
}
void SpotLight::setDirection(glm::vec3 direction) 
{
	this->direction = direction;
}

void SpotLight::setPositionUni(GLint location)
{
	glUniform3fv(location, 1, glm::value_ptr(this->position));
}