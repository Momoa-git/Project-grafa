#include "Skybox.h"
#include "Models/Plain_texture.h"
#include "Transformation.h"

SkyBox::SkyBox(Shader* shader, int version) 
{

	Model* bottom = Model::create(plain_texture, 6, 8).positionAttrib(0).texAttrib(6).build();
	Model* top = Model::create(plain_texture, 6, 8).positionAttrib(0).texAttrib(6).build();
	Model* left = Model::create(plain_texture, 6, 8).positionAttrib(0).texAttrib(6).build();
	Model* right = Model::create(plain_texture, 6, 8).positionAttrib(0).texAttrib(6).build();
	Model* front = Model::create(plain_texture, 6, 8).positionAttrib(0).texAttrib(6).build();
	Model* back = Model::create(plain_texture, 6, 8).positionAttrib(0).texAttrib(6).build();

	
	if (version == 1)
	{

		Texture* tex1 = new Texture("./Texture/cubemap/negy.jpg", 0);
		bottom->setTexture(tex1);

		Texture* tex2 = new Texture("./Texture/cubemap/posy.jpg", 0);
		top->setTexture(tex2);

		Texture* tex3 = new Texture("./Texture/cubemap/negx.jpg", 0);
		left->setTexture(tex3);

		Texture* tex4 = new Texture("./Texture/cubemap/posx.jpg", 0);
		right->setTexture(tex4);

		Texture* tex5 = new Texture("./Texture/cubemap/negz.jpg", 0);
		front->setTexture(tex5);
		
		Texture* tex6 = new Texture("./Texture/cubemap/posz.jpg", 0);
		back->setTexture(tex6);

	}
	else 
	{
		Texture* tex1 = new Texture("./Texture/space/negY.jpg", 0);
		bottom->setTexture(tex1);

		Texture* tex2 = new Texture("./Texture/space/posY.jpg", 0);
		top->setTexture(tex2);

		Texture* tex3 = new Texture("./Texture/space/posX.jpg", 0);
		left->setTexture(tex3);

		Texture* tex4 = new Texture("./Texture/space/negX.jpg", 0);
		right->setTexture(tex4);

		Texture* tex5 = new Texture("./Texture/space/negZ.jpg", 0);
		front->setTexture(tex5);

		Texture* tex6 = new Texture("./Texture/space/posZ.jpg", 0);
		back->setTexture(tex6);
	}


	this->setObjects(bottom, top, left, right, front, back, shader);


}
void SkyBox::setObjects(Model* bottom, Model* top, Model* left, Model* right, Model* front, Model* back, Shader* shader)
{
	this->sides[0] = Object(bottom, shader);
	Transformation::translate((&this->sides[0])->getMatrix(), glm::vec3(0.0f, -1.0f, .0f));
	Transformation::rotate((&this->sides[0])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.f, .0f));

	this->sides[1] = Object(top, shader);
	Transformation::translate((&this->sides[1])->getMatrix(), glm::vec3(0.0f, 1.0f, .0f));
	Transformation::rotate((&this->sides[1])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.f, .0f));

	this->sides[2] = Object(left, shader);
	Transformation::translate((&this->sides[2])->getMatrix(), glm::vec3(-1.0f, .0f, .0f));
	Transformation::rotate((&this->sides[2])->getMatrix(), glm::radians(180.f), glm::vec3(1.0f, .0f, .0f));
	Transformation::rotate((&this->sides[2])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, .0f, -1.0f));
	this->sides[3] = Object(right, shader);
	Transformation::translate((&this->sides[3])->getMatrix(), glm::vec3(1.0f, .0f, .0f));
	Transformation::rotate((&this->sides[3])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, .0f, -1.0f));
	this->sides[4] = Object(front, shader);
	Transformation::translate((&this->sides[4])->getMatrix(), glm::vec3(.0f, .0f, -1.0f));
	Transformation::rotate((&this->sides[4])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, 1.0f, .0f));
	Transformation::rotate((&this->sides[4])->getMatrix(), glm::radians(-90.f), glm::vec3(.0f, .0f, 1.0f));
	this->sides[5] = Object(back, shader);
	Transformation::translate((&this->sides[5])->getMatrix(), glm::vec3(.0f, .0f, 1.0f));
	Transformation::rotate((&this->sides[5])->getMatrix(), glm::radians(90.f), glm::vec3(1.0f, .0f, .0f));
	Transformation::rotate((&this->sides[5])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.0f, .0f));

}


