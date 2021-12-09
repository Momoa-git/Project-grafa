#include "ModelManager.h"

ModelManager* ModelManager::instance = 0;

ModelManager::ModelManager() {
	
};

ModelManager* ModelManager::getInstance()
{
	if (instance == 0)
	{
		instance = new ModelManager();
	}

	return instance;
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

