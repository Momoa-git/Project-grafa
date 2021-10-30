#pragma once

#include <stdexcept>
#include <glm/vec4.hpp>
#include <memory>
#include "Window.h"
#include "Scene.h"

class Engine {
private:
	Window* window;
	static Engine* instance;
	std::vector <Scene*> vecScenes;
	Scene* scene;
	Engine();

public:
	void init();

	void startRendering();

	void onKey(int key, int scancode, int action, int mods);
	void onMove(double x, double y);
	void onClick(int button, int action, double x, double y);
	void nextScene();
	void previousScene();

	void processHeldKeys();

	Window* getWindow();

	static Engine* getInstance();

	//Scene *getScene();



};