void SkyBox::draw() {

	for (int i = 0; i < 6; i++)
	{
		this->sides[i].draw();
	}
	glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void SkyBox::update(glm::vec3 position)
{
		this->position = position;

		for (int i = 0; i < 6; i++)
		{
			//(&this->sides[i])->getMatrix() = glm::mat4(1.0);
			Transformation::resetMat((&this->sides[i])->getMatrix());
		}

		//Transformation::rotate((&this->sides[0])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, 1.f, .0f));
		Transformation::translate((&this->sides[0])->getMatrix(), position);
		Transformation::translate((&this->sides[0])->getMatrix(), glm::vec3(0.0f, -1.0f, .0f));
		Transformation::rotate((&this->sides[0])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.f, .0f));

		//Transformation::rotate((&this->sides[1])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, 1.f, .0f));
		Transformation::translate((&this->sides[1])->getMatrix(), position);
		Transformation::translate((&this->sides[1])->getMatrix(), glm::vec3(0.0f, 1.0f, .0f));
		Transformation::rotate((&this->sides[1])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.f, .0f));

		//Transformation::rotate((&this->sides[2])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, .0f, -1.0f));
		//Transformation::rotate((&this->sides[2])->getMatrix(), glm::radians(-180.f), glm::vec3(1.0f, .0f, .0f));
		Transformation::translate((&this->sides[2])->getMatrix(), position);
		Transformation::translate((&this->sides[2])->getMatrix(), glm::vec3(-1.0f, .0f, .0f));
		Transformation::rotate((&this->sides[2])->getMatrix(), glm::radians(180.f), glm::vec3(1.0f, .0f, .0f));
		Transformation::rotate((&this->sides[2])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, .0f, -1.0f));

		//Transformation::rotate((&this->sides[3])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, .0f, -1.0f));
		Transformation::translate((&this->sides[3])->getMatrix(), position);
		Transformation::translate((&this->sides[3])->getMatrix(), glm::vec3(1.0f, .0f, .0f));
		Transformation::rotate((&this->sides[3])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, .0f, -1.0f));

		//Transformation::rotate((&this->sides[4])->getMatrix(), glm::radians(90.f), glm::vec3(.0f, .0f, 1.0f));
		//Transformation::rotate((&this->sides[4])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.0f, .0f));
		Transformation::translate((&this->sides[4])->getMatrix(), position);
		Transformation::translate((&this->sides[4])->getMatrix(), glm::vec3(.0f, .0f, -1.0f));
		Transformation::rotate((&this->sides[4])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, 1.0f, .0f));
		Transformation::rotate((&this->sides[4])->getMatrix(), glm::radians(-90.f), glm::vec3(.0f, .0f, 1.0f));

	//	Transformation::rotate((&this->sides[5])->getMatrix(), glm::radians(90.f), glm::vec3(0.0f, 1.0f, .0f));
		//Transformation::rotate((&this->sides[5])->getMatrix(), glm::radians(-90.f), glm::vec3(1.0f, .0f, .0f));
		Transformation::translate((&this->sides[5])->getMatrix(), position);
		Transformation::translate((&this->sides[5])->getMatrix(), glm::vec3(.0f, .0f, 1.0f));
		Transformation::rotate((&this->sides[5])->getMatrix(), glm::radians(90.f), glm::vec3(1.0f, .0f, .0f));
		Transformation::rotate((&this->sides[5])->getMatrix(), glm::radians(-90.f), glm::vec3(0.0f, 1.0f, .0f));
		
	
}