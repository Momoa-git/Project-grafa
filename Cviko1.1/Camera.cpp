#include"Camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	this->position = position;
	this->orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	this->Right = glm::vec3(0.0f, 1.0f, 0.0f);
	this->Up = glm::vec3(0.0f, 1.0f, 0.0f);

	this->bias = -90.0f;       //odchylka
	this->pitch = 0.0f;
	this->speed = 0.1f;        //movement speed
	this->sensitivity = 0.04f; //citlivost

	viewMat = glm::lookAt(position, position + orientation, WorldUp);
	projMat = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 500.0f);
	calcVectors();
}

// pocitani smerovych vektoru kamery
void Camera::calcVectors() 
{
	glm::vec3 front;
	front.x = cos(glm::radians(bias)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(bias)) * cos(glm::radians(pitch));
	orientation = glm::normalize(front);

	Right = glm::normalize(glm::cross(orientation, WorldUp));
	Up = glm::normalize(glm::cross(Right, orientation));
} 
void Camera::calcView()
{
	viewMat = glm::lookAt(position, position + orientation, WorldUp);
	notify();
}
void Camera::calcMovement(Camera_Movement direction) 
{
	GLfloat velocity = speed;
	printf("direction %d\n", direction);

	switch (direction) 
	{
		case CAMERA_FORWARD:
			position += orientation * velocity;
			break;
		case CAMERA_BACKWARD:
			position -= orientation * velocity;
			break;
		case CAMERA_LEFT:
			position -= Right * velocity;
			break;
		case CAMERA_RIGHT:
			position += Right * velocity;
			break;
		case CAMERA_UP:
			position += Up * velocity;
			break;
		case CAMERA_DOWN:
			position -= Up * velocity;
			break;
	}
	calcView();
}
// otaceni mysis
void Camera::rotateMouse(double xoffset, double yoffset, GLboolean constrainPitch) 
{
	this->bias += xoffset * this->sensitivity;
	this->pitch -= yoffset * this->sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}
	calcVectors();
	calcView();
}

void Camera::calcProjection(int width, int height)
{
	projMat = glm::perspective(glm::radians(40.0f), (float)width / height, 0.1f, 100.0f);
	this->notify();

}


//Observer functions

void Camera::registerObserver(Observer* observer) {
	observers.push_back(observer);
}
void Camera::unregisterObserver(Observer* observer) {
	auto iterator = std::find(observers.begin(), observers.end(), observer);

	if (iterator != observers.end()) { // observer found
		observers.erase(iterator); // remove the observer
	}
}

void Camera::registerObserver(ObserverSkyBox* observer) {
	observersSky.push_back(observer);
}
void Camera::unregisterObserver(ObserverSkyBox* observer) {
	auto iterator = std::find(observersSky.begin(), observersSky.end(), observer);

	if (iterator != observersSky.end()) { // observer found
		observersSky.erase(iterator); // remove the observer
	}
}



void Camera::notify() {
	for (Observer* observer : observers) { // notify all observers
		observer->updateShader(viewMat, projMat, position);
	}

	for (ObserverSkyBox* observer : observersSky) { // notify all observers
		observer->update(this->position);
	}

}