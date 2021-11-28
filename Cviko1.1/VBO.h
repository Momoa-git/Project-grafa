#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class VBO {
public:
	GLuint id;

	VBO(const GLfloat* points, GLint pointsLen);
	VBO(std::vector<float> data);

	void BindBuffer();
	void ResetBindBuffer();

};
