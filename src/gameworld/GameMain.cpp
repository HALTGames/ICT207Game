/*#include "GameMain.h"

GameMain::GameMain(void)
{
}


GameMain::~GameMain(void)
{
}

void GameMain::GameLoop()
{
	//Intilise Game window
	glutSetWindowTitle("Game!");
	// register callbacks
	glutDisplayFunc(RenderWorld);

	glutKeyboardFunc(KeyMap);
	glutMouseFunc(Mouse);
	//glutKeyboardUpFunc();

	//Empty Callback functions
	glutSpecialFunc(EmptyFunc);
	glutSpecialUpFunc(EmptyFunc);

	// here is the idle func registration
	glutIdleFunc(RenderWorld); // Change this to glutPostRedisplay at some point early on *************


	// enter GLUT event processing cycle
	glutMainLoop();
}

void GameMain::RenderWorld(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0, 10, -10,
			  0 , 0, 3,
			  0.0f, 1.0f,  0.0f);

	glPushMatrix();
		glScalef(7,7,7);
		//glRotatef(-90,0,0,0);
	GameMain::DrawModel();
	
	glPopMatrix();

	glFlush();
	glutSwapBuffers();

} 

void GameMain::EmptyFunc(int key, int x, int y)
{
	//Used to override previous callback.
}

void GameMain::KeyMap(unsigned char key, int x, int y)
{
	toupper(key);
	switch(key)
	{
		case 'W'://move camera up
		{
			//GameMain::Camera.CameraChange(0,0,1);
			break;
		}
		case 'A'://move camera to the left
		{
			//Camera.CameraChange(-1,0,0);
			break;
		}
		case 'S'://move camera down
		{
		//	Camera.CameraChange(0,0,-1);
			break;
		}
		case 'D'://move camera right
		{
		//	Camera.CameraChange(1,0,0);
			break;
		}
	}

}

void GameMain::Mouse(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		//if left button pressed
	}
}


void GameMain::DrawModel()
{
	GLMmodel* island = NULL;
	// Load the model only if it hasn't been loaded before
	// If it's been loaded then pmodel1 should be a pointer to the model geometry data...otherwise it's null
    if (!island) 
	{
		// this is the call that actualy reads the OBJ and creates the model object
		island = glmReadOBJ("models/island.obj");
        if (!island) exit(0);
		// This will rescale the object to fit into the unity matrix
		// Depending on your project you might want to keep the original size and positions you had in 3DS Max or GMAX so you may have to comment this.

		glmUnitize(island);
		// These 2 functions calculate triangle and vertex normals from the geometry data.
		// To be honest I had some problem with very complex models that didn't look to good because of how vertex normals were calculated
		// So if you can export these directly from you modeling tool do it and comment these line
		// 3DS Max can calculate these for you and GLM is perfectly capable of loading them
        glmFacetNormals(island);        
		glmVertexNormals(island, 90.0); 
    }
    // This is the call that will actualy draw the model
	// Don't forget to tell it if you want textures or not :))
	//glScalef(0.65,0.65,0.65);
    glmDraw(island, GLM_SMOOTH|GLM_TEXTURE);  
}*/