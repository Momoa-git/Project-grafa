#include "ModelManager.h"

ModelManager* ModelManager::instance = 0;

ModelManager::ModelManager() {
	init();
};

ModelManager* ModelManager::getInstance()
{
	if (instance == 0)
	{
		instance = new ModelManager();
	}

	return instance;
}

void ModelManager::init()
{
	
}

bool ModelManager::saveModel(Model* model, std::string name)
{
	for(AssetDetail ad : this->models)
		if (ad.name == name)
		{
			return false;
		}

	AssetDetail assetToPush;
	assetToPush.name = name;
	assetToPush.pointer = (void*)model;
	this->models.push_back(assetToPush);
	return true;
}

Model* ModelManager::getModel(std::string name)
{
	for (AssetDetail ad : this->models)
		if (ad.name == name)
			return (Model*)ad.pointer;
}

bool ModelManager::saveShader(Shader* shader, std::string name)
{
	for (AssetDetail ad : this->shaders)
		if (ad.name == name)
		{
			return false;
		}

	AssetDetail assetToPush;
	assetToPush.name = name;
	assetToPush.pointer = (void*)shader;
	this->shaders.push_back(assetToPush);
	return true;
}

Shader* ModelManager::getShader(std::string name)
{
	for (AssetDetail ad : this->shaders)
		if (ad.name == name)
			return (Shader*)ad.pointer;
}