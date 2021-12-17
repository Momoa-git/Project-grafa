#include "Object.h"
Object::Object(){

}


Object::Object(Model* model, Shader* shader, GLint objectID)
{
	this->model = model;
	this->shader = shader;
	this->transMat = glm::mat4(1.0f);
	//this->idModelTransform = glGetUniformLocation(this->shader->getShader(), "modelMatrix");
	this->idModelTransform = this->shader->getUniform("modelMatrix");
	this->objectID = objectID;
}
// nastavi shader, shaderu se hodi trans matice
void Object::draw()
{
	shader->drawShader();
	glUniformMatrix4fv(this->idModelTransform, 1, GL_FALSE, &this->transMat[0][0]);
	this->model->getVAO()->BindBuffer();

	if (this->model->texture != nullptr)
		this->model->texture->useTexture(shader);

	// draw triangles
	glDrawArrays(model->getpointsType(), 0, model->getPointsLen());


}
/*
void Object::draww()
{
	Transformation::resetMat(this->getMatrix());
	Transformation::translate(this->getMatrix(), this->way.getNextControlPoint(0.0015f));

	shader->drawShader();
	glUniformMatrix4fv(this->idModelTransform, 1, GL_FALSE, &this->transMat[0][0]);
	//glUniform4fv(shader->getUniform("in_colour"), 1, glm::value_ptr(this->color));

	if (this->model->texture != nullptr) {
		this->model->texture->useTexture(shader);
	}
	this->model->getVAO()->BindBuffer();
	glDrawArrays(model->getpointsType(), 0, model->getPointsLen());
}
*/

Shader* Object::getShader()
{
	return this->shader;
}

glm::mat4* Object::getMatrix()
{
	return &this->transMat;
}

GLint Object::getObjectID()
{
	return this->objectID;
}


