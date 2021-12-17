#include "Engine.h"
#include "Fragment_shader.h"
#include "Vertex_shader.h"
#include "Shader.h"
#include "Object.h"
#include "Transformation.h"
#include "Camera.h"
#include "Scene.h"
#include "SkyBox.h"
#include "ShaderLoader.h"
#include "FactoryModel.h"
#include "FactoryObject.h"
#include "MovingObject.h"
#include "Controller.h"


Engine* Engine::instance = 0;
GLint objectCounter = 1;

//FactoryObject* factoryO = new FactoryObject();
//FactoryModel* factoryM = new FactoryModel();


Engine::Engine()
{
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

void Engine::init() {

	glfwSetErrorCallback([](int err, const char* description) -> void {
		throw std::runtime_error(description);
		});

	if (!glfwInit()) {
		throw std::runtime_error("failed to init glfw");
		exit(EXIT_FAILURE);
	}
	controller = new Controller();
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

void Engine::getInstanceManagers()
{
	this->modelManager = ModelManager::getInstance();
	this->shaderManager = ShaderManager::getInstance();
}


void Engine::initShaders()
{ 
	Shader* defaultShader = new Shader("vertex_shader.vec", "fragment_shader.frag");
	Shader* constShader = new Shader("vertex_shader_const.vec", "fragment_shader_const.frag");
	Shader* lambertShader = new Shader("vertex_shader_lambert.vec", "fragment_shader_lambert.frag");
	Shader* phongShader = new Shader("vertex_shader_phong.vec", "fragment_shader_phong.frag");
	Shader* phongTextureShader = new Shader("vertex_shader_phong_texture.vec", "fragment_shader_phong_texture.frag");
	Shader* textureShader = new Shader("vertex_shader_texture.vec", "fragment_shader_texture.frag");
	Shader* lightShader = new Shader("vertex_shader_light.vec", "fragment_shader_light.frag");

	this->shaderManager->saveShader(defaultShader, "default");
	this->shaderManager->saveShader(constShader, "const");
	this->shaderManager->saveShader(lambertShader, "lambert");
	this->shaderManager->saveShader(phongShader, "phong");
	this->shaderManager->saveShader(phongTextureShader, "phong-texture");
	this->shaderManager->saveShader(textureShader, "texture");
	this->shaderManager->saveShader(lightShader, "light");
	
}



void Engine::startRendering() {

	int sceneCount = 0;
	
	Camera* camera = new Camera(window->getWidth(), window->getHeight(), glm::vec3(0.0f, 0.0f, 8.0f));
	camera->registerObserver(shaderManager->getShader("default"));
	camera->registerObserver(shaderManager->getShader("const"));
	camera->registerObserver(shaderManager->getShader("lambert"));
	camera->registerObserver(shaderManager->getShader("phong"));
	camera->registerObserver(shaderManager->getShader("phong-texture"));
	camera->registerObserver(shaderManager->getShader("texture"));
	camera->registerObserver(shaderManager->getShader("light"));

	
	FactoryObject* factoryO = new FactoryObject();
	FactoryModel* factoryM = new FactoryModel();


	modelManager->saveModel(factoryM->newModel("addingTree"), "addingTree");

// SCENE BALL

	SkyBox* skybox = new SkyBox(shaderManager->getShader("texture"), 1);
	
	Object* ball_R = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Object* ball_L = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Object* ball_U = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Object* ball_D = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
//	Object* monkey = new Object(new Model(suziSmooth, 2904 * (3 + 3), 6), phongShader);
	//Object* test = factoryO->newObject(factoryM->newModel("plainTexture"), testShader);



// SCENE FORREST
	Object* plain = factoryO->newObject(factoryM->newModel("plainTexture"), shaderManager->getShader("phong-texture"));
	Transformation::translate(plain->getMatrix(), glm::vec3(7.0f, 0.0f, -11.0f));
	Transformation::scale(plain->getMatrix(), glm::vec3(20.0f, 10.0f, 20.0f));

	Object* tree = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree->getMatrix(), glm::vec3(3.0f, 0.0f, -7.0f));

	Object* tree2 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree2->getMatrix(), glm::vec3(7.0f, 0.0f, -5.0f));
	Object* tree3 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree3->getMatrix(), glm::vec3(6.0f, 0.0f, -10.0f));
	Object* tree4 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree4->getMatrix(), glm::vec3(10.0f, 0.0f, -8.0f));
	Object* tree5 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree5->getMatrix(), glm::vec3(5.0f, 0.0f, -13.0f));
	Object* tree6 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree6->getMatrix(), glm::vec3(12.0f, 0.0f, -13.0f));
	Object* tree7 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree7->getMatrix(), glm::vec3(8.0f, 0.0f, -2.0f));
	Object* tree8 = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("phong"));
	Transformation::translate(tree8->getMatrix(), glm::vec3(11.0f, 0.0f, -3.0f));

	Object* bushes1 = factoryO->newObject(factoryM->newModel("bushes"), shaderManager->getShader("phong"));
	Transformation::translate(bushes1->getMatrix(), glm::vec3(1.0f, 0.0f, -2.0f));
	Transformation::scale(bushes1->getMatrix(), glm::vec3(1.0f, 1.0f, 1.0f));
	Object* bushes2 = factoryO->newObject(factoryM->newModel("bushes"), shaderManager->getShader("phong"));
	Transformation::translate(bushes2->getMatrix(), glm::vec3(0.4f, 0.0f, -2.5f));
	Object* bushes3 = factoryO->newObject(factoryM->newModel("bushes"), shaderManager->getShader("phong"));
	Transformation::translate(bushes3->getMatrix(), glm::vec3(1.4f, 0.0f, -1.6f));
	Object* bushes4 = factoryO->newObject(factoryM->newModel("bushes"), shaderManager->getShader("phong"));
	Transformation::translate(bushes4->getMatrix(), glm::vec3(0.4f, 0.0f, -1.7f));
	Object* bushes5 = factoryO->newObject(factoryM->newModel("bushes"), shaderManager->getShader("phong"));
	Transformation::translate(bushes5->getMatrix(), glm::vec3(1.3f, 0.0f, -2.4f));
	Object* bushes6 = factoryO->newObject(factoryM->newModel("bushes"), shaderManager->getShader("phong"));
	Transformation::translate(bushes6->getMatrix(), glm::vec3(0.6f, 0.0f, -1.5f));

