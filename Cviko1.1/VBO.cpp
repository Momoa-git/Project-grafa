#include "VBO.h"

VBO::VBO(const GLfloat* points, GLint pointsLen)
{
	id = 0;
	glGenBuffers(1, &id); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points) * pointsLen, points, GL_STATIC_DRAW);

}

void VBO::BindBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::ResetBindBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
