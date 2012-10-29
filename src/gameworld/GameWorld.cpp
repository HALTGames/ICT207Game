#include "GameWorld.h"
#include <time.h>

int minuser =0;
time_t seconds;
float back = 0.0;

GameWorld::GameWorld(void)
{
	SoundController.SoundMenu();
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

	//AddObject(AIBird);

	left = right = forward = back = false;
}


GameWorld::~GameWorld(void)
{
}

void GameWorld::Init(void)
{
	srand(time(0));
	glutSetWindowTitle("Blizzard, the motherfucking Wizard.");
	glEnable(GL_DEPTH_TEST);
	//TextureLoad.LoadTexture(1, "textures/UIfinal.png");
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
	SoundController.loopmain();
	glutSetWindow(1);
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
	CreateAI();

	glFlush();
	glutSwapBuffers();	
}


void GameWorld::GUI(void)
{
	glutSetWindow(2);
	glClearColor (0.25, 0.25, 0.25, 0.0); 
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
//	glBindTexture(GL_TEXTURE_2D, TextureLoad.GetTexture(1));
	glPushMatrix();

	glColor3f (1.0F, 1.0F, 1.0F); 
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-1.0f,-1.0f,0);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-1.0f,1.0f,0);
		glTexCoord2f(1.0,1.0);
		glVertex3f(1.0f,1.0f,0);
		glTexCoord2f(1.0,0.0);
		glVertex3f(1.0f,-1.0f,0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//healthbar
	glPushMatrix();
	glColor3f (1.0F, 0.0F, 0.0F); 
	glTranslatef(-0.7, 0.5, 0);
	glBegin(GL_QUADS);
		glVertex3f(-0.1,-0.1,-0.1);
		glVertex3f(-0.1,0.1,-0.1);
		glVertex3f((0.2*Character.GetHealth()/66.6-0.1),0.1,-0.1);
		glVertex3f((0.2*Character.GetHealth()/66.6-0.1),-0.1,-0.1);
		glEnd();
	glPopMatrix();
	//manabar
	glPushMatrix();
	glColor3f (0.0F, 0.0F, 1.0F); 
	glTranslatef(-0.7, 0.2, 0);
	glBegin(GL_QUADS);
		glVertex3f(-0.1,-0.1,-0.1);
		glVertex3f(-0.1,0.1,-0.1);
		glVertex3f((0.2*Character.GetMana()/66.6-0.1),0.1,-0.1);
		glVertex3f((0.2*Character.GetMana()/66.6-0.1),-0.1,-0.1);
		glEnd();
	glPopMatrix();
	glutSwapBuffers ();
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
	if(Key == 'm')
	{
		SoundController.PausePlaySoundTrack();
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

void GameWorld::CreateAI() 
{
	seconds = time(NULL);
	if(seconds>minuser+10)
	{
	Vector3 Placement;
	
	Placement.x = (rand() %40)-20 ;
	Placement.y = 0;
	Placement.z = (rand() %40)-20 ;
	minuser = seconds;
	AIBird = new Bird;
	AIBird->SetPosition(Placement);
	BirdList.push_back(AIBird);
	//delete AIBird;
	}


	list<Bird*>::iterator itr;
	for(itr=BirdList.begin(); itr != BirdList.end(); ++itr)
	{
		(*itr)->SubtractHealth(1);
		(*itr)->Update(player->GetPosition());
		(*itr)->Display();
		if((*itr)->GetHealth() < 0)
		{
			itr = BirdList.erase(itr);
		}

	}

	
	//AIBird->Update(player->GetPosition());
	//AIBird->Display();
	//AI->ChangePosition(AI->GetDirection());
	//AI = new Bird;
	//AddObject(AI);

}