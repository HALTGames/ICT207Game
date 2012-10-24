#pragma once

//-----------------------------------------------------------------------------

#include <assert.h>
#include "model.h"
#include "../Vector3.h"

//-----------------------------------------------------------------------------

struct CollisionSphere
{
	Vector3 center;
	double radius;

	CollisionSphere():center(Vector3()), radius(1) {}
	CollisionSphere(Vector3 cen, double rad):center(cen), radius(rad) {}

	void TranslateSphere(Vector3 move) { center += move; }
	void ScaleSphere(double scale) { radius *= scale; }
};

//-----------------------------------------------------------------------------

/**
 * \file GameModel.h GameModel.cpp
 * \class GameModel
 * \brief GameModel class implementation.
 *
 * Sets up a Model with a bounding box around it.
 *
 * \author Timothy Veletta
 * \date 08/10/12
 * \version 01 - Timothy Veletta 08/10/12
 *		Created and implemented the constructor as well as methods to load the
 *		model and draw it.
 */
class GameModel :
	public Model
{
public:
	/**
	 * \brief The default constructor.
	 *
	 * Sets up the collision bounding box.
	 */
	GameModel();

	/**
	 * \brief The default destructor.
	 *
	 * Destroys the collision bounding box.
	 */
	~GameModel(void);

	/**
	 * \brief Loads the model.
	 *
	 * Loads in the OBJ format model and creates the collision bounding box
	 * for that model.
	 *
	 * \param the OBJ model file to load in
	 * \retval whether or not the creation of the bounding boxes was successful
	 */
	virtual bool LoadModel(char* fileName);

	/**
	 * \brief Renders the model.
	 *
	 * Renders the model to screen.
	 *
	 * \retval whether or not rendering was successful
	 */
	virtual bool DrawModel();

	void DrawSphere();
private:
	CollisionSphere* sphere;

	/**
	 * \brief Creates the bounding box.
	 *
	 * Creates the collision bounding box based around the size of the model.
	 *
	 * \retval whether or not the process was successful
	 */
	bool CreateCollisionSphere();
};

//-----------------------------------------------------------------------------