#include "Way.h"
int choose(int n, int k) { //n nad k
	if (k == 0)
		return 1;
	else
		return (n * choose(n - 1, k - 1)) / k;
}

Way::Way() 
{
	this->t = 0.5f;
	this->forward = true;
}

void Way::addControlPoint(glm::vec3 point) 
{
	this->controlPoints.push_back(point);
}
glm::vec3 Way::getNextControlPoint(float delta) 
{
	int pointNo = this->controlPoints.size() - 1;
	glm::vec3 resPoint = glm::vec3(0.f);

	for (int i = 0; i <= pointNo; i++) {
		float coef = choose(pointNo, i) * pow(t, i) * pow((1 - t), pointNo - i);
		printf("Path coef: %f, IsForward: %d, PointNo: %d, t: %f\n", coef, forward, pointNo, t);
		resPoint.x += this->controlPoints.at(i).x * coef;
		resPoint.y += this->controlPoints.at(i).y * coef;
		resPoint.z += this->controlPoints.at(i).z * coef;
	}
	if (t > 1.0f || t < 0.0f) {
		forward = !forward;
		printf("Reversing resPoint: %f %f %f\n", resPoint.x, resPoint.y, resPoint.z);
		printf("Vector:\n");
		for (int j = 0; j < this->controlPoints.size(); j++) {
			printf("\t point: %f %f %f\n", this->controlPoints.at(j).x, this->controlPoints.at(j).y, this->controlPoints.at(j).z);
		}
	}
	if (forward) t += delta;
	else t -= delta;
	printf("Path resPoint: %f %f %f\n", resPoint.x, resPoint.y, resPoint.z);
	return resPoint;
}