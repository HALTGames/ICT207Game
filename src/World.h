#pragma once

//-----------------------------------------------------------------------------

/**
 * Allows the child classes of World to set what world callbacks to switch to.
 */
enum WorldEnum {
	NONE, /**< No world selected. i.e. NULL */
	SHAYSWORLD, /**< Shays world selected */
	GAMEWORLD, /**< Game world selected */
	MENUWORLD /**< Menu world selected */
};

//-----------------------------------------------------------------------------

/**
 * \file World.h World.cpp
 * \class World
 * \brief World class implementation.
 *
 * Sets up a world which acts as a scene with its own OpenGL function
 * callbacks.
 *
 * \author Timothy Veletta, Hamish Carrier
 * \date 29/09/12
 * \version 01 - Timothy Veletta 29/09/12
 *		Created file including Init, Reshape, Display, Keyboard, Mouse,
 *		MovementKeys, ReleaseKey, ReleaseKeys, MouseMove functions and also the
 *		changeWorld variable.
 * \version 02 - Timothy Veletta, 14/10/12
 *		Minor changes.
 * \version 03 - Timothy Veletta, 26/10/12
 *		Added virtual destructor.
 * \version 04 - Hamish Carrier, 29/10/12
 *		Addition of GUI function.
 * \version 05 - Hamish Carrier, 30/10/12
 *		Addition of GUIInit function.
 * \version 06 - Timothy Veletta, 03/11/12
 *		Documentation added.
 */
class World abstract
{
public:
	/**
	 * \brief Destroys the world.
	 *
	 * Destroys the world and sets the current world to NONE.
	 */
	virtual ~World() {currWorld = NONE; }

	/**
	 * \brief Initialises the class.
	 *
	 * Is called when the world is changed to this world to initialise the
	 * member variables of the class and also set up models/textures.
	 */
	virtual void Init() {};

	/**
	 *	\brief Reshape callback.
	 *
	 * Called whenever the size of the window is changed.
	 *
	 * \param w the width of the window
	 * \param h the height of the window
	 */
	virtual void Reshape(int w, int h) {};

	/**
	 *	\brief Display callback.
	 *
	 * Called every display loop.
	 */
	virtual void Display() {};

	/**
	 *	\brief Idle callback.
	 *
	 * Called every single loop through the program.
	 */
	virtual void Idle() {};

	/**
	 *	\brief Keyboard callback.
	 *
	 * Calls the Keyboard function of the current World.
	 * 
	 * /param key the key pressed
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void Keyboard(unsigned char key, int keyX, int keyY) {};

	/**
	 *	\brief Mouse callback.
	 *
	 * Calls the Mouse function of the current World.
	 *
	 * \param button the button pressed
	 * \param state the state of the mouse buttonm
	 * \param mouseX the x coordinate of the mouse pointer
	 * \param mouseY the y coordinate of the mouse pointer
	 */
	virtual void Mouse(int button, int state, int mouseX, int mouseY) {};

	/**
	 *	\brief Special keyboard callback.
	 *
	 * Calls the special keyboard function of the current World.
	 *
	 * /param key the special key pressed
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void MovementKeys(int key, int x, int y) {};

	/**
	 *	\brief Special keyboard up callback.
	 *
	 * Calls the special keyboard up function of the current World.
	 *
	 * \param newWorld the world to switch to
	 */
	virtual void ReleaseKey(int key, int x, int y) {};

	/**
	 *	\brief Keyboard up callback.
	 *
	 * Calls the keyboard up function of the current World.
	 *
	 * /param key the special key up
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void ReleaseKeys(unsigned char key, int x, int y) {};

	/**
	 *	\brief Motion callback.
	 *
	 * Calls the mouse move function of the current World.
	 *
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void MouseMove(int x, int y) {}; 

	/**
	 * \brief Displays the GUI.
	 *
	 * Displays the GUI in the current window, if the current world has one.
	 */
	virtual void GUI() {};

	/**
	 * \brief Initalises the GUI.
	 *
	 * Sets up the GUI for the current World.
	 */
	virtual void GUIinit() {};

	/**
	 * \brief Deallocates the memory used by the world.
	 *
	 * Deallocates the resources used by the world. This is called whenever
	 * we change away from the current world to deallocate the memory used by
	 * that world.
	 */
	virtual void Exit() {};

	WorldEnum currWorld; /**< The current world getting displayed, can be
						 changed to another world which will cause the program
						 to change worlds the next update loop. */
};

//-----------------------------------------------------------------------------