#pragma once

#define GLUT_DISABLE_ATEXIT_HACK
#ifndef GAMEWORLD_H
#define GAMEWORLD_H

//------------------------------------------------------------------------------

#define PI 3.14159265

//------------------------------------------------------------------------------

// STL
#include <list>
#include <cmath>

// FREEGLUT
#include <GL\freeglut.h>
#include <GL\freeglut_ext.h>

// PARENT
#include "../World.h"

// HELPER CLASSES
#include "../modelimporter/TerrainModel.h"
#include "GameCamera.h"
#include "GameObj.h"
//#include "../SoundControl/sounds.h"
#include "../modelimporter/GameModel.h"
#include "ProjectileManager.h"

// OBJECTS
#include "objects\AIManager.h"
#include "objects\ProjectileObj.h"
#include "objects\ReticuleObj.h"
#include "objects\TerrainObj.h"

//------------------------------------------------------------------------------

/**
 * \file GameWorld.h GameWorld.cpp
 * \class GameWorld
 * \brief Handles the Game World functionality.
 *
 * The game world sets up and manages the components of the game world. It
 * handles the displaying of components, spawning of AI, sound, lighting and the
 * GUI.
 *
 * \author Timothy Veletta, Arran Ford, Hamish Carrier
 * \date 29/09/12
 * \version 01 - Timothy Veletta 29/09/12
 *		Created file with Display, Keyboard, Mouse, SpecialKeyFunc and Init
 *		functions.
 * \version 02 - Timothy Veletta 14/10/12
 *		Added Reshape, MouseMove as well as functions to manage objects within
 *		the world.
 * \version 03 - Timothy Veletta 22/10/12
 *		Added a camera, player and island object.
 * \version 04 - Timothy Veletta 23/10/12
 *		Added functions to measure frames per second as well as registering
 *		key presses and turning them into player movements.
 * \version 05 - Timothy Veletta 25/10/12
 * 		Limited the frame rate to 85 FPS, halved the memory usage.
 * \version 06 - Arran Ford 28/10/12
 * 		Added in spawning and AI management.
 * \version 07 - Hamish Carrier 29/10/12
 *		Added in GUI creation for the game world.
 * \version 08 - Array Ford 29/10/12
 *		Added in music that plays when the game world is entered.
 * \version 09 - Timothy Veletta 29/10/12
 *		Moved existing object management code to another class.
 * \version 10 - Arran Ford 30/10/12
 *		AI maintenance things. 4 different types of AI spawning.
 * \version 11 - Hamish Carrier 30/10/12
 *		Working on GUI, added textures to the GUI and various GUI buttons.
 * \version 12 - Hamish Carrier 31/10/12
 *		Added in improved island.
 * \version 13 - Arran Ford 01/11/12
 *		Lighting code added in.
 */
class GameWorld: public World
{
public:
	/**
	 * \brief GameWorld destructor.
	 *
	 * Destroys the GameWorld class.
	 */
	~GameWorld(void);

	
	/**
	 * \brief Initialises the class.
	 *
	 * Sets up the lighting, sound, player, AI, terrain. window size
	 */
	virtual void Init();

	/**
	 *	\brief Reshape callback.
	 *
	 * Called whenever the size of the window is changed.
	 *
	 * \param w the width of the window
	 * \param h the height of the window
	 */
	virtual void Reshape(int w, int h);

	/**
	 *	\brief Display callback.
	 *
	 * Handles the camera movement, displaying of the player and the island and
	 * also calls the update function for the AI.
	 */
	virtual void Display();

	/**
	 *	\brief Idle callback.
	 *
	 * Handles the limiting of the frame rate.
	 */
	virtual void Idle();

	/**
	 *	\brief Keyboard callback.
	 *
	 * Handles the key presses for the game world.
	 * 
	 * /param key the key pressed
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void Keyboard(unsigned char key, int keyX, int keyY);

	/**
	 *	\brief Mouse callback.
	 *
	 * Handles the mouse functions for the game world.
	 *
	 * \param button the button pressed
	 * \param state the state of the mouse buttonm
	 * \param mouseX the x coordinate of the mouse pointer
	 * \param mouseY the y coordinate of the mouse pointer
	 */
	virtual void Mouse(int button, int state, int mouseX, int mouseY);

	/**
	 *	\brief Special keyboard callback.
	 *
	 * Not in use.
	 *
	 * /param key the special key pressed
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void MovementKeys(int key, int x, int y);

	/**
	 *	\brief Special keyboard up callback.
	 *
	 * Not in use.
	 *
	 * /param key the special key released
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void ReleaseKey(int key, int x, int y);

	/**
	 *	\brief Keyboard up callback.
	 *
	 * Changes the state of the up, down, left, right player movement.
	 *
	 * /param key the special key up
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void ReleaseKeys(unsigned char key, int x, int y);

	/**
	 *	\brief Motion callback.
	 *
	 * Gets where the mouse pointer is in relation to the world and uses this
	 * to work out what direction the player is facing.
	 *
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void MouseMove(int x, int y); 

	/**
	 * \brief Displays the GUI.
	 *
	 * Displays the GUI in the current window.
	 */
	virtual void GUI();

	/**
	 * \brief Initalises the GUI.
	 *
	 * Loads in the GUI models.
	 */
	virtual void GUIinit();

	/**
	 * \brief Deallocates the memory used by the world.
	 *
	 * Deallocates the resources used by the world. This is called whenever
	 * we change away from the current world to deallocate the memory used by
	 * that world.
	 */
	virtual void Exit();

	/**
	 * \brief Passive Mana Regen.
	 *
	 * Passively regenerates mana.
	 */
	void ManaRegen();
	
private:
	PlayerObj* playerObj; /**< The player object */
	ReticuleObj* reticuleObj; /**< The reticule object */
	TerrainObj* terrainObj; /**< The terrain object that handles collision 
								around the mountain on the island. */
	
	AIManager* AImanage; /**< Manages the AI spawning. */
	sounds* SoundController; /**< Manages the playing of sound */
	GameCamera camera; /**< Manages the camera movement */
	
	/**
	 *	\brief Sets the position of the reticule.
	 *
	 * Gets where the mouse pointer is in relation to the world and uses this
	 * to work out what direction they are firing and where to place the
	 * reticule.
	 *
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	void SetReticulePosition(int x, int y);

	/**
	 * \brief Handles player movement.
	 *
	 * Handles continuous player movement in the case of keys being held down.
	 */
	void PlayerMovement();

	TerrainModel level; /**< Loads in the Island model */
	GameModel ModelLoader[10]; /**< Loads in the models for the GUI */

	int ManaTimer; /**< Times the passive mana regeneration */

	int lastdrawn; /**< Gets the time the Display function was last called */

	bool left, right, forward, back; /**< Gets the movement states as to
										whether the ASDW keys are pressed */

	int gameWidth, gameHeight; /**< The resolution of the game window */
};

//------------------------------------------------------------------------------

#endif