#include "Shader.h"

Shader::Shader(const char* vertex_shader, const char* fragment_shader) 
{
	this->shader = loadShader(vertex_shader, fragment_shader);

}


void Shader::drawShader()
{
	glUseProgram(shader);

	GLint idViewMat = glGetUniformLocation(shader, "viewMatrix");
	GLint idProjMat = glGetUniformLocation(shader, "projectionMatrix");
	GLint idCamPos = glGetUniformLocation(shader, "cameraPos");

	glUniformMatrix4fv(idViewMat, 1, GL_FALSE, &viewMat[0][0]);
	glUniformMatrix4fv(idProjMat, 1, GL_FALSE, &projMat[0][0]);
	glUniform3fv(idCamPos, 1, glm::value_ptr(this->cameraPos));
}
/*
GLuint Shader::getShader()
{
	return shader;

}*/
GLint Shader::getUniform(const char* name)
{
	return glGetUniformLocation(shader, name);
}

void Shader::updateShader(glm::mat4 viewMat, glm::mat4 projMat, glm::vec3 cameraPos)
{
	this->viewMat = viewMat;
	this->projMat = projMat;
	this->cameraPos = cameraPos;

}
