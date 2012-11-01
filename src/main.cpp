#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <GL\freeglut.h>
#include <SDL.h>
#include "World.h"
#include "shaysworld\ShaysWorld.h"
#include "gameworld\GameWorld.h"
#include "gamemenu\MenuWorld.h"

//-----------------------------------------------------------------------------

void SwitchWorld(WorldEnum newWorld);
void Display(void);
void Idle(void);
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int mouseX, int mouseY);
void Reshape(int w, int h);
void MovementKeys(int key, int x, int y);
void ReleaseKey(int key, int x, int y);
void ReleaseKeys(unsigned char key, int x, int y);
void MouseMove(int x, int y);
void GUI(void);

//void timer(int n);

World* game = new GameWorld;
World* shays = NULL;
World* menu = NULL;
World* currentWorld = game;
WorldEnum current = GAMEWORLD;

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

	//int fps = 60;
	//glutTimerFunc(100, timer, fps);

	glutMainLoop();

	return 0;
}

void SwitchWorld(WorldEnum newWorld)
{
	currentWorld->Exit();

	switch(newWorld)
	{
	case SHAYSWORLD:
		if(shays)
		{
			shays = new ShaysWorld;
		}
		currentWorld = shays;
		break;
	case GAMEWORLD:
		if(game)
		{
			game = new GameWorld;
		}
		currentWorld = game;
		break;
	case MENUWORLD:
		if(menu)
		{
			menu = new MenuWorld;
		}
		currentWorld = menu;
		break;
	}

	currentWorld->Init();
}

void Display(void)
{
	currentWorld->Display();
}

void Idle(void)
{
	//std::cout << "CurrentWorld: " << current << std::endl;

	if(currentWorld->currWorld != current)
	{
		current = currentWorld->currWorld;
		SwitchWorld(current);
	}

	currentWorld->Idle();
}

void Keyboard(unsigned char key, int x, int y)
{
	currentWorld->Keyboard(key, x, y);
}

void Mouse(int button, int state, int mouseX, int mouseY)
{
	currentWorld->Mouse(button, state, mouseX, mouseY);
}

void Reshape(int w, int h)
{
	currentWorld->Reshape(w, h);
}

void MovementKeys(int key, int x, int y)
{
	currentWorld->MovementKeys(key, x, y);
}

void ReleaseKey(int key, int x, int y)
{
	currentWorld->ReleaseKey(key, x, y);
}

void ReleaseKeys(unsigned char key, int x, int y)
{
	currentWorld->ReleaseKeys(key, x, y);
}

void MouseMove(int x, int y)
{
	currentWorld->MouseMove(x, y);
}

void GUI()
{
	currentWorld->GUI();
}
/*
void GUIinit()
{
	currentWorld->GUIinit();
}*/

/*void timer(int n)
{
	glutPostRedisplay();
	glutTimerFunc(1000/n, timer, n);
}*/
