#include "VBO.h"

VBO::VBO(const GLfloat* points, GLint pointsLen)
{
	id = 0;
	glGenBuffers(1, &id); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points) * pointsLen, points, GL_STATIC_DRAW);

}

VBO::VBO(std::vector<float> data)
{
	id = 0;
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

}


void VBO::BindBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::ResetBindBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
