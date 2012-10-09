#include "GameObj.h"


GameObj::GameObj(void)
{
	Init();
}


GameObj::GameObj(const Vector3 pos, char* modelFile, 
	const string collideType)
{
	Init();

	model.LoadModel(modelFile);
	position = pos;
	collidableType = collideType;
}

GameObj::~GameObj(void)
{
	model.~GameModel();
}

void GameObj::Init()
{
	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0f;
}

void GameObj::Display()
{
	glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(angle, 0.0, 1.0, 0.0);
		model.DrawModel();
	glPopMatrix();
}

void GameObj::Update()
{
	// anything that changes on its own goes in here
	// i.e. a scroll spinning around when its dropped
}

bool GameObj::IsOnScreen() const
{
	// still trying to figure out a way to do this

}

bool GameObj::SetModel(char* modelFile)
{
	return model.LoadModel(modelFile);
}

void GameObj::SetCollidableType(const string collideType)
{
	collidableType = collideType;
}

void GameObj::SetPosition(const Vector3 pos)
{
	position = pos;
}

void GameObj::ChangePosition(const Vector3 pos)
{
	position += pos;
}

void GameObj::SetAngle(const int ang)
{
	angle = ang;
}

void GameObj::ChangeAngle(const int ang)
{
	angle += ang;
}

string GameObj::GetCollidableType() const
{
	return collidableType;
}

Vector3 GameObj::GetPosition() const
{
	return position;
}

int GameObj::GetAngle() const
{
	return angle;
}