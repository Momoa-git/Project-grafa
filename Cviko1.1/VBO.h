#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VBO {
public:
	GLuint id;

	VBO(const GLfloat* points, GLint pointsLen);

	void BindBuffer();
	void ResetBindBuffer();

};
