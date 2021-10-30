#include "Scene.h"
#include "Transformation.h"

Scene::Scene(int sceneCount) {
	currentCam = nullptr;
	lightPosition = glm::vec3(0.0f, 0.0f, 0.0);
	this->sceneCount = sceneCount;
}
void Scene::setLightPosition(glm::vec3 lightPosition)
{
	this->lightPosition = lightPosition;

}

void Scene::draw(GLfloat timeDelta) 
{
	for (Object* element : objects)
	{
		glUniform3fv(glGetUniformLocation(element->getShader()->getShader(), "lightPos"), 1, glm::value_ptr(this->lightPosition));

		element->draw();
		//Transformation::rotate(element->getMatrix(), 0.02f, glm::vec3(0.0f, 1.0f, 0.0f));

	}
}
Camera* Scene::getCurrentCam()
{
	return this->currentCam;
}
void Scene::addCamera(Camera* cam, GLboolean setCurrent) 
{
	cameras.push_back(cam);
	if (setCurrent)
		currentCam = cam;
}
void Scene::addObject(Object* obj) 
{
	objects.push_back(obj);
}

