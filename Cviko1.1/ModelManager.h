#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include <string>
#include "AssetDetail.h"
#include "Model.h"
#include "FactoryModel.h"
#include "FactoryObject.h"

class ModelManager
{
private:
	static ModelManager* instance;
	std::vector<AssetDetail> models;
	std::vector<AssetDetail> shaders;
	ModelManager();
	
public:
	void init();
	static ModelManager* getInstance();
	bool saveModel(Model* model, std::string name);
	Model* getModel(std::string name);

	bool saveShader(Shader* shader, std::string name);
	Shader* getShader(std::string name);


};

