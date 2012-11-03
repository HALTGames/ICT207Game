#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <cmath>
#include <GL\freeglut.h>
#include "../../Vector3.h"
#include "../GameObj.h"
#include "../GameCollision.h"
#include "../../modelimporter/GameModel.h"

class ProjectileObj:
	public GameObj
{
public:
	ProjectileObj();
	ProjectileObj(double x1, double z1, double x2, double z2);
	~ProjectileObj();

	void Display();

	Vector3 GetCurrentPosition();
	Vector3 GetDirection();
protected:
	double speed;
	int time; // 1000 = 1 sec
	Vector3 direction;
	int startTime;

	void Scale(double factor);

private:
	

	

	bool CheckTime() const;

	virtual bool CheckCollision();
};

