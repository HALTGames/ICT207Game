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

	void LoadTexture(int i, std::string Name) {
	std::vector<char> chars(Name.c_str(), Name.c_str() + Name.size() + 1u); 
	
	Texture[i] = SOIL_load_OGL_texture
	(
	&chars[0],
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);
	glBindTexture(GL_TEXTURE_2D, Texture[i]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

	GLuint GetTexture(int i) const {return Texture[i];}

private:
	GLuint Texture[100];
	GLuint X;
};

#endif