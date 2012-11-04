#include "GameWorld.h"

//------------------------------------------------------------------------------

float back = 0.0;
float lightx = 0, lighty =10, lightz =-5;
GLfloat light_position[] = { lightx, lighty, lightz, 0.0 };

//------------------------------------------------------------------------------

GameWorld::~GameWorld(void)
{
}

//------------------------------------------------------------------------------

void GameWorld::Init(void)
{

	GLfloat lmodel_ambient[] = { 3.3, 3.3, 3.3, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	GLfloat light1_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat light1_diffuse[] = { 1, 1, 1, 1 };
	GLfloat light1_specular[] = { 4.0, 4.0, 4.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light1_specular);
	//glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
	 glEnable(GL_LIGHT0);

	
	SoundController = new sounds;
	
	SoundController->SoundMenu();
	SoundController->PausePlaySoundTrack();
	SoundController->addSound("sounds/fireball.wav", "Spell");
	

	glEnable(GL_TEXTURE_2D);

	lastdrawn = 0;

	level.LoadModel("./models/island.obj");

	AImanage = new AIManager();
	playerObj = new PlayerObj();

	terrainObj = new TerrainObj();
	reticuleObj = new ReticuleObj;

	left = right = forward = back = false;

	currWorld = GAMEWORLD;
	gameWidth = 1280, gameHeight = 960;
	
	glutSetWindowTitle("Blizzard, the motherfucking Wizard.");
	glEnable(GL_DEPTH_TEST);
}

//------------------------------------------------------------------------------

void GameWorld::Exit()
{
	delete playerObj;
	playerObj = NULL;

	delete reticuleObj;
	reticuleObj = NULL;
}

//------------------------------------------------------------------------------

void GameWorld::Reshape(int w, int h) 
{
	if (h == 0 || w == 0) return;
	
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();

	gluPerspective(60.0,(GLdouble)w/(GLdouble)h,1.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h); 

	gameWidth = w;
	gameHeight = h;
}

//------------------------------------------------------------------------------

void GameWorld::Display(void)
{
	SoundController->loopmain();
	glutSetWindow(1);

	lastdrawn = glutGet(GLUT_ELAPSED_TIME);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera.Render(playerObj->GetPosition());
	playerObj->Display();
	reticuleObj->Display();
	terrainObj->Display();

	PlayerMovement();
	Vector3 difference = reticuleObj->GetPosition()
		- playerObj->GetPosition();
	double angle = atan(difference.x / difference.z) * (180 / PI);
	if(difference.z < 0)
	{
		playerObj->SetAngle(angle+180);
	}
	else
	{
		playerObj->SetAngle(angle);
	}

	glPushMatrix();
		glScalef(50.0, 50.0, 50.0);
		glTranslatef(0,-0.40,0);
		level.DrawModel();
	glPopMatrix();

	ProjectileManager::UpdateProjectiles();
	
	AImanage->CheckForAICreate();
	AImanage->UpdateAI(playerObj->GetPosition());

	glFlush();
	glutSwapBuffers();	
}

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

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
	if(playerObj->GetInventoryStatus(1) == true)
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
		glVertex3f((0.32*playerObj->GetHealth()/76.2-0.1),0.14,-0.1);
		glVertex3f((0.32*playerObj->GetHealth()/76.2-0.1),-0.14,-0.1);
		glEnd();
	glPopMatrix();
	//manabar
	glPushMatrix();
	glColor3f (0.0F, 0.0F, 1.0F); 
	glTranslatef(-0.778, -0.035, 0);
	glBegin(GL_QUADS);
		glVertex3f(-0.1,-0.14,-0.1);
		glVertex3f(-0.1,0.14,-0.1);
		glVertex3f((0.32*playerObj->GetMana()/76.2-0.1),0.14,-0.1);
		glVertex3f((0.32*playerObj->GetMana()/76.2-0.1),-0.14,-0.1);
		glEnd();
	glPopMatrix();
	glutSwapBuffers ();
	//return to main window
	glutSetWindow(1);
}

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

void GameWorld::ManaRegen()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	if((time / 1000)-1 >=  ManaTimer/1000)
	{
		//everysecond gain 1 mana.
		playerObj->ModifyMana(1);
		ManaTimer = time;
	}	
}

//------------------------------------------------------------------------------

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
	if(Key == '1')
	{
		playerObj->SelectSpell(1);
	}
	if(Key == '2')
	{
		playerObj->SelectSpell(2);
	}

	if(Key == 'p')
	{
		SoundController->StopMusic();
		delete SoundController;
		currWorld = SHAYSWORLD;	
	}
	glutPostRedisplay();
}

//------------------------------------------------------------------------------

void GameWorld::Mouse(int Button, int State, int MouseX, int MouseY)
{
	SetReticulePosition(MouseX, MouseY);

	if(Button == GLUT_LEFT_BUTTON)
	{
		//activate left button code
		if(State == GLUT_UP)
		{

		}
		else if(State == GLUT_DOWN)
		{
			SoundController->playSound("Spell");
			std::cout << "Mouse Pressed" << std::endl;
			playerObj->Shoot(reticuleObj->GetPosition().x, 
				reticuleObj->GetPosition().z);
		}
	}
}

//------------------------------------------------------------------------------

void GameWorld::PlayerMovement()
{
	if(left)
	{
		playerObj->ChangePosition(Vector3(0.0, 0.0, -0.1));
		reticuleObj->ChangePosition(Vector3(0.0, 0.0, -0.1));
	}

	if(right)
	{
		playerObj->ChangePosition(Vector3(0.0, 0.0, 0.1));
		reticuleObj->ChangePosition(Vector3(0.0, 0.0, 0.1));
	}

	if(forward)
	{
		playerObj->ChangePosition(Vector3(0.1, 0.0, 0.0));
		reticuleObj->ChangePosition(Vector3(0.1, 0.0, 0.0));
	}

	if(back)
	{
		playerObj->ChangePosition(Vector3(-0.1, 0.0, 0.0));
		reticuleObj->ChangePosition(Vector3(-0.1, 0.0, 0.0));
	}

}

//------------------------------------------------------------------------------

void GameWorld::MovementKeys(int key, int x, int y) {}

//------------------------------------------------------------------------------

void GameWorld::ReleaseKey(int key, int x, int y) {}

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

void GameWorld::MouseMove(int x, int y)
{
	SetReticulePosition(x, y);
}

//------------------------------------------------------------------------------

void GameWorld::SetReticulePosition(int x, int y)
{
	if(y > gameHeight - (gameHeight * 0.95))
	{
		GLdouble objx, objy, objz;
		double modelview[16], projection[16];
		int viewport[4];
		float z;
		//get the projection matrix		
		glGetDoublev( GL_PROJECTION_MATRIX, projection );
		//get the modelview matrix		
		glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
		//get the viewport		
		glGetIntegerv( GL_VIEWPORT, viewport );
		
		glReadPixels( x, viewport[3]-y, 1, 1,
			 GL_DEPTH_COMPONENT, GL_FLOAT, &z );

		gluUnProject( x, viewport[3]-y, z, modelview, 
			projection, viewport, &objx, &objy, &objz );

		reticuleObj->SetPosition(Vector3(objx, 1, objz));
	}
}

//------------------------------------------------------------------------------