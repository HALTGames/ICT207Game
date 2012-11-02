#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <cmath>
#include <GL\freeglut.h>
#include "../../Vector3.h"
#include "../../modelimporter/GameModel.h"

class ProjectileObj
{
public:
	ProjectileObj(double x1, double z1, double x2, double z2);

	virtual void Display();

	Vector3 GetCurrentPosition();
	Vector3 GetDirection();

	bool CheckTime();
protected:
	double speed;
	int time; // 1000 = 1 sec

	void Scale(double factor);

	GameModel model;
private:
	Vector3 currentPosition;
	Vector3 direction;

	int startTime;

	double scale;
};

