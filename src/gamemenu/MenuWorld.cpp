#include "MenuWorld.h"

void MenuWorld::Init()
{
	windowWidth = 1280, windowHeight = 960;

	glutSetWindow(1);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);

	currWorld = MENUWORLD;

	MenuChoice = 0;
	Exit = false;

	glMatrixMode(GL_MODELVIEW);

	Loader[0].LoadModel("./models/MenuTitle.obj");
	Loader[1].LoadModel("./models/MenuNew.obj");
	Loader[2].LoadModel("./models/MenuShay.obj");
	Loader[3].LoadModel("./models/MenuExit.obj");
	Loader[4].LoadModel("./models/MenuArrow.obj");
	Loader[5].LoadModel("./models/MenuSplash.obj");
}

void MenuWorld::Reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
   // gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode (GL_MODELVIEW);

	//update vars
    windowWidth = w;
    windowHeight = h;
}

void MenuWorld::Display()
{
	if(Exit == false)
	{
		glutSetWindow(1);
		glClearColor (0.0, 0.0, 0.0, 0.0); 
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glLoadIdentity();
		glPushMatrix();
				glRotatef(90,1,0,0);
				glScalef(0.5, 0.5, 0.5);
				glTranslatef(0.0,0.0,-1.5);
				Loader[0].DrawModel();
		glPopMatrix();
		glPushMatrix();
				glRotatef(90,1,0,0);
				glScalef(0.14, 0.14, 0.14);
				glTranslatef(-0.06,0.0,-1.0);
				Loader[1].DrawModel();
		glPopMatrix();
		glPushMatrix();
				glRotatef(90,1,0,0);
				glScalef(0.15, 0.15, 0.15);
				glTranslatef(0.0,0.0,0.5);
				Loader[2].DrawModel();
		glPopMatrix();
		glPushMatrix();
				glRotatef(90,1,0,0);
				glScalef(0.07, 0.10, 0.12);
				glTranslatef(-1.1,0.0,2.0);
				Loader[3].DrawModel();
		glPopMatrix();

		switch(MenuChoice)
		{
		case 1:
			{
				glPushMatrix();
					glRotatef(90,1,0,0);
					glScalef(0.08, 0.10, 0.10);
					glTranslatef(-2.2,0.0,-1.4);
					Loader[4].DrawModel();
				glPopMatrix();

				break;
			}
		case 2:
			{
				glPushMatrix();
					glRotatef(90,1,0,0);
					glScalef(0.08, 0.10, 0.10);
					glTranslatef(-2.2,0.0,0.65);
					Loader[4].DrawModel();
				glPopMatrix();
				break;
			}
		case 3:
			{	
				glPushMatrix();
					glRotatef(90,1,0,0);
					glScalef(0.08, 0.10, 0.10);
					glTranslatef(-2.2,0.0,2.5);
					Loader[4].DrawModel();
				glPopMatrix();
				break;
			}
		}
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glPushMatrix();
			glRotatef(90,1,0,0);
			glScalef(0.8, 1.0, 1.0);
			glTranslatef(0,0.0,-0.1);
			Loader[5].DrawModel();
		glPopMatrix();
	}
    glutSwapBuffers();
}

void MenuWorld::Idle()
{

}

void MenuWorld::DisplayExit()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	glutSwapBuffers();
}

void MenuWorld::Keyboard(unsigned char key, int keyX, int keyY)
{

}

void MenuWorld::Mouse(int Button, int State, int mouseX, int mouseY)
{

	if(Button == GLUT_LEFT_BUTTON)
	{
		if(State == GLUT_DOWN)
		{
			if(Exit == false)
			{
				switch(MenuChoice)
				{
				case 1:
					{
						currWorld = GAMEWORLD;
						break;
					}
				case 2:
					{
						currWorld = SHAYSWORLD;
						break;
					}
				case 3:
					{
						Exit = true;
						DisplayExit();
						break;
					}
				}
			}
			else
			{
				 glutDestroyWindow (1);
				 exit (0);
			}
		}
	}
}

void MenuWorld::MovementKeys(int key, int x, int y)
{

}

void MenuWorld::ReleaseKey(int key, int x, int y)
{

}
void MenuWorld::ReleaseKeys(unsigned char key, int x, int y)
{

}
void MenuWorld::MouseMove(int x, int y)
{
	if(Exit == false)
	{
		if((y > 384) && (y < 440))
		{
			MenuChoice = 1;
			glutPostRedisplay();
		}
		else if((y > 484) && (y < 545))
		{
			MenuChoice = 2;
			glutPostRedisplay();
		}
		else if((y > 571) && (y < 615))
		{
			MenuChoice = 3;
			glutPostRedisplay();
		}
		else
		{
			MenuChoice = 0;
			glutPostRedisplay();
		}
	}
}