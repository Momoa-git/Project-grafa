#include "Transformation.h"

void Transformation::rotate(glm::mat4x4* transMat, float angle, glm::vec3 axis)
{
	*transMat = glm::rotate(*transMat, angle, axis);
}

void Transformation::scale(glm::mat4x4* transMat, glm::vec3 scaleVec)
{
	*transMat = glm::scale(*transMat, scaleVec);
}

void Transformation::translate(glm::mat4x4* transMat, glm::vec3 transVec)
{
	*transMat = glm::translate(*transMat, transVec);
}