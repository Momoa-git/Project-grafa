#pragma once

#include <stdexcept>
#include <glm/vec4.hpp>
#include <memory>
#include <assimp/Importer.hpp>#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Window.h"
#include "Scene.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "Controller.h"

class Engine {
private:
	static Engine* instance;
	std::vector <Scene*> vecScenes;
	//Window* window;
	Window* window;
	Scene* scene;
	Controller* controller;

	Engine();

public:
	ModelManager* modelManager;
	ShaderManager* shaderManager;
	int index = 0;

	void init();

	void getInstanceManagers();
	void initShaders();
	void startRendering();
/*
	void onKey(int key, int scancode, int action, int mods);
	void onMove(double x, double y);
	void onClick(int button, int action, double x, double y);*/
	void nextScene();
	void previousScene();
	GLint getIndex();

//	void processHeldKeys();


	Window* getWindow();
	Scene* getScene();
	Controller* getController();

	static Engine* getInstance();





};
