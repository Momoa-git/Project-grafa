#include "Object.h"
Object::Object(){

}


Object::Object(Model* model, Shader* shader)
{
	this->model = model;
	this->shader = shader;
	this->transMat = glm::mat4(1.0f);
	this->idModelTransform = glGetUniformLocation(this->shader->getShader(), "modelMatrix");

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

Shader* Object::getShader()
{
	return this->shader;
}

glm::mat4* Object::getMatrix()
{
	return &this->transMat;
}


