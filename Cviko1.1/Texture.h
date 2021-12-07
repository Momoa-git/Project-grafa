#pragma once
#include <SOIL.h>
#include <string>
#include <memory>
#include "Shader.h"

class Texture {
private:
	GLuint textureID;
	int index;

public: 
	Texture();
	Texture(const char* path, int index);
	int getIndex();
	void useTexture(Shader* shader);


};
