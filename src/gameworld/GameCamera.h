#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <gl\freeglut.h>
#include "../Vector3.h"

#include <math.h>

//-----------------------------------------------------------------------------

/**
 * \file GameCamera.h GameCamera.cpp
 * \class GameCamera
 * \brief Game Camera class implementation.
 *
 * Sets up the camera and handles moving the camera with the player.
 *
 * \author Timothy Veletta
 * \date 29/09/12
 * \version 01 - Timothy Veletta 29/09/12
 *		Created file including Render, SetHeight, SetBehind functions.
 * \version 02 - Timothy Veletta, 14/10/12
 *		Added functions for changing the height and behind.
 */
class GameCamera
{
public:
	/**
	 * \brief Sets up the camera.
	 *
	 * Sets up the game camera with a height of 30 and a behind value of 7.
	 */
	GameCamera();			

	/**
	 * \brief Displays the camera.
	 *
	 * Sets up the camera looking at the input position from the point 
	 * determined by the height and behind.
	 *
	 * \param position the point to look at
	 */
	void Render(const Vector3 position) const;	

	/**
	 * \brief Sets the height of the camera.
	 *
	 * Sets the height of the camera to the input value and returns whether or
	 * not this operation is successful.
	 *
	 * \param height the height of the camera
	 * \retval whether or not this is successful
	 */
	bool SetHeight(const double hght);

	/**
	 * \brief Sets the behind of the camera.
	 *
	 * Sets the behind of the camera to the input value and returns whether or
	 * not this operation is successful.
	 *
	 * \param behind the height of the camera
	 * \retval whether or not this is successful
	 */
	bool SetBehind(const double bhnd);

	/**
	 * \brief Changes the height of the camera.
	 *
	 * Changes the height of the camera by the specified amount.
	 *
	 * \param height the height of the camera
	 */
	void ChangeHeight(const double hght);

	/**
	 * \brief Changes the behind of the camera.
	 *
	 * Changes the behind of the camera by the specified amount.
	 *
	 * \param behind the behind of the camera
	 */
	void ChangeBehind(const double bhid);
private:
	double height; /**< the height of the camera */
	double behind; /**< the distance behind of the camera */
};

//-----------------------------------------------------------------------------