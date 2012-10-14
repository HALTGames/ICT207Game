/*#include "GameCamera.h"



GameCamera::GameCamera(void)
{
}


GameCamera::~GameCamera(void)
{
}


void GameCamera::Init(void)
{
	CameraPos.X = 0;
	CameraPos.Y = 10;
	CameraPos.Z = -10;

	gluLookAt(CameraPos.X, CameraPos.Y, CameraPos.Z,
			  CameraPos.X, CameraPos.Y+10, CameraPos.Z-10,
			  0, 0, -1);

}

void GameCamera::MoveCamera(double addX, double addY, double addZ)
{
	gluLookAt(CameraPos.X+addX, CameraPos.Y+addY, CameraPos.Z+addZ,
			  CameraPos.X+addX, CameraPos.Y+addY+10, CameraPos.Z+addZ-10,
			  0, 0, -1);

}*/