#pragma once

#define GLUT_DISABLE_ATEXIT_HACK
#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#define PI 3.14159265

// STL
#include <list>
#include <cmath>

// FREEGLUT
#include <GL\freeglut.h>
#include <GL\freeglut_ext.h>

// PARENT
#include "../World.h"

// HELPER CLASSES
#include "../modelimporter/TerrainModel.h"
#include "GameCamera.h"
#include "GameObj.h"
#include "../TextureLoader.h"
//#include "../SoundControl/sounds.h"
#include "GameObjManager.h"
#include "../modelimporter/GameModel.h"
#include "ProjectileManager.h"

// OBJECTS
#include "objects\AIManager.h"
#include "objects\ProjectileObj.h"
#include "objects\ReticuleObj.h"


class GameWorld: public World
{
public:
	~GameWorld(void);

	// Callbacks
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
	virtual void GUI();
	virtual void GUIinit();

	virtual void Exit();
	void ManaRegen();
	/// may get moved to a class
private:
	PlayerObj* playerObj;
	ReticuleObj* reticuleObj;
	AIManager* AImanage;

	sounds* SoundController;
	GameCamera camera;
	
	void SetReticulePosition(int x, int y);

	
	TextureLoader TextureLoad;

	void PlayerMovement();

	TerrainModel level;
	GameModel ModelLoader[10];

	int ManaTimer;

	int lastdrawn;

	bool left, right, forward, back;

	int gameWidth, gameHeight;
};
#endif