#include "GameWorld.h"

float back = 0.0;


GameWorld::GameWorld(void)
{
	level.LoadModel("./models/island.obj");

	player = new PlayerObj;
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
	if (h == 0 || w == 0) return;
	
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();

	gluPerspective(60.0,(GLdouble)w/(GLdouble)h,1.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h); 
}

void GameWorld::Display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera.Render(player->GetPosition());

	glPushMatrix();
		glScalef(30.0, 30.0, 30.0);
		level.DrawModel();
	glPopMatrix();

	//UpdateObjects();

	glFlush();
	glutSwapBuffers();
}

void GameWorld::Keyboard(unsigned char Key, int KeyX, int KeyY)
{
	if(Key == 'a')
	{
		player->ChangePosition(Vector3(0.0, 0.0, -1.0));
	}

	if(Key =='d')
	{
		player->ChangePosition(Vector3(0.0, 0.0, 1.0));
	}

	if(Key == 'w')
	{
		player->ChangePosition(Vector3(1.0, 0.0, 0.0));
	}

	if(Key == 's')
	{
		player->ChangePosition(Vector3(-1.0, 0.0, 0.0));
	}
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