// LIGHTS SCENE
	Object* plainLight = factoryO->newObject(factoryM->newModel("plainTexture"), shaderManager->getShader("light"));
	Transformation::translate(plainLight->getMatrix(), glm::vec3(7.0f, 0.0f, -11.0f));
	Transformation::scale(plainLight->getMatrix(), glm::vec3(20.0f, 10.0f, 20.0f));
    
// BUILDING SCENE
	GLint objectID = 1;
	Object* building = factoryO->newObject(factoryM->newModel("house"), shaderManager->getShader("light"));
	Object* plainGrass = factoryO->newObjectWithID(factoryM->newModel("plainGrass"), shaderManager->getShader("light"), objectID);
	//index = getIndex();

	MovingObject* zombie = new MovingObject(factoryM->newModel("zombie"), shaderManager->getShader("light"));
	zombie->way.addControlPoint(glm::vec3(-20.f, 0.f, -10.f));
	zombie->way.addControlPoint(glm::vec3(-10.f, 0.f, -20.f));
	zombie->way.addControlPoint(glm::vec3(30.f, 0.f, -10.f));
	zombie->way.addControlPoint(glm::vec3(60.f, 0.f, 0.f));
	zombie->way.addControlPoint(glm::vec3(30.f, 0.f, 10.f));
	zombie->way.addControlPoint(glm::vec3(-10.f, 0.f, 20.f));
	zombie->way.addControlPoint(glm::vec3(-20.f, 0.f, 10.f));

	Object* start = factoryO->newObject(factoryM->newModel("redSphere"), shaderManager->getShader("light"));
	Transformation::translate(start->getMatrix(), glm::vec3(-20.0f, 0.0f, -10.0f));

	Object* check1 = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Transformation::translate(check1->getMatrix(), glm::vec3(-10.0f, 2.0f, -20.0f));

	Object* check2 = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Transformation::translate(check2->getMatrix(), glm::vec3(30.0f, 0.0f, -10.0f));

	Object* check3 = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Transformation::translate(check3->getMatrix(), glm::vec3(60.0f, 10.0f, 0.0f));

	Object* check4 = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Transformation::translate(check4->getMatrix(), glm::vec3(30.0f, 0.0f, 10.0f));

	Object* check5 = factoryO->newObject(factoryM->newModel("sphere"), shaderManager->getShader("phong"));
	Transformation::translate(check5->getMatrix(), glm::vec3(-10.0f, 0.0f, 20.0f));

	Object* finish = factoryO->newObject(factoryM->newModel("redSphere"), shaderManager->getShader("light"));
	Transformation::translate(finish->getMatrix(), glm::vec3(-20.0f, 0.0f, 10.0f));
// SPACE SCENE
	SkyBox* skybox_space = new SkyBox(shaderManager->getShader("texture"), 2);
	Object* planet_earth = factoryO->newObject(factoryM->newModel("earth"), shaderManager->getShader("light"));


	Scene* sceneBall = new Scene(sceneCount);
	sceneCount++;
	sceneBall->addCamera(camera);
	sceneBall->addObject(ball_R);
	sceneBall->addObject(ball_L);
	sceneBall->addObject(ball_U);
	sceneBall->addObject(ball_D);
	sceneBall->setSkybox(skybox);
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
	vecScenes.push_back(forrest);
	
