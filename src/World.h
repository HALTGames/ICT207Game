#pragma once
class World abstract
{
public:
	virtual ~World() {};

	virtual void Init() {};
	virtual void Reshape(int w, int h) {};
	virtual void Display() {};
	virtual void Idle() {};
	virtual void Keyboard(unsigned char key, int keyX, int keyY) {};
	virtual void Mouse(int button, int state, int mouseX, int mouseY) {};
	virtual void MovementKeys(int key, int x, int y) {};
	virtual void ReleaseKey(int key, int x, int y) {};
	virtual void ReleaseKeys(unsigned char key, int x, int y) {};
	virtual void MouseMove(int x, int y) {}; 
};

