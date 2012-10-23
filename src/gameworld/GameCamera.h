#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <gl\freeglut.h>
#include "../Vector3.h"

class GameCamera
{
public:
	void rotateX(double amount);
	void rotateY(double amount);
	void rotateZ(double amount);

	void moveForward(double amount);
	void moveLeft(double amount);
	void moveRight(double amount);

	void SetTarget(Vector3 target);
	void SetPosition(Vector3 position);
	void SetUp(Vector3 up);
private:
	Vector3 m_target;
	Vector3 m_position;
	Vector3 m_up;
	Vector3 m_right;
};
