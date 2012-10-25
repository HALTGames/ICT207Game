#include "PlayerObj.h"

PlayerObj::PlayerObj()
{
	model.LoadModel("./models/frame.obj");
	collidableType = "Player";
	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0;
}

void PlayerObj::Display()
{
	glPushMatrix();
	GameObj::Display();
	glPopMatrix();
}

void PlayerObj::Update()
{
}