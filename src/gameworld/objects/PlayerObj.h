#pragma once

#include <iostream>
#include "..\gameobj.h"
#include "..\GameCollision.h"

class PlayerObj :
	public GameObj
{
public:
	PlayerObj();

	virtual void Display();
};

