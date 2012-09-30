#define GLUT_DISABLE_ATEXIT_HACK

#include <GL\freeglut.h>
#include "TerrainModel.h"

GLfloat rotation = 0.0;

TerrainModel model;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);

	model.LoadModel("model/box.obj");
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
		glRotatef(rotation, 0.0, 1.0, 0.0);
		model.DrawModel();
	glPopMatrix();

	rotation += 0.1;

	if(rotation >= 360.0)
	{
		rotation = 0.0;
	}

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Model Loader");

	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);

	glutMainLoop();

	return 0;
}