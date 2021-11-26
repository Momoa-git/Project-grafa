#pragma once
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>

class LightBase
{
protected:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
public:
	LightBase();
	LightBase(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	void setAmbientUni(GLint location);
	void setDiffuseUni(GLint location);
	void setSpecularUni(GLint location);
};
