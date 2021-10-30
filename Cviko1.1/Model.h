#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VAO.h"
#include "VBO.h"

class Model
{
private:
	int point;
	VAO* vao;
	VBO* vbo;
	GLenum pointsType;

public:
	Model(const GLfloat* points, int size, int lineLen, int vecLen = 3, int uniformCount = 0, GLenum pointsType = GL_TRIANGLES);

	VAO* getVAO();
	VBO* getVBO();
	int getPointsLen();

	GLenum getpointsType();

};
