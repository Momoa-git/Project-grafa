#include "DirectionalLight.h"
DirectionalLight::DirectionalLight() :LightBase() {
	//this->direction = glm::vec3(.0f, -1.f, 1.f);
}
DirectionalLight::DirectionalLight(glm::vec3 direction) : direction(direction) {

}
DirectionalLight::DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 direction)
	: direction(direction), LightBase(ambient, diffuse, specular) {
}
void DirectionalLight::setDirectionUni(GLint location) {
	glUniform3fv(location, 1, glm::value_ptr(this->direction));
}