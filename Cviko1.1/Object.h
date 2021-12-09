#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "Shader.h"
#include "Model.h"
#include "Way.h"
#include "Transformation.h"
#include "Drawable.h"

class Object{
protected:
	Shader* shader;
	glm::mat4 transMat;
	GLint idModelTransform;
	Model* model;
	GLint objectID;



public:
	Object();
	Object(Model* model, Shader* shader, GLint objectID = 0);

	Shader* getShader();
	void draw();
	glm::mat4* getMatrix();
	GLint getObjectID();


};

