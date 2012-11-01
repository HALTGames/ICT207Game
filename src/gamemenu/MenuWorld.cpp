#include "MenuWorld.h"


MenuWorld::MenuWorld(void)
{
	GLuint texture; // stores the current texture being used

	windowWidth = 500;//window width
	windowHeight = 500;//window height

	menuPos = 1; //Menu position, initialised to first spot
	maxEntries = 4; //Max amount of menu items

	menuDist = 0.5;//Distance apart each menu element is

	//Defines a menu element polygon size,
	p1[0] = 0,0,0;
	p2[0] = 2,0,0.0;
	p3[0] = 2,2,0.0;
	p4[0] = 0,2,0.0;

	//for the selection arrow element
	p5[0] = 0.5,0,0.0;
	p6[0] = 0.5,0.5,0.0;
	p7[0] = 0,0.5,0.0;
}

void MenuWorld::Init()
{
	glClearColor (0.0, 0.0, 0.0, 1.0);  
   glColor3f(1.0,0.0,0.0);
   //glEnable(GL_DEPTH_TEST); //alpha channel will not work if this is enabled
   glLineWidth(5.0);
   //glShadeModel (GL_SMOOTH);

   glEnable( GL_TEXTURE_2D );
   glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, 1, 1.0, 1000.0);
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
}

void MenuWorld::Reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode (GL_MODELVIEW);

	//update vars
   windowWidth = w;
   windowHeight = h;
}

void MenuWorld::Display()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();             
		   
   gluLookAt (0.0f, 0.0f, 5.0f, //5 units backward from the origin
				0.0f, 0.0f, 0.0f, 
				0.0f, 1.0f, 0.0f);

   //drawDivision();
   DrawMenu();

   glutSwapBuffers();
}

void MenuWorld::Idle()
{
	animate();
}

void MenuWorld::Keyboard(unsigned char key, int keyX, int keyY)
{
	switch (key) {
		case 13: 
			MenuSelect();
			break;
		case 27:
			exit(EXIT_SUCCESS);
			break;
	}
}

void MenuWorld::Mouse(int button, int state, int mouseX, int mouseY)
{
	switch(button){
		case GLUT_LEFT_BUTTON:
			MenuSelect();
			break;
	}
}

void MenuWorld::MovementKeys(int key, int x, int y)
{
}

void MenuWorld::ReleaseKey(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP: 
			MenuUp();
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN: 
			MenuDown(); 
			glutPostRedisplay();
			break;
	}
}

void MenuWorld::ReleaseKeys(unsigned char key, int x, int y)
{
}

void MenuWorld::MouseMove(int x, int y)
{
	if(x < (windowWidth/3)+(windowWidth/3) && (x > (windowWidth/3)))
	{
		//std::cout << "left/right check working" << "\n";
		if(y > (windowHeight/11)*5 && (y < (windowHeight/11)*6))
		{
			menuPos = 1;
			glutPostRedisplay();
		}
		else if(y > (windowHeight/11)*6 && (y < (windowHeight/11)*7))
		{
			menuPos = 2;
			glutPostRedisplay();
		}
		else if(y > (windowHeight/11)*7 && (y < (windowHeight/11)*8))
		{
			menuPos = 3;
			glutPostRedisplay();
		}
		else if(y > (windowHeight/11)*8 && (y < (windowHeight/11)*9))
		{
			menuPos = 4;
			glutPostRedisplay();
		}
	}
}

void MenuWorld::drawIsland()
{
    if (!island) 
	{
        island = glmReadOBJ("models/island.obj");	
        if (!island) exit(0);
        glmUnitize(island);
        glmFacetNormals(island);        
		glmVertexNormals(island, 90.0);
    }
    glmDraw(island, GLM_SMOOTH| GLM_TEXTURE);
}

void MenuWorld::drawSkybox()
{
    if (!skybox) 
	{
        skybox = glmReadOBJ("models/skybox.obj");	
        if (!skybox) exit(0);
        glmUnitize(skybox);
        glmFacetNormals(skybox);        
		glmVertexNormals(skybox, 90.0);
    }
    glmDraw(skybox, GLM_SMOOTH| GLM_TEXTURE);
}

void MenuWorld::animate()
{
	ypoz+=0.01;
	if (ypoz>360) ypoz=0;
	glutPostRedisplay();
}

