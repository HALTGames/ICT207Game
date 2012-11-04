#pragma once

//-----------------------------------------------------------------------------

#include "..\GameObj.h"
#include "..\GameCollision.h"

//-----------------------------------------------------------------------------

/**
 * \brief TerrainObj.h TerrainObj.cpp
 * \class TerrainObj
 * \brief TerrainObj class implementation.
 *
 * Sets up a piece of collidable terrain which the player and AI cannot move
 * through and must go around.
 *
 * \author Timothy Veletta 
 * \date 26/10/12
 * \version 01 - Timothy Veletta, 26/10/12
 *		Created constructor and display function.
 */
class TerrainObj :
	public GameObj
{
public:
	/**
	 * \brief Sets up the terrain object.
	 *
	 * Initialises the TerrainObj class by setting up the terrain object.
	 *
	 */
	TerrainObj();

	/**
	 * \brief Displays the TerrainObj.
	 *
	 * Displays the terrain object to screen.
	 */
	virtual void Display();
};

//-----------------------------------------------------------------------------