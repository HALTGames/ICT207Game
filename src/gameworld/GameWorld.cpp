#include "GameWorld.h"



GameWorld::GameWorld(void)
{
}


GameWorld::~GameWorld(void)
{
}


void GameWorld::Display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glFlush();
	glutSwapBuffers();
}

void GameWorld::Keyboard(unsigned char Key, int KeyX, int KeyY)
{
	toupper(Key);
	switch(Key)
	{
		case 'W'://move camera up
		{
			GameWorld::Camera.MoveCamera(0, 0, -0.2);
			break;
		}
		case 'A'://move camera to the left
		{
			GameWorld::Camera.MoveCamera(0.2, 0, 0);
			break;
		}
		case 'S'://move camera down
		{
			GameWorld::Camera.MoveCamera(0, 0, 0.2);
			break;
		}
		case 'D'://move camera right
		{
			GameWorld::Camera.MoveCamera(-0.2, 0, 0);
			break;
		}
	}

}

void GameWorld::Mouse(int Button, int State, int MouseX, int MouseY)
{

}

void GameWorld::SpecialKeyFunc(void)
{

}

void GameWorld::Init(void)
{
		glutSetWindowTitle("Blizzard, the motherfucking Wizard.");
}