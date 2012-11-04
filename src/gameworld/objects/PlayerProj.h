#pragma once

#include "ProjectileObj.h"
#include "../GameCollision.h"

class PlayerProj:
	public ProjectileObj
{
public:
	PlayerProj(double x1, double z1, double x2, double z2);

private:
	virtual bool CheckCollision();
};