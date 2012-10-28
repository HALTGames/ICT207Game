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

void MenuWorld::DrawMenu()
{
		glPushMatrix();
		//Load our texture
		texture = LoadTexture( "textures/start_icon_alpha.raw", 256, 256 );
		glColor4f(1,1,1,1);
		glTranslatef(-1,-1,0);
		DrawBox();

		texture = LoadTexture( "textures/settings_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		DrawBox();

		texture = LoadTexture( "textures/help_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		DrawBox();

		texture = LoadTexture( "textures/exit_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		DrawBox();
		//Free our texture
		FreeTexture( texture );
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
		texture = LoadTexture( "textures/banner_alpha.raw", 512, 512 );
		DrawBanner();
		FreeTexture( texture );
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
	texture = LoadTexture( "textures/select_icon_alpha.raw", 256, 256 );
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
	FreeTexture( texture );
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

GLuint MenuWorld::LoadTexture(const char * filename, int width, int height)
{
	GLuint texture;
	unsigned char * data;
	FILE * file;

	//The following code will read in our RAW file
	file = fopen( filename, "rb" );
	if ( file == NULL ) return 0;
	data = (unsigned char *)malloc( width * height * 4 );
	fread( data, width * height * 4, 1, file );
	fclose( file );

	glGenTextures( 1, &texture ); //generate the texture with the loaded data
	glBindTexture( GL_TEXTURE_2D, texture ); //bind the texture to it’s array
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); //set texture environment parameters

	//here we are setting what textures to use and when. The MIN filter is which quality to show
	//when the texture is near the view, and the MAG filter is whichquality to show when the texture
	//is far from the view.

	//The qualities are (in order from worst to best)
	//GL_NEAREST
	//GL_LINEAR
	//GL_LINEAR_MIPMAP_NEAREST
	//GL_LINEAR_MIPMAP_LINEAR

	//And if you go and use extensions, you can use Anisotropic filtering textures which are of an
	//even better quality, but this will do for now.
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	//Here we are setting the parameter to repeat the texture instead of clamping the texture
	//to the edge of our shape. 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	//Generate the texture
	//gluBuild2DMipmaps(GL_TEXTURE_2D,4,width,height,GL_RGBA,GL_UNSIGNED_BYTE,data);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, data);
	free( data ); //free the texture
	return texture; //return whether it was successfull
}

void MenuWorld::FreeTexture( GLuint texture )
{
	glDeleteTextures( 1, &texture ); 
}