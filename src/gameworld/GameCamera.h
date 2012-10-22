#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <gl\freeglut.h>
#include "GameObj.h"
#include "../Vector3.h"

class GameCamera
{
public:
	GameCamera(void);
	
	GameCamera(GameObj* obj);
	
	~GameCamera(void);

	void ChangeFollowing(GameObj* obj);

	void UpdateCamera();
private:
	GameObj* following;
	bool followingObj;
};
