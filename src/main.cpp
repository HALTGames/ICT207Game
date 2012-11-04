#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <iostream>
#include <GL\freeglut.h>
#include <SDL.h>
#include "World.h"
#include "shaysworld\ShaysWorld.h"
#include "gameworld\GameWorld.h"
#include "gamemenu\MenuWorld.h"

//-----------------------------------------------------------------------------

/**
 *	\brief Switches between worlds.
 *
 * Switches to the specified world.
 *
 * \param newWorld the world to switch to
 */
void SwitchWorld(WorldEnum newWorld);

/**
 *	\brief Display callback.
 *
 * Calls the Display function of the current World.
 */
void Display(void);

/**
 *	\brief Idle callback.
 *
 * Calls the Idle function of the current World.
 */
void Idle(void);

/**
 *	\brief Keyboard callback.
 *
 * Calls the Keyboard function of the current World.
 * 
 * /param key the key pressed
 * /param x the x coordinate of the mouse pointer
 * /param y the y coordinate of the mouse pointer
 */
void Keyboard(unsigned char key, int x, int y);

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
void Mouse(int button, int state, int mouseX, int mouseY);

/**
 *	\brief Reshape callback.
 *
 * Calls the Reshape function of the current World.
 *
 * \param w the width of the window
 * \param h the height of the window
 */
void Reshape(int w, int h);

/**
 *	\brief Special keyboard callback.
 *
 * Calls the special keyboard function of the current World.
 *
 * /param key the special key pressed
 * /param x the x coordinate of the mouse pointer
 * /param y the y coordinate of the mouse pointer
 */
void MovementKeys(int key, int x, int y);

/**
 *	\brief Special keyboard up callback.
 *
 * Calls the special keyboard up function of the current World.
 *
 * \param newWorld the world to switch to
 */
void ReleaseKey(int key, int x, int y);

/**
 *	\brief Keyboard up callback.
 *
 * Calls the keyboard up function of the current World.
 *
 * /param key the special key up
 * /param x the x coordinate of the mouse pointer
 * /param y the y coordinate of the mouse pointer
 */
void ReleaseKeys(unsigned char key, int x, int y);

/**
 *	\brief Motion callback.
 *
 * Calls the mouse move function of the current World.
 *
 * /param x the x coordinate of the mouse pointer
 * /param y the y coordinate of the mouse pointer
 */
void MouseMove(int x, int y);

/**
 *	\brief GUI function.
 *
 * Calls the GUI function of the current World.
 */
void GUI(void);


//-----------------------------------------------------------------------------
//Uncomment to start in GameWorld
/*
World* game = new GameWorld;
World* shays = NULL;
World* menu = NULL;
World* currentWorld = game;
WorldEnum current = GAMEWORLD;
*/
//-----------------------------------------------------------------------------
//Uncomment to start in MenuWorld

World* game = NULL;
World* shays = NULL;
World* menu = new MenuWorld;
World* currentWorld = menu;
WorldEnum current = MENUWORLD;


/*
World* game = new GameWorld;
World* shays = new ShaysWorld;
World* menu = new MenuWorld;
World* currentWorld = game;
WorldEnum current = GAMEWORLD;
*/

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	// OpenGL Initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(400,0);
	glutInitWindowSize(1280, 960);

	glutCreateWindow("Window");

	currentWorld->Init();
	
	// Set Callbacks
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(MovementKeys);
	glutSpecialUpFunc(ReleaseKey);
	glutKeyboardUpFunc (ReleaseKeys);
	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutReshapeFunc(Reshape);
	glutPassiveMotionFunc(MouseMove);

	if(current == GAMEWORLD)
	{
		glutCreateSubWindow (1, 200, 810, 880, 150); 
		glutDisplayFunc(GUI);
		currentWorld->GUIinit();
	}
	else
	{
		glutDestroyWindow(2);
	}

	glutMainLoop();

	return 0;
}

//-----------------------------------------------------------------------------

void SwitchWorld(WorldEnum newWorld)
{
	//currentWorld->Exit();

	switch(current)
	{
	case SHAYSWORLD:
		delete shays;
		break;
	case GAMEWORLD:
		delete game;
		break;
	case MENUWORLD:
		delete menu;
		break;
	}

	current = newWorld;

	switch(current)
	{
	case SHAYSWORLD:
		if(shays)
		{
			shays = new ShaysWorld;
		}
		shays = new ShaysWorld;
		currentWorld = shays;
		break;
	case GAMEWORLD:
		{
			if(game)
			{
				game = new GameWorld;
			}
			game = new GameWorld;
			currentWorld = game;
			break;
		}
	case MENUWORLD:
		if(menu)
		{
			menu = new MenuWorld;
		}
		menu = new MenuWorld;
		currentWorld = menu;
		break;
	}

	currentWorld->Init();
	if(current == GAMEWORLD)
	{
		glutCreateSubWindow (1, 200, 810, 880, 150); 			
		glutDisplayFunc(GUI);
		currentWorld->GUIinit();
	}
	else
	{
		glutDestroyWindow(2);
	}
}

//-----------------------------------------------------------------------------

void Display(void)
{
	currentWorld->Display();
}

//-----------------------------------------------------------------------------

void Idle(void)
{
	if(currentWorld->currWorld != current)
	{
		SwitchWorld(currentWorld->currWorld);
	}

	currentWorld->Idle();
}

//-----------------------------------------------------------------------------

void Keyboard(unsigned char key, int x, int y)
{
	std::cout << "key" << std::endl;
	currentWorld->Keyboard(key, x, y);
}

//-----------------------------------------------------------------------------

void Mouse(int button, int state, int mouseX, int mouseY)
{
	currentWorld->Mouse(button, state, mouseX, mouseY);
}

//-----------------------------------------------------------------------------

void Reshape(int w, int h)
{
	currentWorld->Reshape(w, h);
}

//-----------------------------------------------------------------------------

void MovementKeys(int key, int x, int y)
{
	currentWorld->MovementKeys(key, x, y);
}

//-----------------------------------------------------------------------------

void ReleaseKey(int key, int x, int y)
{
	currentWorld->ReleaseKey(key, x, y);
}

//-----------------------------------------------------------------------------

void ReleaseKeys(unsigned char key, int x, int y)
{
	currentWorld->ReleaseKeys(key, x, y);
}

//-----------------------------------------------------------------------------

void MouseMove(int x, int y)
{
	currentWorld->MouseMove(x, y);
}

//-----------------------------------------------------------------------------

void GUI()
{
	currentWorld->GUI();
}

//-----------------------------------------------------------------------------