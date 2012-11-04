#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <GL\freeglut.h>
#include "../world.h"

//#include "RAWTexture.h"
#include "../modelimporter/GameModel.h"

typedef GLfloat point[3];//Point in 3d space

class MenuWorld :
	public World
{
public:
	//MenuWorld(void);
	
	virtual void Init();
	virtual void Reshape(int w, int h);
	virtual void Display();
	virtual void Idle();
	virtual void Keyboard(unsigned char key, int keyX, int keyY);
	virtual void Mouse(int button, int state, int mouseX, int mouseY);
	virtual void MovementKeys(int key, int x, int y);
	virtual void ReleaseKey(int key, int x, int y);
	virtual void ReleaseKeys(unsigned char key, int x, int y);
	virtual void MouseMove(int x, int y);

private:

	int windowWidth;//window width
	int windowHeight;//window height

	///Create 10 GameModel Loader Objects
	GameModel Loader[10]; 

	int MenuChoice;

/*	void DrawMenu();
	void DrawBanner();
	void DrawSelectionBox();
	void DrawBox();
	void DrawDivision();

	void MenuSelect();
	void MenuDown();
	void MenuUp();
	
	void drawIsland(void);
	void drawSkybox(void);
	void animate(void);
	*/
	//GLMmodel* island;
	//GLMmodel* skybox;
	//static float ypoz;

	//GLuint texture; // stores the current texture being used

	//int menuPos; //Menu position, initialised to first spot
	//int maxEntries; //Max amount of menu items

	//GLfloat menuDist;//Distance apart each menu element is

	//Defines a menu element polygon size,
	//point p1;
	//point p2;
	//point p3;
	//point p4;

	//for the selection arrow element
	//point p5;
	//point p6;
	//point p7;
};

