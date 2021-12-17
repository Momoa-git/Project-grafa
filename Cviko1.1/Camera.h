#pragma once
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include "ObserverSubject.h"
#include "vector"

const glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

enum Camera_Movement {
	CAMERA_LEFT,
	CAMERA_RIGHT,
	CAMERA_UP,
	CAMERA_DOWN,
	CAMERA_FORWARD,
	CAMERA_BACKWARD,
};

class Camera : public ObserverSubject
{
public:
	std::vector<Observer*> observers;
	std::vector<ObserverSkyBox*> observersSky;

	glm::vec3 position;
	glm::vec3 orientation;
	glm::vec3 Right;
	glm::vec3 Up;

	glm::mat4 viewMat;
	glm::mat4 projMat;

	GLfloat speed;
	GLfloat sensitivity;
	GLfloat pitch;
	GLfloat bias;

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	//void updateShader(GLuint shader);
	void calcVectors();
	void calcView();
	void calcMovement(Camera_Movement direction);
	void rotateMouse(double xoffset, double yoffset, GLboolean constrainPitch = true);
	void calcProjection(int width, int height);

	virtual void registerObserver(Observer* observer) override;
	virtual void unregisterObserver(Observer* observer) override;
	virtual void registerObserver(ObserverSkyBox* observer) override;
	virtual void unregisterObserver(ObserverSkyBox* observer) override;
	virtual void notify() override;

};