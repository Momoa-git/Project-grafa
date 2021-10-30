#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VBO.h"

class VAO {
public:

	GLuint id;

	VAO();

	void setAttribute(VBO& VBO, GLuint layout, int pointsLen, GLenum dataType,  GLsizeiptr stride, void* offset);

	void BindBuffer();
	void ResetBindBuffer();

};
