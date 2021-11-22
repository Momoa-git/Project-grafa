#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "Shader.h"
#include "Model.h"
#include "ObserverDrawable.h"

class Object : public ObserverDrawable{
private:
	Shader* shader;
	glm::mat4 transMat;
	GLint idModelTransform;
	Model* model;

public:
	Object();
	Object(Model* model, Shader* shader);
	
	virtual void draw() override;
	Shader* getShader();
	//void draw();
	glm::mat4* getMatrix();


};

