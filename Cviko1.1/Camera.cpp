#include"Camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	this->position = position;
	bias = -90.0f;
	pitch = 0.0f;
	speed = 0.1f;
	viewMat = glm::lookAt(position, position + orientation, WorldUp);
	projMat = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
	calcOrientation();
}

void Camera::updateShader(GLuint shader) {
	GLint idViewMat = glGetUniformLocation(shader, "viewMatrix");
	GLint idProjMat = glGetUniformLocation(shader, "projectionMatrix");

	glUniformMatrix4fv(idViewMat, 1, GL_FALSE, &viewMat[0][0]);
	glUniformMatrix4fv(idProjMat, 1, GL_FALSE, &projMat[0][0]);

}
// pocitani smerovych vektoru kamery
void Camera::calcOrientation() {
	glm::vec3 front;
	front.x = cos(glm::radians(bias)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(bias)) * cos(glm::radians(pitch));
	orientation = glm::normalize(front);

	Right = glm::normalize(glm::cross(orientation, WorldUp));
	Up = glm::normalize(glm::cross(Right, orientation));
} 
void Camera::calcView() {
	viewMat = glm::lookAt(position, position + orientation, WorldUp);
	notify();
}
void Camera::move(Camera_Movement direction) {
	GLfloat velocity = speed;
	printf("direction %d\n", direction);

	switch (direction) {
	case CAM_FORWARD:
		position += orientation * velocity;
		break;
	case CAM_BACKWARD:
		position -= orientation * velocity;
		break;
	case CAM_LEFT:
		position -= Right * velocity;
		break;
	case CAM_RIGHT:
		position += Right * velocity;
		break;
	case CAM_UP:
		position += Up * velocity;
		break;
	case CAM_DOWN:
		position -= Up * velocity;
		break;
	}
	calcView();
}
// otaceni mysis
void Camera::rotate(double xoffset, double yoffset, GLboolean constrainPitch) {
	bias += xoffset * sensitivity;
	pitch -= yoffset * sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}
	calcOrientation();
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