#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <GL\freeglut.h>
#include "glm.h"

class Model
{
public:
	Model(void);

	Model(char* fileName);

	~Model(void);

	virtual bool LoadModel(char* fileName);

	virtual bool DrawModel();

protected:
	GLMmodel* mod;
};

