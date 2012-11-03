#include "GameObj.h"

int GameObj::numObjects = 0;

//-----------------------------------------------------------------------------

GameObj::GameObj(void)
{
	identificationNumber = numObjects;
	++numObjects;

	deleteObject = false;
}

//-----------------------------------------------------------------------------

GameObj::GameObj(const Vector3 pos, char* modelFile, 
	const string collideType)
{

	identificationNumber = numObjects;
	++numObjects;

	deleteObject = false;

	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0f;

	model.LoadModel(modelFile);
	position = pos;
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
		glScalef(scale, scale, scale);
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

void GameObj::SetPosition(const Vector3 pos)
{
	position = pos;
	model.GetCollisionSphere()->SetCenter(position);
}

//-----------------------------------------------------------------------------

void GameObj::ChangePosition(const Vector3 pos)
{
	position += pos;

	model.GetCollisionSphere()->SetCenter(position);
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

CollisionSphere* GameObj::GetCollisionSphere()
{
	return model.GetCollisionSphere();
}

void GameObj::SetScale(double factor)
{
	scale = factor;
}

bool GameObj::GetDeleteObject() const
{
	return deleteObject;
}