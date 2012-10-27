#pragma once

#include "..\GameObj.h"
#include "..\GameCollision.h"

class TerrainObj :
	public GameObj
{
public:
	TerrainObj();

	virtual void Display();
};