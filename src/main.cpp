#define GLUT_DISABLE_ATEXIT_HACK

#include <GL\freeglut.h>
#include <SDL.h>

#include "World.h"
#include "shaysworld\ShaysWorld.h"
//#include "GameMain.h"

void Display(void);
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int mouseX, int mouseY);
void Reshape(int w, int h);
void MovementKeys(int key, int x, int y);
void ReleaseKey(int key, int x, int y);
void ReleaseKeys(unsigned char key, int x, int y);
void MouseMove(int x, int y);

World* currentWorld;
ShaysWorld* shays = new ShaysWorld();
//GameMain* game = NULL;

bool isShays = true;

int main(int argc, char** argv)
{
	currentWorld = shays;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Window");

	currentWorld->Init();
	
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(MovementKeys);
	glutSpecialUpFunc(ReleaseKey);
	glutKeyboardUpFunc (ReleaseKeys);
	glutKeyboardFunc(Keyboard);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);
	
	// ONLY USE IF REQUIRE MOUSE MOVEMENT
	//glutPassiveMotionFunc(mouseMove);
	//ShowCursor(FALSE);

	glutReshapeFunc(Reshape);
	glutMainLoop();

	return 0;
}

void SwitchWorld()
{
/*	if(currentWorld->changeWorld)
	{
		if(isShays)
		{
			delete shays;
			shays = NULL;

//			game = new GameMain();
			currentWorld = game;

			currentWorld->Init();

			isShays = false;
		}
		else
		{
			delete game;
			game = NULL;

			shays = new ShaysMain();
			currentWorld = shays;

			currentWorld->Init();

			isShays = true;
		}
	}*/
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