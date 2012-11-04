#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <GL\freeglut.h>
#include "../world.h"

#include "../modelimporter/GameModel.h"

class MenuWorld :
	public World
{
public:
	/**
	 * \brief Initialises the class.
	 *
	 * Sets up the window size, loads in menu models, inti
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
	 * Handles the display of the menu items, as well as exit splash
	 */
	virtual void Display();
	/**
	 *	\brief Idle callback.
	 *
	 * tracks when the world should be changed.
	 */
	virtual void Idle();
	/**
	 *	\brief keyboard callback.
	 *
	 * Not in use.
	 *
	 * /param key the key pressed
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void Keyboard(unsigned char key, int keyX, int keyY);
	/**
	 *	\brief Mouse callback.
	 *
	 * Handles the mouse functions for the menu world, tracks which button the mouse has currently selected
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
	 * Not in use.
	 *
	 * /param key the special key up
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void ReleaseKeys(unsigned char key, int x, int y);
	/**
	 *	\brief Motion callback.
	 *
	 * Not in use
	 *
	 * /param x the x coordinate of the mouse pointer
	 * /param y the y coordinate of the mouse pointer
	 */
	virtual void MouseMove(int x, int y);



private:
	///width of the glut window
	int windowWidth;
	///height of the glut window
	int windowHeight;

	///Create 10 GameModel Loader Objects
	GameModel Loader[10]; 
	///Int used to track which menu button is selected
	int MenuChoice;
	///Tracks whether or not exit has been selected
	bool Exit;
	/**
	 * \brief Displays exit screen
	 *
	 * When called displays the exit splash
	 */
	void DisplayExit();
};

