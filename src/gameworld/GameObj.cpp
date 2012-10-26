#include "GameObj.h"

int GameObj::numObjects = 0;

//-----------------------------------------------------------------------------

GameObj::GameObj(void)
{
}

//-----------------------------------------------------------------------------

GameObj::GameObj(const Vector3 pos, char* modelFile, 
	const string collideType)
{
	identificationNumber = numObjects;
	++numObjects;

	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0f;

	model.LoadModel(modelFile);
	position = pos;
	collidableType = collideType;
}

//-----------------------------------------------------------------------------

GameObj::~GameObj(void)
{
	model.~GameModel();
}

//-----------------------------------------------------------------------------

void GameObj::Display()
{
	glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(angle, 0.0, 1.0, 0.0);
		model.DrawModel();
	glPopMatrix();
}

//-----------------------------------------------------------------------------

bool GameObj::SetModel(char* modelFile)
{
	return model.LoadModel(modelFile);
}

//-----------------------------------------------------------------------------

void GameObj::SetCollidableType(const string collideType)
{
	collidableType = collideType;
}

//-----------------------------------------------------------------------------

void GameObj::SetPosition(const Vector3 pos)
{
	position = pos;
}

//-----------------------------------------------------------------------------

void GameObj::ChangePosition(const Vector3 pos)
{
	position += pos;
}

//-----------------------------------------------------------------------------

void GameObj::SetAngle(const int ang)
{
	angle = ang;
}

//-----------------------------------------------------------------------------

void GameObj::ChangeAngle(const int ang)
{
	angle += ang;
}

//-----------------------------------------------------------------------------

string GameObj::GetCollidableType() const
{
	return collidableType;
}

//-----------------------------------------------------------------------------

Vector3 GameObj::GetPosition() const
{
	return position;
}

//-----------------------------------------------------------------------------

int GameObj::GetAngle() const
{
	return angle;
}

//-----------------------------------------------------------------------------

int GameObj::GetIdentificationNumber() const
{
	return identificationNumber;
}