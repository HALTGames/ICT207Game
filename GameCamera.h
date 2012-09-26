#pragma once
#include <gl\freeglut.h>

struct point3D
{
	double X;
	double Y;
	double Z;
};

class GameCamera
{
public:
	GameCamera(void);
	~GameCamera(void);

	void Init();

	void MoveCamera(double addX, double addY, double addZ);

private:

	point3D CameraPos;
};
