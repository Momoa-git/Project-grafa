#include "Controller.h"

Controller::Controller()
{

}

void Controller::onClick(int button, int action, double x, double y)
{
	if (action == GLFW_PRESS) {
		printf("press %d %d %f %f\n", button, action, x, y);
	}
	if (action == GLFW_RELEASE) {
		printf("release %d %d %f %f\n", button, action, x, y);
	}

	if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_RIGHT) {
		glfwSetInputMode(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
	if (action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_RIGHT) {
		glfwSetInputMode(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT)
	{
		//read data from frame buffer
		GLbyte color[4];
		GLfloat depth;
		GLuint index; // identifikace telesa


		int newy = Engine::getInstance()->getWindow()->getHeight() - y;

		glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
		glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
		glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

		printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n",
			x, y, color[0], color[1], color[2], color[3], depth, index);
		glm::vec3 screenX = glm::vec3(x, newy, depth);
		glm::mat4 view = Engine::getInstance()->getScene()->getCamera()->viewMat;
		glm::mat4 projection = Engine::getInstance()->getScene()->getCamera()->projMat;
		glm::vec4 viewPort = glm::vec4(0, 0, Engine::getInstance()->getWindow()->getWidth(), Engine::getInstance()->getWindow()->getHeight());
		glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);

		printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);

		if (index != 0)
		{
			Object* toAdd = new Object(Engine::getInstance()->modelManager->getModel("addingTree"), Engine::getInstance()->shaderManager->getShader("light"));
			Transformation::translate(toAdd->getMatrix(), glm::vec3(pos.x, pos.y, pos.z));
			Transformation::scale(toAdd->getMatrix(), glm::vec3(.3f, .3f, .3f));
			Engine::getInstance()->getScene()->addObject(toAdd);
		}

	}


	return;
}

void Controller::onKey(int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		printf("press %d %d %d %d\n", key, scancode, action, mods);
	}
	if (action == GLFW_RELEASE) {
		printf("release %d %d %d %d\n", key, scancode, action, mods);
	}
	if (action == GLFW_PRESS && key == GLFW_KEY_RIGHT)
		Engine::getInstance()->nextScene();

	if (action == GLFW_PRESS && key == GLFW_KEY_LEFT)
		Engine::getInstance()->previousScene();
/*
	if (action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_W)
			Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_FORWARD);
	}*/

	return;
}



void Controller::onMove(double x, double y)
{
	printf("move %f %f \n", x, y);
	double moveX, moveY;
	moveX = x - (Engine::getInstance()->getWindow()->getWidth() / 2);
	moveY = y - (Engine::getInstance()->getWindow()->getHeight() / 2);

	glfwSetCursorPos(Engine::getInstance()->getWindow()->getGLFWWindow(), (Engine::getInstance()->getWindow()->getWidth() / 2), (Engine::getInstance()->getWindow()->getHeight() / 2));


	//this->forrest->getCurrentCam()->Rotate(xmove, ymove);
	if (glfwGetMouseButton(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->rotateMouse(moveX, moveY);
	}
}


void Controller::processHeldKeys()
{

	if (glfwGetKey(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_FORWARD);
	}
	if (glfwGetKey(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_LEFT);
	}
	if (glfwGetKey(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_BACKWARD);
	}
	if (glfwGetKey(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_RIGHT);
	}
	if (glfwGetKey(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_UP);
	}
	if (glfwGetKey(Engine::getInstance()->getWindow()->getGLFWWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Engine::getInstance()->getScene()->getCamera()->calcMovement(CAMERA_DOWN);
	}

}

