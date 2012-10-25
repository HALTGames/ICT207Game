#pragma once

#include "..\gameobj.h"

class PlayerObj :
	public GameObj
{
public:
	PlayerObj();

	virtual void Display();

	virtual void Update();
};

