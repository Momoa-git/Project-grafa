#pragma once
#include "Model.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Model;
class BuilderModel
{
private:
	Model* model;
public:
	BuilderModel(const GLfloat* points, int pointNo, int lineLen);
	BuilderModel(const char* data);
	BuilderModel mode(GLenum mode);
	BuilderModel positionAttrib(GLint at);
	BuilderModel normalAttrib(GLint at);
	BuilderModel texAttrib(GLint at);
	BuilderModel colorAttrib(GLint at, GLboolean alpha = 0);
	Model* build();
};