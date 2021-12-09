#include "ShaderManager.h"
ShaderManager* ShaderManager::instance = 0;

ShaderManager::ShaderManager() {
}

ShaderManager* ShaderManager::getInstance()
{
	if (instance == 0)
	{
		instance = new ShaderManager();
	}

	return instance;
}

bool ShaderManager::saveShader(Shader* shader, std::string name)
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

Shader* ShaderManager::getShader(std::string name)
{
	for (AssetDetail ad : this->shaders)
		if (ad.name == name)
			return (Shader*)ad.pointer;
}