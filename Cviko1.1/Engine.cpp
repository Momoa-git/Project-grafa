#include "Engine.h"
#include "Fragment_shader.h"
#include "Vertex_shader.h"
#include "Shader.h"
#include "Object.h"
#include "Transformation.h"
#include "Camera.h"
#include "Scene.h"
#include "Models/Cube.h"
#include "Models/CubeWithoutBase.h"
#include "Models/sphere.h"
#include "Models/suzi_flat.h"
#include "Models/suzi_smooth.h"
#include "Models/Tree.h"
#include "Models/plain.h"
#include "Models/gift.h"
#include "Models/bushes.h"
#include "ShaderLoader.h"
#include "FactoryModel.h"
#include "FactoryObject.h"


Engine* Engine::instance = 0;
float deltTime = 0.0f;
float lastFrame = 0.0f;

void Engine::init() {

	glfwSetErrorCallback([](int err, const char* description) -> void {
		throw std::runtime_error(description);
		});

	if (!glfwInit()) {
		throw std::runtime_error("failed to init glfw");
		exit(EXIT_FAILURE);
	}

	window = new Window(800, 600, "EngineInitiatedWindow");

	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

void Engine::startRendering() {

	int sceneCount = 0;



	//glm::mat4 viewMat = glm::lookAt(eye, eye + target, up);
	//glm::mat4 viewMat = glm::lookAt(glm::vec3(0.0f, 1.0f, -5.0f), glm::vec3(0.0f, 1.0f, -5.0f) + glm::vec3(0.0f, -0.3f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//glm::mat4 projMat = glm::perspective(glm::radians(45.0f), 800.f / 600.f, 0.1f, 100.0f);


	glfwSetCursorPos(window->getGLFWWindow(), (window->getWidth() / 2), (window->getHeight() / 2));

/*
	GLuint defaulShaderID = 0;
	GLuint constShaderID = 0;
	GLuint lambertShaderID = 0;
	GLuint phongShaderID = 0;

	new ShaderLoader("vertex_shader.vec", "fragment_shader.frag", &defaulShaderID);
	new ShaderLoader("vertex_shader_const.vec", "fragment_shader_const.frag", &constShaderID);
	new ShaderLoader("vertex_shader_lambert.vec", "fragment_shader_lambert.frag", &lambertShaderID);
	new ShaderLoader("vertex_shader_phong.vec", "fragment_shader_phong.frag", &phongShaderID);
*/


	Shader* defaultShader = new Shader("vertex_shader.vec", "fragment_shader.frag");
	Shader* constShader = new Shader("vertex_shader_const.vec", "fragment_shader_const.frag");
	Shader* lambertShader = new Shader("vertex_shader_lambert.vec", "fragment_shader_lambert.frag");
	Shader* phongShader = new Shader("vertex_shader_phong.vec", "fragment_shader_phong.frag");



	//Object* cube = new Object(new Model(Cube, 20 * (3 + 3), 6, 3, 2, GL_TRIANGLE_STRIP), phongShader);
//	Object* cube2 = new Object(new Model(CubeWithoutBase, 10 * (3 + 3), 6, 3, 2, GL_TRIANGLE_STRIP), phongShader);

	
	FactoryObject* factoryO = new FactoryObject();
	FactoryModel* factoryM = new FactoryModel();

	//Object* koule = factoryO->newObject(factoryM->newModel("sphere"), phongShader);
	
// SCENE BALL
	
	Object* ball_R = factoryO->newObject(factoryM->newModel("sphere"), phongShader);
	Object* ball_L = factoryO->newObject(factoryM->newModel("sphere"), phongShader);
	Object* ball_U = factoryO->newObject(factoryM->newModel("sphere"), phongShader);
	Object* ball_D = factoryO->newObject(factoryM->newModel("sphere"), phongShader);
//	Object* monkey = new Object(new Model(suziSmooth, 2904 * (3 + 3), 6), phongShader);

// SCENE FORREST
	Object* plain = factoryO->newObject(factoryM->newModel("plain"), phongShader);
	Transformation::translate(plain->getMatrix(), glm::vec3(7.0f, 0.0f, -11.0f));
	Transformation::scale(plain->getMatrix(), glm::vec3(20.0f, 10.0f, 20.0f));
	Object* tree = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree->getMatrix(), glm::vec3(3.0f, 0.0f, -7.0f));
	Object* tree2 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree2->getMatrix(), glm::vec3(7.0f, 0.0f, -5.0f));
	Object* tree3 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree3->getMatrix(), glm::vec3(6.0f, 0.0f, -10.0f));
	Object* tree4 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree4->getMatrix(), glm::vec3(10.0f, 0.0f, -8.0f));
	Object* tree5 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree5->getMatrix(), glm::vec3(5.0f, 0.0f, -13.0f));
	Object* tree6 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree6->getMatrix(), glm::vec3(12.0f, 0.0f, -13.0f));
	Object* tree7 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree7->getMatrix(), glm::vec3(8.0f, 0.0f, -2.0f));
	Object* tree8 = factoryO->newObject(factoryM->newModel("tree"), phongShader);
	Transformation::translate(tree8->getMatrix(), glm::vec3(11.0f, 0.0f, -3.0f));



	Object* bushes1 = factoryO->newObject(factoryM->newModel("bushes"), phongShader);
	Transformation::translate(bushes1->getMatrix(), glm::vec3(1.0f, 0.0f, -2.0f));
	Transformation::scale(bushes1->getMatrix(), glm::vec3(1.0f, 1.0f, 1.0f));
	Object* bushes2 = factoryO->newObject(factoryM->newModel("bushes"), phongShader);
	Transformation::translate(bushes2->getMatrix(), glm::vec3(0.4f, 0.0f, -2.5f));
	Object* bushes3 = factoryO->newObject(factoryM->newModel("bushes"), phongShader);
	Transformation::translate(bushes3->getMatrix(), glm::vec3(1.4f, 0.0f, -1.6f));
	Object* bushes4 = factoryO->newObject(factoryM->newModel("bushes"), phongShader);
	Transformation::translate(bushes4->getMatrix(), glm::vec3(0.4f, 0.0f, -1.7f));
	Object* bushes5 = factoryO->newObject(factoryM->newModel("bushes"), phongShader);
	Transformation::translate(bushes5->getMatrix(), glm::vec3(1.3f, 0.0f, -2.4f));
	Object* bushes6 = factoryO->newObject(factoryM->newModel("bushes"), phongShader);
	Transformation::translate(bushes6->getMatrix(), glm::vec3(0.6f, 0.0f, -1.5f));



