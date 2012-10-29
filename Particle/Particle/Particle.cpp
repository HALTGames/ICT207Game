// Particle.cpp : Defines the entry point for the console application.
//

#include <gl\glut.h>
#include <gl\GL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "SOIL.h"

const int winIdMain = 1;                                       /* Main Window handle         */
const int winIdSub = 2;                                        /* Sub-Window handle          */
int exitIdSub;
//int MenuOn = 1;

void CreateParticle(int i);
void EvolveParticle();
void DrawObjects();
void Display();
void GUI();

GLuint texture;

typedef struct
{
  float lifetime;                       // total lifetime of the particle
  float decay;                          // decay speed of the particle
  float r,g,b;                          // color values of the particle
  float xpos,ypos,zpos;                 // position of the particle
  float xspeed,yspeed,zspeed;           // speed of the particle
  bool active;                       // is particle active or not?
} PARTICLE;

const int maxparticle = 1000;

PARTICLE particle[maxparticle];

void Init()
{
	srand(time(0));
}

void LoadGLTextures()									// Load Bitmaps And Convert To Textures
{
	/* load an image file directly as a new OpenGL texture */
	texture = SOIL_load_OGL_texture
		(
		"UIfinal.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

};

/*void mainReshape(int w, int h) 
{ 

  glViewport (0, 0, w, h); 
  glMatrixMode (GL_PROJECTION); 
  glLoadIdentity (); 
  gluOrtho2D (-1.0F, 1.0F, -1.0F, 1.0F); 
  glMatrixMode (GL_MODELVIEW); 
  glLoadIdentity (); 

  glutSetWindow (winIdSub); 
  glutReshapeWindow (w - 10, h / 10); 
  glutPositionWindow (5, 5); 
  glutSetWindow (winIdMain); 
 
}; 

void  
subReshape (int w, int h) 
{ 
  glViewport (0, 0, w, h); 
  glMatrixMode (GL_PROJECTION); 
  glLoadIdentity (); 
  gluOrtho2D (0.0F, 1.0F, 0.0F, 1.0F); 
}; */
 

 void Idle()
{
	glutSetWindow (winIdMain); 
	glutPostRedisplay (); 
	glutSetWindow (winIdSub); 
	glutPostRedisplay (); 
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	int GAMEWIDTH = 1280;
	int GAMEHEIGHT = 960;
	glutInitWindowPosition(300,0);
	glutInitWindowSize(GAMEWIDTH, GAMEHEIGHT);
	Init();
	glutCreateWindow("Window");

	//glutReshapeFunc (mainReshape); 
	glutIdleFunc(Idle);

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(Display);
		  /* Sub window creation and setup */ 
	glutCreateSubWindow (winIdMain, 200, 810, 880, 150); 

	glutDisplayFunc (GUI);
	//glutReshapeFunc (subReshape); 

	glutMainLoop();

	return 0;
}

/*void drawBanner(void)
{
	glBegin(GL_POLYGON);
        glTexCoord2f(0,1); glVertex2f(0,0);
        glTexCoord2f(1,1); glVertex2f(3,0);
        glTexCoord2f(1,0); glVertex2f(3,3);
        glTexCoord2f(0,0); glVertex2f(0,3);
    glEnd();
}*/
 
void Display()
{
	//std::getchar();
	glutSetWindow (winIdMain); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glDisable(GL_DEPTH_TEST);      // deactivate hidden surface removal
   // glDisable(GL_CULL_FACE);       // show backside of polygons

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // clear background to black

    glMatrixMode(GL_MODELVIEW);    // switch to model view matrix

	DrawObjects();
	EvolveParticle();
	glutSwapBuffers();
}


void GUI()
{
	glutSetWindow(winIdSub);
	glClearColor (0.25, 0.25, 0.25, 0.0); 
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 


	LoadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, texture);

	//drawBanner();
	glPushMatrix();
	glLoadIdentity();
	//glColor3f (1.0F, 1.0F, 1.0F); 
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);
		glVertex2f(-1.0f,-1.0f);
		glTexCoord2f(0.0,1.0);
		glVertex2f(-1.0f,1.0f);
		glTexCoord2f(1.0,1.0);
		glVertex2f(1.0f,1.0f);
		glTexCoord2f(1.0,0.0);
		glVertex2f(1.0f,-1.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glutSwapBuffers (); 
}

void CreateParticle(int i)
{
     particle[i].lifetime= (float)(rand()%500000)/500000.0;
     particle[i].decay=0.001;
     particle[i].r = 0.7;
     particle[i].g = 0.7;
     particle[i].b = 1.0;
     particle[i].xpos= 0.0;
     particle[i].ypos= 0.0;
     particle[i].zpos= 0.0;
     particle[i].xspeed = 0.0005-(float)(rand()%100)/100000.0;
     particle[i].yspeed = 0.01-(float)(rand()%100)/100000.0;
     particle[i].zspeed = 0.0005-(float)(rand()%100)/100000.0;
     particle[i].active = true;
}

void EvolveParticle()
{
   for(int i=0;i<=maxparticle;i++){      // evolve the particle parameters
     particle[i].lifetime-=particle[i].decay;
     particle[i].xpos+=particle[i].xspeed;
     particle[i].ypos+=particle[i].yspeed;
     particle[i].zpos+=particle[i].zspeed;
     particle[i].yspeed-=0.00007;
   }
}

void DrawObjects()
{
	// rendering functions
	glLoadIdentity();

	glRotatef(50.0,1.0,0.0,0.0);         // show scene from top front

	//glBindTexture(GL_TEXTURE_2D,0);          // choose particle texture
	for (int i=0;i<=maxparticle;i++)
	{
		if(particle[i].ypos<0.0)
		{
			particle[i].lifetime=0.0;
		}
		if((particle[i].active==true) && (particle[i].lifetime>0.0))
		{
			glColor3f(particle[i].r,particle[i].g,particle[i].b);
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(0.0,1.0); glVertex3f(particle[i].xpos+0.002, particle[i].ypos+0.002, particle[i].zpos+0.0);     // top    right
				glTexCoord2f(0.0,0.0); glVertex3f(particle[i].xpos-0.002, particle[i].ypos+0.002, particle[i].zpos+0.0);     // top    left
				glTexCoord2f(1.0,1.0); glVertex3f(particle[i].xpos+0.002, particle[i].ypos-0.002, particle[i].zpos+0.0);     // bottom right
				glTexCoord2f(1.0,0.0); glVertex3f(particle[i].xpos-0.002, particle[i].ypos-0.002, particle[i].zpos+0.0);     // bottom left
			glEnd();
		} 
		else 
		{
			CreateParticle(i);
		}
    }
	EvolveParticle();
}