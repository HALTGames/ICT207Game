#pragma once

#define GLUT_DISABLE_ATEXIT_HACK
#include "objects\Bird.h"
#include <map>
#include <GL\freeglut.h>
#include <GL\freeglut_ext.h>

#include "../World.h"
#include "GameCamera.h"
#include "GameObj.h"
#include "../modelimporter/TerrainModel.h"

#include "objects\PlayerObj.h"
#include "objects\TerrainObj.h"
#include <list>
#include "../TextureLoader.h"
#include "../SoundControl/sounds.h"
#include "objects\PlayerObj.h"

typedef map<int, GameObj*> MapGameObj;
typedef MapGameObj::iterator ItrGameObj;
typedef MapGameObj::const_iterator CItrGameObj;

class GameWorld: public World
{
public:
	GameWorld(void);
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

	void UpdateObjects() const;
	void CreateAI();
	/// may get moved to a class
	

	void AddObject(GameObj* obj);

	GameObj* GetObject(int idnum);

	void RemoveObject(int idnum);
private:
	sounds SoundController;
	MapGameObj objects;
	GameCamera camera;
	PlayerObj* player;
	list<Bird*> BirdList;

	Bird *AIBird;
	TextureLoader TextureLoad;

	void PlayerMovement();

	TerrainModel level;
	PlayerObj Character;

	void CalculateFPS();
	double elapsedTime;
	int frameCount;
	int currentTime;
	int previousTime;
	double fps;

	int lastdrawn;

	bool left, right, forward, back;
};
