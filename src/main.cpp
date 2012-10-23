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
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int mouseX, int mouseY);
void Reshape(int w, int h);
void MovementKeys(int key, int x, int y);
void ReleaseKey(int key, int x, int y);
void ReleaseKeys(unsigned char key, int x, int y);
void MouseMove(int x, int y);

World* currentWorld = NULL;

int main(int argc, char** argv)
{
	// OpenGL Initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	GAMEWIDTH = 800;
	GAMEHEIGHT = 600;

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
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);
	glutReshapeFunc(Reshape);

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
			currentWorld = new ShaysWorld();
			break;
		case GAMEWORLD:
			currentWorld = new GameWorld();
			break;
	}

	currentWorld->Init();
}

void Display(void)
{
	currentWorld->Display();
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