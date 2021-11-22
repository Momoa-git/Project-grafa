#pragma once
#include "Object.h"
#include "Camera.h"
#include "SkyBox.h"
#include <vector>
class Scene
{
private:
	std::vector <Object*> objects;
	std::vector <Camera*> cameras;
	glm::vec3 lightPosition;
	Camera* currentCam;
	SkyBox* skybox;
public:
	int sceneCount;
	Scene(int sceneCount);
	void draw();
	Camera* getCurrentCam();
	void addCamera(Camera* cam, GLboolean setCurrent = true);
	void addObject(Object* obj);
	void setLightPosition(glm::vec3 lightPosition);
	void setSkybox(SkyBox* skybox);

};
