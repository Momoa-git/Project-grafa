#pragma once
#include "Object.h"
#include "Camera.h"
#include <vector>
class Scene
{
private:
	std::vector <Object*> objects;
	std::vector <Camera*> cameras;
	glm::vec3 lightPosition;
	Camera* currentCam;
public:
	int sceneCount;
	Scene(int sceneCount);
	void draw(GLfloat timeDelta);
	Camera* getCurrentCam();
	void addCamera(Camera* cam, GLboolean setCurrent = true);
	void addObject(Object* obj);
	void setLightPosition(glm::vec3 lightPosition);

};
