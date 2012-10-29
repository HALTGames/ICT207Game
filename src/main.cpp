#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <GL\freeglut.h>
#include <SDL.h>
#include "World.h"
#include "shaysworld\ShaysWorld.h"
#include "gameworld\GameWorld.h"
#include "GlobalVars.h"

//-----------------------------------------------------------------------------

enum WorldEnum {
	SHAYSWORLD,
	GAMEWORLD,
	MENUWORLD
};

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

bool Game;
World* currentWorld = NULL;

int main(int argc, char** argv)
{
	// OpenGL Initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	GAMEWIDTH = 1280;
	GAMEHEIGHT = 960;

	glutInitWindowSize(GAMEWIDTH, GAMEHEIGHT);

	glutCreateWindow("Window");

	// Start World
	SwitchWorld(GAMEWORLD);

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
	glutReshapeFunc(Reshape);
	glutPassiveMotionFunc(MouseMove);

	if(Game)
	{
		glutCreateSubWindow (1, 200, 810, 880, 150); //(1, 200, 810, 880, 150); 
		glutDisplayFunc(GUI);
	}

	//int fps = 60;
	//glutTimerFunc(100, timer, fps);

	glutMainLoop();

	return 0;
}

void SwitchWorld(WorldEnum newWorld)
{
	if(currentWorld) {
		delete currentWorld;
		currentWorld = NULL;
	}

	switch (newWorld) {
		case SHAYSWORLD:
			{
			currentWorld = new ShaysWorld();
			Game = false;
			break;
			}
		case GAMEWORLD:
			{
			currentWorld = new GameWorld();
			Game = true;
			break;
			}
	}

	currentWorld->Init();
}

void Display(void)
{
	currentWorld->Display();
}

void Idle(void)
{
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
	GAMEWIDTH = w;
	GAMEHEIGHT = h;

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

/*void timer(int n)
{
	glutPostRedisplay();
	glutTimerFunc(1000/n, timer, n);
}*/