//Light scenes
	Scene* pointLightScene = new Scene(sceneCount);
	sceneCount++;
	pointLightScene->addCamera(camera);
	pointLightScene->addObject(plainLight);
	pointLightScene->addPointLight(PointLight(glm::vec3(0.0f, 6.0f, 0.0)));
	pointLightScene->addPointLight(PointLight(glm::vec3(15.0f, 2.0f, 0.0)));
	vecScenes.push_back(pointLightScene);

	Scene* directLightScene = new Scene(sceneCount);
	sceneCount++;
	directLightScene->addCamera(camera);
	directLightScene->addObject(plainLight);
	directLightScene->setDirLight(DirectionalLight(glm::vec3(.0f, -1.f, 1.f)));
	vecScenes.push_back(directLightScene);

	Scene* spotLightScene = new Scene(sceneCount);
	sceneCount++;
	spotLightScene->addCamera(camera);
	spotLightScene->addObject(plainLight);
	spotLightScene->addSpotLight(SpotLight((glm::vec3(.0f, -1.f, -1.f)), (glm::vec3(.0f, 5.f, 0.f))));
	spotLightScene->addSpotLight(SpotLight((glm::vec3(.6f, -1.f, 0.f)), (glm::vec3(.5f, 5.f, 0.f))));
	vecScenes.push_back(spotLightScene);

//Building scene

	Scene* houseScene = new Scene(sceneCount);
	sceneCount++;
	houseScene->addCamera(camera);
	houseScene->addObject(plainGrass);
	houseScene->addObject(building);
	houseScene->addObject(zombie);
	houseScene->addObject(start);
	houseScene->addObject(finish);
	houseScene->addObject(check1);
	houseScene->addObject(check2);
	houseScene->addObject(check3);
	houseScene->addObject(check4);
	houseScene->addObject(check5);
	houseScene->setSkybox(skybox);
	houseScene->setDirLight(DirectionalLight(glm::vec3(.0f, -1.f, 1.f)));
	vecScenes.push_back(houseScene);

//Space scene
	Scene* spaceScene = new Scene(sceneCount);
	sceneCount++;
	spaceScene->addCamera(camera);
	spaceScene->setSkybox(skybox_space);
	spaceScene->addPointLight(PointLight(glm::vec3(0.0f, 10.0f, 0.0)));
	spaceScene->addObject(planet_earth);
	vecScenes.push_back(spaceScene);

//Christmas scene
	Scene* christmas = new Scene(sceneCount);
	sceneCount++;
	Object* plain2 = factoryO->newObject(factoryM->newModel("plain"), shaderManager->getShader("phong"));
	Transformation::scale(plain2->getMatrix(), glm::vec3(10.0f, 10.0f, 10.0f));
	Object* treeCH = factoryO->newObject(factoryM->newModel("tree"), shaderManager->getShader("lambert"));

	christmas->addCamera(camera);
	christmas->addObject(plain2);
	christmas->addObject(treeCH);

	for (int i = 0; i < 30; i++)
	{
		Object* gift;

		float randomX = ((float)rand()) / (float)RAND_MAX;
		float diff = 7 - (-7);
		float x = (randomX * diff) +(- 7);

		float randomZ = ((float)rand()) / (float)RAND_MAX;
		float z = (randomZ * diff) + (-7);

		gift = factoryO->newObject(factoryM->newModel("gift"), shaderManager->getShader("default"));
		Transformation::translate(gift->getMatrix(), glm::vec3(x, 0.0f, z));
		Transformation::scale(gift->getMatrix(), glm::vec3(2.0f, 2.0f, 2.0f));

		christmas->addObject(gift);
	}

	christmas->setLightPosition(glm::vec3(0.0f, 10.0f, 0.0));
	vecScenes.push_back(christmas);

	
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
	

	scene = vecScenes.at(0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	scene->getCamera()->notify();
	while (!glfwWindowShouldClose(this->window->getGLFWWindow())) 
	{
	

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//scene->getCurrentCam()->UpdateShader(shader->getShader());
		scene->draw();


		this->controller->processHeldKeys();
		

		//Transformation::rotate(cube->getMatrix(), 0.02f, glm::vec3(1.0f, 1.0f, 0.0f));
		//Transformation::rotate(cube2->getMatrix(), 0.01f, glm::vec3(0.0f, 1.0f, 1.0f));
		//Transformation::rotate(ball_R->getMatrix(), 0.01f, glm::vec3(0.0f, 1.0f, 1.0f));
		Transformation::rotate(treeCH->getMatrix(), 0.04f, glm::vec3(0.0f, 1.0f, 0.0f));
		Transformation::rotate(planet_earth->getMatrix(), 0.009f, glm::vec3(0.0f, 1.0f, 0.0f));

			
	// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(this->window->getGLFWWindow());
	}

	glfwDestroyWindow(this->window->getGLFWWindow());
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

Window* Engine::getWindow() 
{
	return this->window;
}

GLint Engine::getIndex() 
{
	GLint index = objectCounter;
	objectCounter++;
	return index;
}


void Engine::nextScene() 
{
	GLint nextScene = this->scene->sceneCount + 1;
	if (nextScene >= vecScenes.size())
		nextScene = 0;
	this->scene = vecScenes.at(nextScene);

	printf("change scene %d\n", nextScene);
}

void Engine::previousScene()
{
	GLint prevScene = this->scene->sceneCount - 1;
	if (prevScene < 0)
		prevScene = vecScenes.size()-1;
	this->scene = vecScenes.at(prevScene);

	printf("change scene %d\n", prevScene);
}


Scene* Engine::getScene()
{
	return this->scene;

}

Controller* Engine::getController()
{
	return this->controller;
}

