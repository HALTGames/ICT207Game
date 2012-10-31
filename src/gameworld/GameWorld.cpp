#include "GameWorld.h"
#include <time.h>

int minuser =0;
time_t seconds;
float back = 0.0;

GameWorld::~GameWorld(void)
{
}

void GameWorld::Init(void)
{
	objectManager = new GameObjManager;

	RandomAI = 0;
	ShooterList = new list<Shooter*>;
	BirdList = new list<Bird*>;
	AlligatorList = new list<Alligator*>;
	StraferList = new list<Strafer*>;
	SoundController = new sounds;
	SoundController->SoundMenu();
	SoundController->PausePlaySoundTrack();
	glEnable(GL_TEXTURE_2D);

	lastdrawn = 0;

	level.LoadModel("./models/island.obj");

	TerrainObj* terrain = new TerrainObj;
	objectManager->AddObject(terrain);

	player = new PlayerObj;
	objectManager->AddObject(player);

	//AddObject(AIBird);

	left = right = forward = back = false;

	currWorld = GAMEWORLD;

	srand(time(0));
	glutSetWindowTitle("Blizzard, the motherfucking Wizard.");
	glEnable(GL_DEPTH_TEST);
	/* Probably never work due to glm fuckery
	//TextureLoad.LoadTexture("textures/UIbackground.RAW",791,151,1);
	float width, height;
	width = 791;
	height = 151;
	//TextureLoad.SetTexture(glmLoadTexture("textures/UIbackground.RAW", GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE, &width, &height));
	*/
}

void GameWorld::Exit()
{
	delete objectManager;
	objectManager = NULL;
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
	SoundController->loopmain();
	glutSetWindow(1);

	lastdrawn = glutGet(GLUT_ELAPSED_TIME);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera.Render(player->GetPosition());

	PlayerMovement();

	glPushMatrix();
		glScalef(50.0, 50.0, 50.0);
		glTranslatef(0,-0.35,0);
		level.DrawModel();
	glPopMatrix();

	objectManager->UpdateObjects();
	CreateAI();

	glFlush();
	glutSwapBuffers();	
}
void GameWorld::GUIinit(void)
{
	glutSetWindow(2);

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	ModelLoader[0].LoadModel("./models/UIback.obj");
	ModelLoader[1].LoadModel("./models/uibar.obj");
	ModelLoader[2].LoadModel("./models/uiscroll.obj");
	ModelLoader[3].LoadModel("./models/uibarouter.obj");
	ModelLoader[4].LoadModel("./models/uiMagicMissile.obj");
	ModelLoader[5].LoadModel("./models/uiProtection.obj");
}

void GameWorld::GUI(void)
{
	glutSetWindow(2);
	glClearColor (0.25, 0.25, 0.25, 0.0); 
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glColor4f(1.0, 1.0, 1.0, 1.0);

	//ui back
	glLoadIdentity();
		glPushMatrix();
		glScalef(50,260,0);
		glRotatef(90,1,0,0);
		ModelLoader[0].DrawModel();
	glPopMatrix();
	//ui bar
	glPushMatrix();
		glTranslatef(0.5, -0.05, -0.01);
		glScalef(0.25,1,1);
		glScalef(1.6,1.6,1);
		glRotatef(90,1,0,0);
		ModelLoader[1].DrawModel();
	glPopMatrix();
	//ui scroll
	if(Character.GetInventoryStatus(1) == true)
	{
		glPushMatrix();
			glTranslatef(0.79, -0.04, -0.02);
			glScalef(0.2,1,1);
			glScalef(0.55,0.55,1);
			glRotatef(90,1,0,0);
			ModelLoader[2].DrawModel();
		glPopMatrix();
	}
	//MM - basic attack
	glPushMatrix();
		glTranslatef(0.225, -0.04, -0.02);
		glScalef(0.2,1,1);
		glScalef(0.3,0.3,1);
		glRotatef(90,1,0,0);
		ModelLoader[4].DrawModel();
	glPopMatrix();
	//Protection - sphere defence
	glPushMatrix();
		glTranslatef(0.417, -0.04, -0.02);
		glScalef(0.2,1,1);
		glScalef(0.3,0.3,1);
		glRotatef(90,1,0,0);
		ModelLoader[5].DrawModel();
	glPopMatrix();
	//statbar outers
	glPushMatrix();
		glTranslatef(-0.67, -0.04, -0.02);
		glScalef(0.2,1,1);
		glScalef(1.3,1.3,1);
		glRotatef(90,1,0,0);
		ModelLoader[3].DrawModel();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.67, 0.33, -0.02);
		glScalef(0.2,1,1);
		glScalef(1.3,1.3,1);
		glRotatef(90,1,0,0);
		ModelLoader[3].DrawModel();
	glPopMatrix();
	//healthbar
	glPushMatrix();
	glColor3f (1.0F, 0.0F, 0.0F); 
	glTranslatef(-0.778, 0.33, 0);
	glBegin(GL_QUADS);
		glVertex3f(-0.1,-0.14,-0.1);
		glVertex3f(-0.1,0.14,-0.1);
		glVertex3f((0.32*Character.GetHealth()/76.2-0.1),0.14,-0.1);
		glVertex3f((0.32*Character.GetHealth()/76.2-0.1),-0.14,-0.1);
		glEnd();
	glPopMatrix();
	//manabar
	glPushMatrix();
	glColor3f (0.0F, 0.0F, 1.0F); 
	glTranslatef(-0.778, -0.035, 0);
	glBegin(GL_QUADS);
		glVertex3f(-0.1,-0.14,-0.1);
		glVertex3f(-0.1,0.14,-0.1);
		glVertex3f((0.32*Character.GetMana()/76.2-0.1),0.14,-0.1);
		glVertex3f((0.32*Character.GetMana()/76.2-0.1),-0.14,-0.1);
		glEnd();
	glPopMatrix();
	glutSwapBuffers ();
}

