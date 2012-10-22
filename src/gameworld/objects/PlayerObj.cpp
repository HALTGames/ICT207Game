#include "PlayerObj.h"

void PlayerObj::Init()
{
	model.LoadModel("../../models/display.obj");
	collidableType = "Player";
	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0;
}

void PlayerObj::Display()
{
	GameObj::Display();
}

void PlayerObj::Update()
{
}