#include "LightAttenuation.h"

LightAttenuation::LightAttenuation()
{
	this->constant = 1.0f;
	this->linear = 0.09f;
	this->quadratic = 0.032f;
}

LightAttenuation::LightAttenuation(float constant, float linear, float quadratic)
{
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
}

void LightAttenuation::setConstantUni(GLint location) {
	glUniform1f(location, this->constant);
}
void LightAttenuation::setLinearUni(GLint location) {
	glUniform1f(location, this->linear);
}
void LightAttenuation::setQuadraticUni(GLint location) {
	glUniform1f(location, this->quadratic);
}