//SCENE CHRISTMAS TREE
	Object* plain2 = factoryO->newObject(factoryM->newModel("plain"), phongShader);
	Transformation::scale(plain2->getMatrix(), glm::vec3(10.0f, 10.0f, 10.0f));
	Object* treeCH = factoryO->newObject(factoryM->newModel("tree"), lambertShader);

	/*
	Object* gift = factoryO->newObject(new Model(gift_plain, 92814 * (3 + 3), 6), defaultShader);
	Object* gift2 = factoryO->newObject(new Model(gift_plain, 92814 * (3 + 3), 6), defaultShader);
	Object* gift3 = factoryO->newObject(new Model(gift_plain, 92814 * (3 + 3), 6), defaultShader);
	Object* gift4 = factoryO->newObject(new Model(gift_plain, 92814 * (3 + 3), 6), defaultShader);
	
	*/

	Camera* camera = new Camera(window->getWidth(), window->getHeight(), glm::vec3(0.0f, 0.0f, 8.0f));
	camera->Attach(defaultShader);
	camera->Attach(constShader);
	camera->Attach(lambertShader);
	camera->Attach(phongShader);
	


	Scene* sceneBall = new Scene(sceneCount);
	sceneCount++;
	sceneBall->addCamera(camera);
	sceneBall->addObject(ball_R);
	sceneBall->addObject(ball_L);
	sceneBall->addObject(ball_U);
	sceneBall->addObject(ball_D);
	vecScenes.push_back(sceneBall);
	

	
	Scene* forrest = new Scene(sceneCount);
	sceneCount++;
	forrest->addCamera(camera);
	forrest->addObject(plain);
	forrest->addObject(tree);
	forrest->addObject(tree2);
	forrest->addObject(tree3);
	forrest->addObject(tree4);
	forrest->addObject(tree5);
	forrest->addObject(tree6);
	forrest->addObject(tree7);
	forrest->addObject(tree8);
	forrest->addObject(bushes1);
	forrest->addObject(bushes2);
	forrest->addObject(bushes3);
	forrest->addObject(bushes4);
	forrest->addObject(bushes5);
	forrest->addObject(bushes6);
	forrest->setLightPosition(glm::vec3(0.0f, 8.0f, 0.0));
	//forrest->AddObject(gift2);
	//forrest->AddObject(gift3);
	//forrest->AddObject(gift4);
	vecScenes.push_back(forrest);
	
	Scene* christmasTree = new Scene(sceneCount);
	sceneCount++;
	christmasTree->addCamera(camera);
	christmasTree->addObject(plain2);
	christmasTree->addObject(treeCH);
	christmasTree->setLightPosition(glm::vec3(0.0f, 8.0f, 0.0));
	vecScenes.push_back(christmasTree);

	
