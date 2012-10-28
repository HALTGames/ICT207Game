#include "GameWorld.h"
#include <time.h>

int minuser =0;
time_t seconds;
float back = 0.0;

GameWorld::GameWorld(void)
{
	frameCount = 0;
	currentTime = 0;
	previousTime = 0;
	fps = 0;
	lastdrawn = 0;

	level.LoadModel("./models/island.obj");

	player = new PlayerObj;
	AddObject(player);

	TerrainObj* terrain = new TerrainObj;
	AddObject(terrain);

	AI = new Bird;
	AddObject(AI);
	



	left = right = forward = back = false;
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
	CalculateFPS();
	//std::cout << fps << std::endl;

	lastdrawn = glutGet(GLUT_ELAPSED_TIME);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera.Render(player->GetPosition());

	PlayerMovement();

	
	
	

	glPushMatrix();
		glScalef(30.0, 30.0, 30.0);
		level.DrawModel();
	glPopMatrix();

	UpdateObjects();

	glFlush();
	glutSwapBuffers();	
}

void GameWorld::Idle()
{
	if(glutGet(GLUT_ELAPSED_TIME) - lastdrawn > 1000/85)
	{
		glutPostRedisplay();
	}
}

void GameWorld::Keyboard(unsigned char Key, int KeyX, int KeyY)
{
	if(Key == 'a')
	{
		left = true;
	}

	if(Key =='d')
	{
		right = true;
	}

	if(Key == 'w')
	{
		forward = true;
	}

	if(Key == 's')
	{
		back = true;
	}

	if(Key == 'o')
	{
		camera.ChangeHeight(2);
	}

	if(Key == 'l')
	{
		camera.ChangeHeight(-2);
	}

	if(Key == 'i')
	{
		camera.ChangeBehind(2);
	}

	if(Key == 'k')
	{
		camera.ChangeBehind(-2);
	}

	glutPostRedisplay();
}

void GameWorld::Mouse(int Button, int State, int MouseX, int MouseY)
{

}

void GameWorld::PlayerMovement()
{
	if(left)
	{
		player->ChangePosition(Vector3(0.0, 0.0, -0.1));
	}

	if(right)
	{
		player->ChangePosition(Vector3(0.0, 0.0, 0.1));
	}

	if(forward)
	{
		player->ChangePosition(Vector3(0.1, 0.0, 0.0));
	}

	if(back)
	{
		player->ChangePosition(Vector3(-0.1, 0.0, 0.0));
	}
}

void GameWorld::MovementKeys(int key, int x, int y)
{
}

void GameWorld::ReleaseKey(int key, int x, int y)
{

}

void GameWorld::ReleaseKeys(unsigned char key, int x, int y)
{
	if(key == 'a')
	{
		left = false;
	}

	if(key =='d')
	{
		right = false;
	}

	if(key == 'w')
	{
		forward = false;
	}

	if(key == 's')
	{
		back = false;
	}
}

void GameWorld::MouseMove(int x, int y)
{

}

void GameWorld::UpdateObjects() const
{
	
	AI->Update(player->GetPosition());
	//AI->ChangePosition(AI->GetDirection());
	
	
	for(CItrGameObj itr = objects.begin(); itr != objects.end(); itr++)
	{
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

void GameWorld::CalculateFPS()
{
	frameCount++;

	currentTime = glutGet(GLUT_ELAPSED_TIME);

	elapsedTime = currentTime - previousTime;

	if(elapsedTime > 1000)
	{
		fps = frameCount / (elapsedTime / 1000.0);
		previousTime = currentTime;
		frameCount = 0;
	}
}