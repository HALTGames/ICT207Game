#pragma once
#include <gl/freeglut.h>


class AbstractWorld abstract
{
public:

	AbstractWorld(void);
	~AbstractWorld(void);

	void GameLoop(void);


	virtual void Display() = 0;

	virtual void Keyboard(unsigned char Key, int KeyX, int KeyY) = 0;

	virtual void Mouse() = 0;

	virtual void SpecialKeyFunc() = 0;

	virtual void Init() = 0;


private:
	static AbstractWorld* currentInstance;

	static void displayCallback()
	{
		currentInstance->Display();
	}

	static void keyboardCallback(unsigned char Key, int KeyX, int KeyY)
	{
		currentInstance->Keyboard(Key, KeyX, KeyY);
	}

};