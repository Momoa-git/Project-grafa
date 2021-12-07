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
private:
	GLuint fragmentID;
	GLuint vertexID;

	string openFile(const char* name);

	GLuint shaderID = 0;

public:
	ShaderLoader();
	~ShaderLoader();
	GLuint loadShader(const char* vertexFileName, const char* fragmentFileName);
	





};
