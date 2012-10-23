#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <map>
#include <GL\freeglut.h>
#include <GL\freeglut_ext.h>

#include "../World.h"
#include "GameCamera.h"
#include "GameObj.h"
#include "../modelimporter/TerrainModel.h"

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
	virtual void Keyboard(unsigned char key, int keyX, int keyY);
	virtual void Mouse(int button, int state, int mouseX, int mouseY);
	virtual void MovementKeys(int key, int x, int y);
	virtual void ReleaseKey(int key, int x, int y);
	virtual void ReleaseKeys(unsigned char key, int x, int y);
	virtual void MouseMove(int x, int y);

	void UpdateObjects() const;

	void AddObject(GameObj* obj);

	void RemoveObject(int idnum);
private:
	MapGameObj objects;
	GameCamera camera;
	PlayerObj* player;
	void PlayerMovement();

	TerrainModel level;

	void CalculateFPS();
	int elapsedTime;
	int frameCount;
	int currentTime;
	int previousTime;
	double fps;

	bool left, right, forward, back;
};
