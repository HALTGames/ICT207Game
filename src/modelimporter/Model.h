#pragma once

//-----------------------------------------------------------------------------

#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <GL\freeglut.h>
#include "glm.h"

//-----------------------------------------------------------------------------

/**
 * \file Model.h Model.cpp
 * \class Model
 * \brief Model class implementation.
 *
 * Creates and loads in an OBJ model file.
 *
 * \author Timothy Veletta
 * \date 08/10/12
 * \version 01 - Timothy Veletta, 12/09/12
 *		Created constructors, destructor as well as load and draw functions.
 */
class Model
{
public:
	/**
	 * \brief The default constructor.
	 *
	 * 
	 *
	 */
	Model(void);

	Model(char* fileName);

	~Model(void);

	virtual bool LoadModel(char* fileName);

	virtual bool DrawModel();

protected:
	GLMmodel* mod;
};

//-----------------------------------------------------------------------------