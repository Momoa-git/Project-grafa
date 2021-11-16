#include "BuilderModel.h"
BuilderModel::BuilderModel(const GLfloat* points, int pointNo, int lineLen) {
	this->model = new Model(points, pointNo, lineLen);
}

BuilderModel BuilderModel::positionAttrib(GLint at) {
	this->model->vao->BindBuffer();
	this->model->vao->setAttribute(*this->model->vbo, 0, 3, GL_FLOAT, this->model->lineLen * sizeof(GL_FLOAT), (GLvoid*)(at * sizeof(GL_FLOAT)));
	this->model->vao->ResetBindBuffer();
	return *this;
}
BuilderModel BuilderModel::normalAttrib(GLint at) {
	this->model->vao->BindBuffer();
	this->model->vao->setAttribute(*this->model->vbo, 1, 3, GL_FLOAT, this->model->lineLen * sizeof(GL_FLOAT), (GLvoid*)(at * sizeof(GL_FLOAT)));
	this->model->vao->ResetBindBuffer();
	return *this;
}
BuilderModel BuilderModel::texAttrib(GLint at) {
	this->model->vao->BindBuffer();
	this->model->vao->setAttribute(*this->model->vbo, 3, 2, GL_FLOAT, this->model->lineLen * sizeof(GL_FLOAT), (GLvoid*)(at * sizeof(GL_FLOAT)));
	this->model->vao->ResetBindBuffer();
	return *this;
}
BuilderModel BuilderModel::colorAttrib(GLint at, GLboolean alpha) {
	this->model->vao->BindBuffer();
	GLint componentNo;
	if (alpha)
		componentNo = 4;
	else
		componentNo = 3;
	this->model->vao->setAttribute(*this->model->vbo, 2, componentNo, GL_FLOAT, this->model->lineLen * sizeof(GL_FLOAT), (GLvoid*)(at * sizeof(GL_FLOAT)));
	this->model->vao->ResetBindBuffer();
	return *this;
}
Model* BuilderModel::build() {
	this->model->vao->ResetBindBuffer();
	this->model->vbo->ResetBindBuffer();
	return this->model;
}