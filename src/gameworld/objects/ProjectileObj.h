#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <cmath>
#include <GL\freeglut.h>
#include "../../Vector3.h"
#include "../GameObj.h"
#include "../GameCollision.h"
#include "../../modelimporter/GameModel.h"

//-----------------------------------------------------------------------------

/**
 * \brief Projectile.h ProjectileObj.cpp
 * \class ProjectileObj
 * \brief ProjectileObj class implementation.
 *
 * Sets up a projectile that moves from a start point in the direction of an
 * end point lasting for a second.
 *
 * \author Timothy Veletta, Arran Ford
 * \date 27/10/12
 * \version 01 - Timothy Veletta, 27/10/12
 *		Created constructor and display function along with speed, length,
 *		start and direction member variables.
 */
class ProjectileObj:
	public GameObj
{
public:
	/**
	 * \brief ProjectileObj constructor.
	 *
	 * Sets up a ProjectileObj with a start point of 0,0,0 and a destination
	 * end point of 10,0,10.
	 */
	ProjectileObj();

	/**
	 * \brief ProjectileObj constructor.
	 *
	 * Sets up a projectile with start position x1,0,z1 which moves towards
	 * x2,0,z2 for one second or until collision.
	 *
	 * \param x1 starting x coordinate
	 * \param z1 starting z coordinate
	 * \param x2 end x coordinate
	 * \param z2 end z coordinate
	 */
	ProjectileObj(double x1, double z1, double x2, double z2);

	/**
	 * \brief Displays the projectile.
	 *
	 * Displays the projectile at the position given by the inherited position
	 * variable.
	 */
	virtual void Display();

	/**
	 * \brief Gets the current position.
	 *
	 * Gets the current position of the projectile.
	 *
	 * \retval the current position of the projectile
	 */
	Vector3 GetCurrentPosition();

	/**
	 * \brief Gets the direction.
	 *
	 * Gets the current direction of the projectile.
	 *
	 * \retval the direction vector for the projectile
	 */
	Vector3 GetDirection();
protected:
	double speed; /**< the speed of the projectile */
	int time; /**< a timer for the projectile */
	Vector3 direction; /**< the direction the projectile is going in */

	int startTime; /**< when the projectile was created */

	/**
	 * \brief Checks the time.
	 *
	 * Checks the amount of time the projectile object has been created for and
	 * sets the flag to destroy this if that time is greater than a second.
	 *
	 * \retval if the time is greater than a second
	 */
	bool CheckTime() const;

	/**
	 * \brief Checks for collision.
	 *
	 * Checks whether the projectile is colliding with another object.
	 *
	 * \retval whether the projectile is colliding with another object
	 */
	virtual bool CheckCollision();
};

//-----------------------------------------------------------------------------