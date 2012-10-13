#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <GL/glut.h>

GLuint texture; // stores the current texture being used

int windowWidth = 500;//window width
int windowHeight = 500;//window height

int menuPos = 1; //Menu position, initialised to first spot
int maxEntries = 4; //Max amount of menu items

GLfloat menuDist = 0.5;//Distance apart each menu element is

typedef GLfloat point[3];//Point in 3d space

//Defines a menu element polygon size,
point p1 = {0,0,0};
point p2 = {2,0,0.0};
point p3 = {2,2,0.0};
point p4 = {0,2,0.0};

//for the selection arrow element
point p5 = {0.5,0,0.0};
point p6 = {0.5,0.5,0.0};
point p7 = {0,0.5,0.0};

void drawBox(void); //Draw a single menu element
void drawMenu(void); //Draw the whole menu
void drawSelectBox(void); //Draw the selection arrow
void drawBanner(void); //Draw the logo

void drawDivision(void);//visual representation of mouse selection, unused atm

void menuUp(void); //move the menu selection up
void menuDown(void); //move the menu selection down
void menuSelect(void); //select the current menu item

void checkMousePos(int x, int y); // checks the mouse current position

GLuint LoadTexture( const char * filename, int width, int height );//function to load in a texture
void FreeTexture( GLuint texture );//clear the current texture

void init(void);//initialize glut stuff
void display(void);//glut display function
void reshape (int w, int h);//window reshape function
void skeyboard(int key, int x, int y);//special keys eg up, down arrow
void keyboard(unsigned char key, int x, int y); //keyboard press function
void mouseMove(int x, int y);//calls when the mouse is moving
void mouse(int button, int state, int x, int y);//calls when the mouse is clicked
void idle(void);//idle function


void init(void)
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

GLuint LoadTexture( const char * filename, int width, int height )
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

void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture ); 
}

void menuUp(void){
	if(menuPos==1)
	{
		menuPos = maxEntries;
	}
	else
	{
		menuPos--;
	}
}

void menuDown(void){
	if(menuPos==maxEntries)
	{
		menuPos = 1;
	}
	else
	{
		menuPos++;
	}
}

void menuSelect(void){
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

void drawDivision(void)
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

void drawBox(void) 
{ 
	glBegin(GL_POLYGON); 
        glTexCoord3f(0,1,0); glVertex3fv(p1);
        glTexCoord3f(1,1,0); glVertex3fv(p2);
        glTexCoord3f(1,0,0); glVertex3fv(p3);
        glTexCoord3f(0,0,0); glVertex3fv(p4);
    glEnd();
}

void drawSelectBox(void) 
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

void drawBanner(void)
{
	glBegin(GL_POLYGON);
        glTexCoord3f(0,1,0); glVertex3f(0,0,0);
        glTexCoord3f(1,1,0); glVertex3f(3,0,0);
        glTexCoord3f(1,0,0); glVertex3f(3,3,0);
        glTexCoord3f(0,0,0); glVertex3f(0,3,0);
    glEnd();
}

void drawMenu( void ) 
{ 
	glPushMatrix();
		//Load our texture
		texture = LoadTexture( "textures/start_icon_alpha.raw", 256, 256 );
		glColor4f(1,1,1,1);
		glTranslatef(-1,-1,0);
		drawBox();

		texture = LoadTexture( "textures/settings_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		drawBox();

		texture = LoadTexture( "textures/help_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		drawBox();

		texture = LoadTexture( "textures/exit_icon_alpha.raw", 256, 256 );
		glTranslatef(0,-menuDist,0);
		drawBox();
		//Free our texture
		FreeTexture( texture );
	glPopMatrix();
	
	glPushMatrix();
		glColor4f(1,1,1,1);
		glTranslatef(-0.1,-0.2,0);
		if(menuPos == 1)
		{
			glTranslatef(1.2,0,0);
			drawSelectBox();
		}
		else if(menuPos == 2)
		{
			glTranslatef(1.2,-menuDist,0);
			drawSelectBox();
		}
		else if(menuPos == 3)
		{
			glTranslatef(1.2,-menuDist*2,0);
			drawSelectBox();
		}
		else
		{
			glTranslatef(1.2,-menuDist*3,0);
			drawSelectBox();
		}
	glPopMatrix();

	glPushMatrix();
		glColor4f(1,1,1,1);
		glTranslatef(-1.4,0.4,0);
		texture = LoadTexture( "textures/banner_alpha.raw", 512, 512 );
		drawBanner();
		FreeTexture( texture );
	glPopMatrix();
	
} 

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();             
           
   gluLookAt (0.0f, 0.0f, 5.0f, //5 units backward from the origin
				0.0f, 0.0f, 0.0f, 
				0.0f, 1.0f, 0.0f);

   //drawDivision();
   drawMenu();

   glutSwapBuffers();
}

void reshape (int w, int h)
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

void skeyboard(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP: 
			menuUp();
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN: 
			menuDown(); 
			glutPostRedisplay();
			break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 13: 
			menuSelect();
			break;
		case 27:
			exit(EXIT_SUCCESS);
			break;
	}
}

void mouseMove(int x, int y)
{
	checkMousePos(x, y);
}

void checkMousePos(int x, int y)
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

void mouse(int button, int state, int x, int y)
{
	switch(button){
		case GLUT_LEFT_BUTTON:
			menuSelect();
			break;
	}
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);

   glutInitDisplayMode (GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
   glutInitWindowSize (windowWidth, windowHeight);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);

   init ();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutPassiveMotionFunc(mouseMove);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(skeyboard);
   
   glutMainLoop();

   return 0;
}