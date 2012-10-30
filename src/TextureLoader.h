#pragma once
#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H


#include <string>
#include <gl\glut.h>
#include <vector>
#include <iostream>


class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);

	void LoadTexture(const char * filename, int width, int height, int i);
	void ReleaseTexture(int i) {glDeleteTextures(1, &Texture[i]);}

	GLuint GetTexture(int i) const {return Texture[i];}

	void SetTexture(GLuint Tex) {Texture[count] = Tex;count++;}

private:
	GLuint Texture[100]; //Array indexes being used. 1
	static int count;
};

#endif