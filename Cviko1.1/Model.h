#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Texture.h"
#include "BuilderModel.h"


#include "VAO.h"
#include "VBO.h"

class BuilderModel;

class Model
{
private:
	int point;
	int lineLen;
	VAO* vao;
	VBO* vbo;
	GLenum pointsType;

public:
	Texture* texture;
	friend class BuilderModel;
	Model(GLboolean bit, const GLfloat* points, int size, int lineLen, int vecLen = 3, int uniformCount = 0, GLenum pointsType = GL_TRIANGLES);
	Model(const GLfloat* points, int pointNo, int lineLen);
	VAO* getVAO();
	VBO* getVBO();
	int getPointsLen();

	static BuilderModel create(const GLfloat* points, GLint pointNo, GLint lineLen);

	GLenum getpointsType();
	void setTexture(Texture* texture);

};
