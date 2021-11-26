#pragma once
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>

class LightAttenuation
{
protected:
	float constant;
	float linear;
	float quadratic;

public:
	LightAttenuation();
	LightAttenuation(float constant, float linear, float quadratic);
	
	void setConstantUni(GLint location);
	void setLinearUni(GLint location);
	void setQuadraticUni(GLint location);
	

};
