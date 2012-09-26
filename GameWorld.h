#pragma once

#include "AbstractWorld.h"
#include "GameCamera.h"

class GameWorld: public AbstractWorld
{
public:
	GameWorld(void);
	~GameWorld(void);

	void Display(void);
	void Keyboard(unsigned char Key, int KeyX, int KeyY);
	void Mouse(int Button, int State, int MouseX, int MouseY);
	void SpecialKeyFunc();
	void Init(void);

private:
	GameCamera Camera;
};
