#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

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

// OBJECTS
#include "objects\Bird.h"
#include "objects\PlayerObj.h"
#include "objects\TerrainObj.h"


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

	virtual void Exit();
	void CreateAI();
	/// may get moved to a class
private:
	GameObjManager* objectManager;

	sounds SoundController;
	GameCamera camera;
	PlayerObj* player;
	list<Bird*> BirdList;

	Bird *AIBird;
	TextureLoader TextureLoad;

	void PlayerMovement();

	TerrainModel level;
	PlayerObj Character;

	int lastdrawn;

	bool left, right, forward, back;
};
