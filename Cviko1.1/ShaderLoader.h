#pragma once

#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>

#include <GL/glew.h>

using namespace std;

class ShaderLoader 
{
	GLuint fragmentID;
	GLuint vertexID;

	string openFile(const char* name);
protected:
	GLuint shaderProgramID = 0;

public:
	ShaderLoader(const char* vertexFileName, const char* fragmentFileName, GLuint* shaderID);
	~ShaderLoader();
	GLuint loadShader(const char* vertexFileName, const char* fragmentFileName);
	ShaderLoader();
	void deleteShader();





};
