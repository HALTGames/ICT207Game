#pragma once

#include "..\gameobj.h"
#include "../../Vector3.h"

class ProjectileObj :
	public GameObj
{
public:
	ProjectileObj(Vector3 start, Vector3 end);

	virtual void Display();

protected:
	double speed;
	double length;

private:
	Vector3 start;
	Vector3 direction;

	int beginTime;
};