void MenuWorld::DrawMenu()
{
	glPushMatrix();//draw the island
		glEnable(GL_DEPTH_TEST);
		glTranslatef(0,0,0);
		glScalef(3,3,3);
		glRotatef(45,1,0,0);
		glRotatef(ypoz,0,1,0);
		drawIsland();
		glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();//draw the skybox
		glEnable(GL_DEPTH_TEST);
		glTranslatef(0,0,0);
		glScalef(5,5,5);
		glRotatef(135,1,0,0);
		drawSkybox();
		glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
		//Load our texture
		texture = RAWTexture::LoadTexture( "textures/start_icon_alpha.raw", 256, 256 );
		glColor4f(1,1,1,1);
		glTranslatef(-1,-1,0);
		DrawBox();

		texture = RAWTexture::LoadTexture( "textures/settings_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		DrawBox();

		texture = RAWTexture::LoadTexture( "textures/help_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		DrawBox();

		texture = RAWTexture::LoadTexture( "textures/exit_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		DrawBox();
		//Free our texture
		RAWTexture::FreeTexture( texture );
	glPopMatrix();
	
	glPushMatrix();
		glColor4f(1,1,1,1);
		glTranslatef(-0.1,-0.2,0);
		if(menuPos == 1)
		{
			glTranslatef(1.2,0,0);
			DrawSelectionBox();
		}
		else if(menuPos == 2)
		{
			glTranslatef(1.2,-menuDist,0);
			DrawSelectionBox();
		}
		else if(menuPos == 3)
		{
			glTranslatef(1.2,-menuDist*2,0);
			DrawSelectionBox();
		}
		else
		{
			glTranslatef(1.2,-menuDist*3,0);
			DrawSelectionBox();
		}
	glPopMatrix();

	glPushMatrix();
		glColor4f(1,1,1,1);
		glTranslatef(-1.4,0.4,0);
		texture = RAWTexture::LoadTexture( "textures/banner_alpha.raw", 512, 512 );
		DrawBanner();
		RAWTexture::FreeTexture( texture );
	glPopMatrix();
}

void MenuWorld::DrawBanner()
{
	glBegin(GL_POLYGON);
		glTexCoord3f(0,1,0); glVertex3f(0,0,0);
		glTexCoord3f(1,1,0); glVertex3f(3,0,0);
		glTexCoord3f(1,0,0); glVertex3f(3,3,0);
		glTexCoord3f(0,0,0); glVertex3f(0,3,0);
	glEnd();
}

void MenuWorld::DrawSelectionBox()
{
	texture = RAWTexture::LoadTexture( "textures/select_icon_alpha.raw", 256, 256 );
	glBegin(GL_POLYGON);
		glTexCoord3f(0,1,0); glVertex3fv(p1);
		glTexCoord3f(1,1,0); glVertex3fv(p5);
		glTexCoord3f(1,0,0); glVertex3fv(p6);
		glTexCoord3f(0,0,0); glVertex3fv(p7);
	glEnd();
	glTranslatef(-2.75,-0.05,0);
	glBegin(GL_POLYGON); 
		glTexCoord3f(1,0,0); glVertex3fv(p1);
		glTexCoord3f(0,0,0); glVertex3fv(p5);
		glTexCoord3f(0,1,0); glVertex3fv(p6);
		glTexCoord3f(1,1,0); glVertex3fv(p7);
	glEnd();
	RAWTexture::FreeTexture( texture );
}

void MenuWorld::DrawBox()
{
	glBegin(GL_POLYGON); 
		glTexCoord3f(0,1,0); glVertex3fv(p1);
		glTexCoord3f(1,1,0); glVertex3fv(p2);
		glTexCoord3f(1,0,0); glVertex3fv(p3);
		glTexCoord3f(0,0,0); glVertex3fv(p4);
	glEnd();
}

void MenuWorld::DrawDivision()
{
	glColor4f(0,1,0,1);//green

	glPushMatrix();
	glTranslatef(-1,-3,0);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,4,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	
	glTranslatef(1,-3,0);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,4,0);
	glEnd();
	
	glPopMatrix();
}

void MenuWorld::MenuSelect()
{
	switch(menuPos){
		case 1:
			//START GAME HERE
			break;
		case 2:
			//GO TO SETTINGS HERE
			break;
		case 3:
			//GO TO HELP HERE
			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
	}
}

void MenuWorld::MenuDown()
{
	if(menuPos==maxEntries)
	{
		menuPos = 1;
	}
	else
	{
		menuPos++;
	}
}

void MenuWorld::MenuUp()
{
	if(menuPos==1)
	{
		menuPos = maxEntries;
	}
	else
	{
		menuPos--;
	}
}