#pragma once
#include <vector>
#include <glm/vec3.hpp>
class Way
{
private:
	std::vector <glm::vec3> controlPoints;
	bool forward;
	float t;

public:
	Way();
	void addControlPoint(glm::vec3 point);
	glm::vec3 getNextControlPoint(float delta);

};

