#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

class RAWTexture
{
public:
	RAWTexture(void);
	~RAWTexture(void);

	static GLuint LoadTexture(const char* filename, int width, int height);
	static void FreeTexture(GLuint texture);
};

