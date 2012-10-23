#include "GameWorld.h"

float back = 0.0;

GameWorld::GameWorld(void)
{
	level.LoadModel("./models/island.obj");

	PlayerObj* player = new PlayerObj;
	AddObject(player);
}


GameWorld::~GameWorld(void)
{
}

void GameWorld::Init(void)
{
	glutSetWindowTitle("Blizzard, the motherfucking Wizard.");
	glEnable(GL_DEPTH_TEST);
}

void GameWorld::Reshape(int w, int h) 
{

}

void GameWorld::Display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera.SetTarget(Vector3(0.0, 100.0, 0.0));

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		level.DrawModel();
	glPopMatrix();

	UpdateObjects();

	glFlush();
	glutSwapBuffers();
}

void GameWorld::Keyboard(unsigned char Key, int KeyX, int KeyY)
{
}

void GameWorld::Mouse(int Button, int State, int MouseX, int MouseY)
{

}

void GameWorld::MovementKeys(int key, int x, int y)
{
}

void GameWorld::ReleaseKey(int key, int x, int y)
{

}

void GameWorld::ReleaseKeys(unsigned char key, int x, int y)
{

}

void GameWorld::MouseMove(int x, int y)
{

}

void GameWorld::UpdateObjects() const
{
	for(CItrGameObj itr = objects.begin(); itr != objects.end(); itr++)
	{
		(itr->second)->Update();
		(itr->second)->Display();
	}
}

void GameWorld::AddObject(GameObj* obj)
{
	objects[obj->GetIdentificationNumber()] = obj;
}

void GameWorld::RemoveObject(int idnum)
{
	objects.erase(idnum);
}