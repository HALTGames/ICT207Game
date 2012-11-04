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
 * \version 03 - Timothy
 */
class World abstract
{
public:
	virtual ~World() {currWorld = NONE; }

	virtual void Init() {};
	virtual void Reshape(int w, int h) {};
	virtual void Display() {};
	virtual void Idle() {};
	virtual void Keyboard(unsigned char key, int keyX, int keyY) {};
	virtual void Mouse(int button, int state, int mouseX, int mouseY) {};
	virtual void MovementKeys(int key, int x, int y) {};
	virtual void ReleaseKey(int key, int x, int y) {};
	virtual void ReleaseKeys(unsigned char key, int x, int y) {};
	virtual void MouseMove(int x, int y) {}; 
	virtual void GUI() {};
	virtual void GUIinit() {};

	virtual void Exit() {};

	WorldEnum currWorld;
};

//-----------------------------------------------------------------------------