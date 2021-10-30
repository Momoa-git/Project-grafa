#pragma once
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Transformation
{
public:
	static void rotate(glm::mat4x4* transMat, float angle, glm::vec3 axis);
	static void scale(glm::mat4x4* transMat, glm::vec3 scaleVec);
	static void translate(glm::mat4x4* transMat, glm::vec3 transVec);

};
