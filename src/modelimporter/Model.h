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
	 *  Initialises the class with no model loaded.
	 */
	Model(void);

	/**
	 * \brief The secondary constructor.
	 *
	 * Initialises the class and loads in the given OBJ model file.
	 * 
	 * \param fileName the OBJ model file to load in
	 */
	Model(char* fileName);

	/**
	 * \brief The default destructor.
	 *
	 * Destroys the model object.
	 */
	~Model(void);

	/**
	 * \brief Loads the model.
	 *
	 * Loads in the given OBJ model file. When it loads in the model file, it
	 * places it at the origin and normalises it to have a maximum size of 1
	 * along the X, Y or Z axis depending on the model.
	 *
	 * \param fileName the OBJ model file to load in
	 * \retval whether or not a model was loaded in
	 */
	virtual bool LoadModel(char* fileName);

	/**
	 * \brief Draws the model.
	 *
	 * Draws the model to screen.
	 *
	 * /retval whether or not the model was drawn to screen
	 */
	virtual bool DrawModel();

protected:
	GLMmodel* mod; /**< the OBJ model data */
};

//-----------------------------------------------------------------------------