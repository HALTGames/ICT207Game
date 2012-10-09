#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <string>
#include <GL\freeglut.h>

using namespace std;

#include "../Vector3.h"
#include "../modelimporter/GameModel.h"

//-----------------------------------------------------------------------------

class GameObj
{
public:
	GameObj(void);

	GameObj(const Vector3 pos, char* modelFile, const string collideType);

	virtual ~GameObj(void);

	virtual void Init();

	virtual void Display();

	virtual void Update();

	bool IsOnScreen() const;


	// SETTERS
	bool SetModel(char* modelFile);

	void SetCollidableType(const string collideType);

	void SetPosition(const Vector3 pos);

	void ChangePosition(const Vector3 pos);

	void SetAngle(const int ang);

	void ChangeAngle(const int ang);


	// GETTERS
	string GetCollidableType() const;

	Vector3 GetPosition() const;

	int GetAngle() const;

	// getBoundingBox?
private:
	GameModel model;
	string collidableType;
	Vector3 position;
	int angle;
};

//-----------------------------------------------------------------------------