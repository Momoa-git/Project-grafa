#include "PointLight.h"
//p
PointLight::PointLight(glm::vec3 position) : LightBase() {
	this->position = position;
	this->constant = 1.0f;
	this->linear = 0.09f;
	this->quadratic = 0.032f;
}
PointLight::PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position) : position(position), LightBase(ambient, diffuse, specular) {
	this->constant = 1.0f;
	this->linear = 0.09f;
	this->quadratic = 0.032f;
}
void PointLight::setPositionUni(GLint location) {
	glUniform3fv(location, 1, glm::value_ptr(this->position));
}
void PointLight::setConstantUni(GLint location) {
	glUniform1f(location, this->constant);
}
void PointLight::setLinearUni(GLint location) {
	glUniform1f(location, this->linear);
}
void PointLight::setQuadraticUni(GLint location) {
	glUniform1f(location, this->quadratic);
}