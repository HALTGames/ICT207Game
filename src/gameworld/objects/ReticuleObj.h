#pragma once

//-----------------------------------------------------------------------------

#include "../gameobj.h"

//-----------------------------------------------------------------------------

/**
 * \brief ReticuleObj.h ReticuleObj.cpp
 * \class ReticuleObj
 * \brief ReticuleObj class implementation.
 *
 * Displays the reticule as the position set by the inherited position 
 * variable.
 *
 * \author Timothy Veletta 
 * \date 26/10/12
 * \version 01 - Timothy Veletta, 26/10/12
 *		Created constructor and display function.
 */
class ReticuleObj :
	public GameObj
{
public:
	/**
	 * \brief ReticuleObj constructor.
	 *
	 * Sets up the ReticuleObj class.
	 */
	ReticuleObj(void);
	
	/**
	 * \brief Displays the object.
	 *
	 * Displays the reticule object to screen.
	 */
	virtual void Display();
};

//-----------------------------------------------------------------------------