void GameWorld::Idle()
{
	if(glutGet(GLUT_ELAPSED_TIME) - lastdrawn > 1000/85)
	{
		ManaRegen();
		glutSetWindow(1);
		glutPostRedisplay();
		glutSetWindow(2);
		glutPostRedisplay();
	}
}

void GameWorld::ManaRegen()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	if((time / 1000)-1 >=  ManaTimer/1000)
	{
		//everysecond gain 1 mana.
		Character.ModifyMana(1);
		ManaTimer = time;
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
		SoundController->PausePlaySoundTrack();
	}

	if(Key == 'p')
	{
		WipeAI();
		SoundController->StopMusic();
		delete SoundController;
		currWorld = SHAYSWORLD;
		
		
	}
	glutPostRedisplay();
}

void GameWorld::Mouse(int Button, int State, int MouseX, int MouseY)
{
	if(Button == GLUT_LEFT_BUTTON)
	{
		//activate left button code
		if(State == GLUT_UP)
		{

		}
		else if(State == GLUT_DOWN)
		{
			if(Character)
			{
				ProjectileObj Projectile();
			}
		}
	}
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

void GameWorld::CreateAI() 
{
	seconds = time(NULL);
	if(seconds>minuser+1)
	{
	Vector3 Placement;
	
	Placement.x = (rand() %40)-20 ;
	Placement.y = 0;
	Placement.z = (rand() %40)-20 ;
	minuser = seconds;
	RandomAI = rand() %4;
	cout<<RandomAI<<"   RANDOM AI NUM \n";
	switch(RandomAI)
	{
	case 0:
		{
			cout<<"BirdCreated \n";
			AIBird = new Bird;
			AIBird->SetPosition(Placement);
			BirdList->push_back(AIBird);
			//delete[] AIBird;
			break;
		}
	case 1:
		{
			cout<<"ShooterCreated \n";
			AIShooter = new Shooter;
			AIShooter->SetPosition(Placement);
			ShooterList->push_back(AIShooter);
			//delete[] AIShooter;
			break;
		}
	case 2:
		{
			cout<<"AlligatorCreated \n";
			AIAlligator = new Alligator;
			AIAlligator->SetPosition(Placement);
			AlligatorList->push_back(AIAlligator);
			//delete[] AIAlligator;
			break;
		}
	case 3:
		{
			cout<<"StraferCreated \n";
			AIStrafer = new Strafer;
			AIStrafer->SetPosition(Placement);
			StraferList->push_back(AIStrafer);
			break;
		}

	}
	
	//delete AIBird;
	}


	list<Bird*>::iterator itr;
	for(itr=BirdList->begin(); itr != BirdList->end(); ++itr)
	{
		(*itr)->SubtractHealth(1);
		(*itr)->Update(player->GetPosition());
		(*itr)->Display();
		if((*itr)->GetHealth() < 0)
		{
			itr = BirdList->erase(itr);
		}

	}

	list<Shooter*>::iterator itrs;
	for(itrs=ShooterList->begin(); itrs != ShooterList->end(); ++itrs)
	{
		(*itrs)->SubtractHealth(1);
		(*itrs)->Update(player->GetPosition());
		(*itrs)->Display();
		if((*itrs)->GetHealth() < 0)
		{
			itrs = ShooterList->erase(itrs);
		}

	}

	list<Alligator*>::iterator itra;
	for(itra=AlligatorList->begin(); itra != AlligatorList->end(); ++itra)
	{
		(*itra)->SubtractHealth(1);
		(*itra)->Update(player->GetPosition());
		(*itra)->Display();
		if((*itra)->GetHealth() < 0)
		{
			itra = AlligatorList->erase(itra);
		}

	}

	list<Strafer*>::iterator itrst;
	for(itrst=StraferList->begin(); itrst != StraferList->end(); ++itrst)
	{
		(*itrst)->SubtractHealth(1);
		(*itrst)->Update(player->GetPosition());
		(*itrst)->Display();
		if((*itrst)->GetHealth() < 0)
		{
			itrst = StraferList->erase(itrst);
		}

	}

	
	//AIBird->Update(player->GetPosition());
	//AIBird->Display();
	//AI->ChangePosition(AI->GetDirection());
	//AI = new Bird;
	//AddObject(AI);

}

void GameWorld::WipeAI()
{
	
	
	list<Bird*>::iterator itr;
	for(itr=BirdList->begin(); itr != BirdList->end(); ++itr)
	{
		itr = BirdList->erase(itr);
		(*itr)->Display();
	}
	

	list<Shooter*>::iterator itrs;
	for(itrs=ShooterList->begin(); itrs != ShooterList->end(); ++itrs)
	{
		itrs = ShooterList->erase(itrs);
		(*itrs)->Display();
	}
	

	list<Alligator*>::iterator itra;
	for(itra=AlligatorList->begin(); itra != AlligatorList->end(); ++itra)
	{
		itra = AlligatorList->erase(itra);
		(*itra)->Display();
	}
	
	list<Strafer*>::iterator itrst;
	for(itrst=StraferList->begin(); itrst != StraferList->end(); ++itrst)
	{
		itrst = StraferList->erase(itrst);
		(*itrst)->Display();
	}
	
	//WipeAI();

	//delete[] BirdList;
	//delete[] AlligatorList;
	//delete[] ShooterList;
}