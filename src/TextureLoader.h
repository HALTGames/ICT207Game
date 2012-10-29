#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#pragma once

#include "SOIL.h"
#include <string>
#include <gl\glut.h>
#include <vector>

class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);

	void LoadTexture(int i, std::string Name);

	Gluint GetTexture(int i) const {return Texture[i];}

private:
	GLuint Texture[100];
};

#endif