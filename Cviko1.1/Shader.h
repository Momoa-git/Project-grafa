#pragma once
#include <stdexcept>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Observer.h"
#include "ShaderLoader.h"

class Shader : public Observer{
private:
	GLuint shader;
    glm::mat4 viewMat;
	glm::mat4 projMat;
	glm::vec3 cameraPos;

public:
	Shader(const char* vertex_shader, const char* fragment_shader);
	
	GLuint getShader();  
	void drawShader();
	GLint getUniform(const char* name);

	virtual void updateShader(glm::mat4 viewMat, glm::mat4 projMat, glm::vec3 cameraPos) override;

};
