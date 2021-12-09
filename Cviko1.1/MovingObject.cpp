#include "MovingObject.h"
MovingObject::MovingObject(Model* model, Shader* shader, GLint objectID) : Object(model, shader, objectID)
{
	this->way = Way();
}

void MovingObject::draw()
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
