#include "Scene.h"
#include "Transformation.h"

Scene::Scene(int sceneCount)
{
	currentCam = nullptr;
	skybox = nullptr;
	//lightPosition = glm::vec3(0.0f, 0.0f, 0.0);
	this->sceneCount = sceneCount;
	this->dirLight = DirectionalLight();
//	this->spotLight = SpotLight();
	
}

void Scene::setLightPosition(glm::vec3 lightPosition)
{
	this->lightPosition = lightPosition;

}

void Scene::draw() 
{
	if (skybox != nullptr)
		skybox->draw();

	for (Object* element : objects)
	{
		//glUniform3fv(glGetUniformLocation(element->getShader()->getShader(), "lightPos"), 1, glm::value_ptr(this->lightPosition));
		/*
		element->getShader()->drawShader();
		dirLight.setAmbientUni(element->getShader()->getUniform("dirLight.ambient"));
		dirLight.setDiffuseUni(element->getShader()->getUniform("dirLight.diffuse"));
		dirLight.setSpecularUni(element->getShader()->getUniform("dirLight.specular"));
		dirLight.setDirectionUni(element->getShader()->getUniform("dirLight.direction"));
		*/
		/*
		element->getShader()->drawShader();
		spotLight.setAmbientUni(element->getShader()->getUniform("flashLight.ambient"));
		spotLight.setDiffuseUni(element->getShader()->getUniform("flashLight.diffuse"));
		spotLight.setSpecularUni(element->getShader()->getUniform("flashLight.specular"));
		spotLight.setDirectionUni(element->getShader()->getUniform("flashLight.direction"));
		spotLight.setPositionUni(element->getShader()->getUniform("flashLight.position"));
		spotLight.setConstant(element->getShader()->getUniform("flashLight.constant"));
		spotLight.setLinear(element->getShader()->getUniform("flashLight.linear"));
		spotLight.setQuadratic(element->getShader()->getUniform("flashLight.quadratic"));
		spotLight.setCutOffUni(element->getShader()->getUniform("flashLight.cutOff"));
		spotLight.setOuterCutOffUni(element->getShader()->getUniform("flashLight.outerCutOff"));
		*/

		element->getShader()->drawShader();
		dirLight.setAmbientUni(element->getShader()->getUniform("dirLight.ambient"));
		dirLight.setDiffuseUni(element->getShader()->getUniform("dirLight.diffuse"));
		dirLight.setSpecularUni(element->getShader()->getUniform("dirLight.specular"));
		dirLight.setDirectionUni(element->getShader()->getUniform("dirLight.direction"));

		for (int i = 0; i < pointLights.size(); i++)
		{
			std::string is = std::to_string(i);
			pointLights.at(i).setAmbientUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].ambient")).c_str())));
			pointLights.at(i).setDiffuseUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].diffuse")).c_str())));
			pointLights.at(i).setSpecularUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].specular")).c_str())));
			pointLights.at(i).setPositionUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].position")).c_str())));
			pointLights.at(i).setConstantUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].constant")).c_str())));
			pointLights.at(i).setLinearUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].linear")).c_str())));
			pointLights.at(i).setQuadraticUni(element->getShader()->getUniform(((std::string("pointLights[") + is + std::string("].quadratic")).c_str())));
		}
		glUniform1i(element->getShader()->getUniform("pointLightsCount"), pointLights.size());

		for (int i = 0; i < spotLights.size(); i++)
		{
			std::string is2 = std::to_string(i);
			spotLights.at(i).setAmbientUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].ambient")).c_str())));
			spotLights.at(i).setDiffuseUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].diffuse")).c_str())));
			spotLights.at(i).setSpecularUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].specular")).c_str())));
			spotLights.at(i).setPositionUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].position")).c_str())));
			spotLights.at(i).setConstantUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].constant")).c_str())));
			spotLights.at(i).setLinearUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].linear")).c_str())));
			spotLights.at(i).setQuadraticUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].quadratic")).c_str())));

			spotLights.at(i).setDirectionUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].direction")).c_str())));
			spotLights.at(i).setCutOffUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].cutOff")).c_str())));
			spotLights.at(i).setOuterCutOffUni(element->getShader()->getUniform(((std::string("spotLights[") + is2 + std::string("].outerCutOff")).c_str())));
		}
		glUniform1i(element->getShader()->getUniform("spotLightsCount"), spotLights.size());


		glUniform3fv(element->getShader()->getUniform("lightPos"), 1, glm::value_ptr(this->lightPosition));

		glStencilFunc(GL_ALWAYS, element->getObjectID(), 0xFF);  //identifikace tìles

		element->draw();
		//Transformation::rotate(element->getMatrix(), 0.02f, glm::vec3(0.0f, 1.0f, 0.0f));

	}
}
Camera* Scene::getCurrentCam()
{
	return this->currentCam;
}
// 
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

void Scene::addPointLight(PointLight pl)
{
	pointLights.push_back(pl);


}

void Scene::addSpotLight(SpotLight sl)
{
	spotLights.push_back(sl);


}

void Scene::setDirLight(DirectionalLight dr)
{
	this->dirLight = dr;
}
/*
void Scene::setSpotLight(SpotLight sl)
{
	this->spotLight = sl;
}*/

void Scene::setSkybox(SkyBox* skybox)
{
	this->skybox = skybox;
	this->currentCam->registerObserver(this->skybox);

}
