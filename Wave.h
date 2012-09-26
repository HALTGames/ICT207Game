#pragma once

//------------------------------------------------------------------------------

#include <math.h>
#include <GL/freeglut.h>

//------------------------------------------------------------------------------

#define PI_OVER_180  0.0174532925f

//------------------------------------------------------------------------------

/**
 * \file Wave.h Wave.cpp
 * \class Wave
 * \brief Wave class implementation.
 *
 * Creates a plane that waves in the same way that a flag does.
 *
 * \author Timothy Veletta
 * \date 12/09/12
 * \version 01 - Timothy Veletta 12/09/12
 *		Created constructor, initialise and render functions.
 */
class Wave
{
public:
	/**
	 * \brief The default constructor.
	 *
	 * Sets up the class by setting the wiggle amount to 0 and calling the
	 * initalise function to set up the wave.
	 */
	Wave(void);

	/**
	 * \brief Renders the wave.
	 *
	 * Renders the wave to screen. This function needs to be called every time 
	 * the display loop is called.
	 */
	void renderWave(void);

private:
	float   points[45][45][3]; //!< an array of points on the wave plane
	int     wiggle; //!< keeps track of what stage the wave is in

	/**
	 * \brief Sets up the wave.
	 *
	 * Sets up the plane of points to be used.
	 */
	void initWave(void);
};

//------------------------------------------------------------------------------