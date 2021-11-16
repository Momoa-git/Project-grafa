#include "Model.h"

Model::Model(GLboolean bit,const GLfloat* points, int size, int lineLen, int vecLen, int uniformCount, GLenum pointsType)
{
	
	this->texture = nullptr;
	point = size / lineLen;
	this->pointsType = pointsType;
	
	//layoutCOunt
	int top = 0;

	if (uniformCount == 0)
		top = lineLen / vecLen;
	else
		top = uniformCount;

	vbo = new VBO(points, size);
	vao = new VAO();
	vao->BindBuffer();
	for (int i = 0; i < top; i++) 
	{
		vao->setAttribute(*vbo, i, vecLen, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(i * vecLen * sizeof(GL_FLOAT)));
	}
	vao->ResetBindBuffer();
	vbo->ResetBindBuffer();

}

Model::Model(const GLfloat* points, int pointNo, int lineLen) {
	this->texture = nullptr;
	this->point = pointNo;
	this->lineLen = lineLen;
	this->pointsType = GL_TRIANGLES;
	vbo = new VBO(points, pointNo * lineLen);
	vao = new VAO();
	vao->BindBuffer();
}


VBO* Model::getVBO()
{
	return vbo;

}

VAO* Model::getVAO()
{
	return vao;

}

GLenum Model::getpointsType()
{
	return pointsType;
}

int Model::getPointsLen()
{
	return point;

}

void Model::setTexture(Texture* texture)
{
	this->texture = texture;
}

BuilderModel Model::create(const GLfloat* points, GLint pointNo, GLint lineLen) {
	return BuilderModel(points, pointNo, lineLen);
}