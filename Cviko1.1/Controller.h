#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <glm/vec4.hpp>
#include <memory>
#include <assimp/Importer.hpp>#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Engine.h"
class Window;

class Controller
{
private:
	//ModelManager* modelmanager;

public:
	Controller();
	void onKey(int key, int scancode, int action, int mods);
	void onMove(double x, double y);
	void onClick(int button, int action, double x, double y);
	void processHeldKeys();
};

