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

class ShaderManager
{
private:
	static ShaderManager* instance;
	std::vector<AssetDetail> shaders;
	ShaderManager();
public:
	static ShaderManager* getInstance();

	bool saveShader(Shader* shader, std::string name);
	Shader* getShader(std::string name);


};

