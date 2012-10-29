#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <GL\freeglut.h>
#include <SDL.h>
#include "WorldManager.h"

//-----------------------------------------------------------------------------

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

WorldManager manager = WorldManager();

int main(int argc, char** argv)
{
	// OpenGL Initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(1280, 960);

	glutCreateWindow("Window");

	manager.GetCurrentWorld()->Init();
	
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

	if(manager.GetCurrentWorldEnum() == GAMEWORLD)
	{
		glutCreateSubWindow (1, 200, 810, 880, 150); //(1, 200, 810, 880, 150); 
		glutDisplayFunc(GUI);
	}
	else
	{
		glutDestroyWindow(2);
	}

	glutMainLoop();

	return 0;
}

void Display(void)
{
	manager.GetCurrentWorld()->Display();
}

void Idle(void)
{
	manager.GetCurrentWorld()->Idle();
}

void Keyboard(unsigned char key, int x, int y)
{
	manager.GetCurrentWorld()->Keyboard(key, x, y);
}

void Mouse(int button, int state, int mouseX, int mouseY)
{
	manager.GetCurrentWorld()->Mouse(button, state, mouseX, mouseY);
}

void Reshape(int w, int h)
{
	manager.GetCurrentWorld()->Reshape(w, h);
}

void MovementKeys(int key, int x, int y)
{
	manager.GetCurrentWorld()->MovementKeys(key, x, y);
}

void ReleaseKey(int key, int x, int y)
{
	manager.GetCurrentWorld()->ReleaseKey(key, x, y);
}

void ReleaseKeys(unsigned char key, int x, int y)
{
	manager.GetCurrentWorld()->ReleaseKeys(key, x, y);
}

void MouseMove(int x, int y)
{
	manager.GetCurrentWorld()->MouseMove(x, y);
}

void GUI()
{
	manager.GetCurrentWorld()->GUI();
}
