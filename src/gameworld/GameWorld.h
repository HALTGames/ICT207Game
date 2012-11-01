#pragma once

#define GLUT_DISABLE_ATEXIT_HACK
#ifndef GAMEWORLD_H
#define GAMEWORLD_H

// STL
#include <list>

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
#include "../SoundControl/sounds.h"
#include "GameObjManager.h"
#include "../modelimporter/GameModel.h"

// OBJECTS
#include "objects\Bird.h"
#include "objects\Shooter.h"
#include "objects\Alligator.h"
#include "objects\PlayerObj.h"
#include "objects\Strafer.h"
#include "objects\TerrainObj.h"
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
	void UpdateAI();
	void CheckForAICreate();
	void CreateAI();
	void WipeAI();
	void PickAIPos();
	void ManaRegen();
	/// may get moved to a class
private:

	sounds* SoundController;
	GameCamera camera;
	PlayerObj* player;
	list<Bird*> *BirdList;
	list<Shooter*> *ShooterList;
	list<Alligator*> *AlligatorList;
	list<Strafer*> *StraferList;
	ReticuleObj* reticule;

	int RandomAI;
	Bird *AIBird;
	Shooter *AIShooter;
	Alligator *AIAlligator;
	Strafer *AIStrafer;
	Vector3 Placement;

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