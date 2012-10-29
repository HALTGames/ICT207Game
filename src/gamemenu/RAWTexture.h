#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

class RAWTexture
{
public:
	RAWTexture(void);
	~RAWTexture(void);

	GLuint LoadTexture(const char* filename, int width, int height);
	void FreeTexture(GLuint texture);
};

