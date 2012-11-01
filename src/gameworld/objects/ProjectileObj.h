#pragma once

#include <cmath>

#include "..\gameobj.h"
#include "../../Vector3.h"

class ProjectileObj :
	public GameObj
{
public:
	ProjectileObj(double x1, double z1, double x2, double z2);

	virtual void Display();

protected:
	double speed;

private:
	Vector3 movement;

	int startTime;
};

