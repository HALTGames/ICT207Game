#include "GameCamera.h"

GameCamera::GameCamera(void)
{
	following = NULL;
	followingObj = false;
}

GameCamera::GameCamera(GameObj* obj)
{
	following = NULL;
	ChangeFollowing(obj);
}


GameCamera::~GameCamera(void)
{
	following = NULL;
}

void GameCamera::ChangeFollowing(GameObj* obj)
{
	followingObj = true;
	following = obj;
}

void GameCamera::UpdateCamera()
{
	if(followingObj) 
	{
		Vector3 cameraPos = following->GetPosition();

		cameraPos += Vector3(5.0, 20.0, 0.0);

		glTranslatef(cameraPos.x, cameraPos.y, cameraPos.z);

		glRotatef(90.0, 1.0, 0.0, 0.0);
	}
}