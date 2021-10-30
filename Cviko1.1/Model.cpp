#include "Model.h"

Model::Model(const GLfloat* points, int size, int lineLen, int vecLen, int uniformCount, GLenum pointsType)
{
	point = size / lineLen;
	this->pointsType = pointsType;
	vbo = new VBO(points, size);

	int i_top = 0;

	if (uniformCount == 0)
		i_top = lineLen / vecLen;
	else
		i_top = uniformCount;


	vao = new VAO();
	vao->BindBuffer();
	for (int i = 0; i < i_top; i++) {
		vao->setAttribute(*vbo, i, vecLen, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(i * vecLen * sizeof(GL_FLOAT)));
	}
	vao->ResetBindBuffer();
	vbo->ResetBindBuffer();

}
VAO* Model::getVAO()
{
	return vao;

}

VBO* Model::getVBO()
{
	return vbo;

}

int Model::getPointsLen()
{
	return point;

}
GLenum Model::getpointsType()
{
	return pointsType;
}
