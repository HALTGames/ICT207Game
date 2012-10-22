#pragma once

#include "..\gameobj.h"

class PlayerObj :
	public GameObj
{
public:
	virtual void Init();

	virtual void Display();

	virtual void Update();
};

