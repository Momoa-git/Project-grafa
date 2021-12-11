#pragma once
#include "Object.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Lights/PointLight.h"
#include "Lights/DirectionalLight.h"
#include "Lights/SpotLight.h"
#include <vector>
class Scene
{
private:
	//objekty
	std::vector <Object*> objects;
	//svetla
	glm::vec3 lightPosition;
	DirectionalLight dirLight;
	std::vector <SpotLight> spotLights;
	std::vector <PointLight> pointLights;

	Camera* currentCam;
	SkyBox* skybox;
public:
	int sceneCount;
	Scene(int sceneCount);
	void draw();
	Camera* getCurrentCam();
	void addCamera(Camera* cam, GLboolean setCurrent = true);
	void addObject(Object* obj);
	void addPointLight(PointLight);
	void setLightPosition(glm::vec3 lightPosition);
	void setDirLight(DirectionalLight dirLight);
	//void setSpotLight(SpotLight spotLight);
	void addSpotLight(SpotLight);
	void setSkybox(SkyBox* skybox);

};