/*
	//Transformation::translate(cube->getMatrix(), glm::vec3(-1.5f, 0.5f, 0.0f));
	//Transformation::translate(cube2->getMatrix(), glm::vec3(1.5f, -1.0f, 0.0f))
	*/
	Transformation::translate(ball_R->getMatrix(), glm::vec3(2.0f, 0.0f, -1.0f));
	Transformation::translate(ball_L->getMatrix(), glm::vec3(-2.0f, 0.0f, -1.0f));
	Transformation::translate(ball_U->getMatrix(), glm::vec3(0.0f, 2.0f, -1.0f));
	Transformation::translate(ball_D->getMatrix(), glm::vec3(0.0f, -2.0f, -1.0f));
	//Transformation::translate(monkey->getMatrix(), glm::vec3(0.0f, 0.0f, -10.0f));


	//Transformation::translate(gift->getMatrix(), glm::vec3(12.0f, 0.0f, -14.0f));
//	Transformation::translate(gift2->getMatrix(), glm::vec3(13.0f, 0.0f, -15.0f));
	//Transformation::translate(gift3->getMatrix(), glm::vec3(11.0f, 0.0f, -15.0f));
//	Transformation::translate(gift4->getMatrix(), glm::vec3(12.8f, 0.0f, -15.6f));
	

	
	
	scene = vecScenes.back();
	glEnable(GL_DEPTH_TEST);

	scene->getCurrentCam()->Notify();
	while (!glfwWindowShouldClose(this->window->getGLFWWindow())) 
	{
		float currentFrame = glfwGetTime();
		deltTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//scene->getCurrentCam()->UpdateShader(shader->getShader());
		scene->draw(deltTime);

		processHeldKeys();

		

		//Transformation::rotate(cube->getMatrix(), 0.02f, glm::vec3(1.0f, 1.0f, 0.0f));
		//Transformation::rotate(cube2->getMatrix(), 0.01f, glm::vec3(0.0f, 1.0f, 1.0f));
		//Transformation::rotate(ball_R->getMatrix(), 0.01f, glm::vec3(0.0f, 1.0f, 1.0f));
		//Transformation::rotate(monkey->getMatrix(), 0.04f, glm::vec3(0.0f, 1.0f, 0.0f));

			
	// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(this->window->getGLFWWindow());
	}

	glfwDestroyWindow(this->window->getGLFWWindow());
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

Window* Engine::getWindow() {
	return this->window;
}

void Engine::nextScene() {
	GLint nextScene = this->scene->sceneCount + 1;
	if (nextScene >= vecScenes.size())
		nextScene = 0;
	this->scene = vecScenes.at(nextScene);

	printf("change scene %d\n", nextScene);
}

void Engine::onClick(int button, int action, double x, double y) {
	if (action == GLFW_PRESS) {
		printf("press %d %d %f %f\n", button, action, x, y);
	}
	if (action == GLFW_RELEASE) {
		printf("release %d %d %f %f\n", button, action, x, y);
	}
	return;
}

void Engine::onKey(int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		printf("press %d %d %d %d\n", key, scancode, action, mods);
	}
	if (action == GLFW_RELEASE) {
		printf("release %d %d %d %d\n", key, scancode, action, mods);
	}
	if (action == GLFW_PRESS && key == GLFW_KEY_RIGHT)
		this->nextScene();
	return;
}



void Engine::onMove(double x, double y) {
	printf("move %f %f \n", x, y);
	double xmove, ymove;
	xmove = x - (window->getWidth() / 2);
	ymove = y - (window->getHeight() / 2);

	glfwSetCursorPos(window->getGLFWWindow(), (window->getWidth() / 2), (window->getHeight() / 2));

	
	//this->forrest->getCurrentCam()->Rotate(xmove, ymove);
	if (glfwGetMouseButton(window->getGLFWWindow(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		this->scene->getCurrentCam()->Rotate(xmove, ymove);
	}
}

Engine::Engine() {
	init();
}

Engine* Engine::getInstance()
{
	if (instance == 0)
	{
		instance = new Engine();
	}

	return instance;
}

void Engine::processHeldKeys()
{
	

	if (glfwGetKey(window->getGLFWWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		scene->getCurrentCam()->Move(CAM_FORWARD);
	}
	if (glfwGetKey(window->getGLFWWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		scene->getCurrentCam()->Move(CAM_LEFT);
	}
	if (glfwGetKey(window->getGLFWWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		scene->getCurrentCam()->Move(CAM_BACKWARD);
	}
	if (glfwGetKey(window->getGLFWWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		scene->getCurrentCam()->Move(CAM_RIGHT);
	}
	if (glfwGetKey(window->getGLFWWindow(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		scene->getCurrentCam()->Move(CAM_UP);
	}
	if (glfwGetKey(window->getGLFWWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		scene->getCurrentCam()->Move(CAM_DOWN);
	}
	
	
	
}
