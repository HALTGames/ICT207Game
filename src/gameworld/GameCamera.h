#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include <gl\freeglut.h>
#include "../Vector3.h"

#include <math.h>


 
class GameCamera
{
public:
	GameCamera();			

	void Render (Vector3 position);	

	bool SetHeight(double height);
	bool SetBehind(double behind);
private:
	double m_height;
	double m_behind;
};