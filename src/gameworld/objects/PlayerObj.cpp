#include "PlayerObj.h"

	int PlayerObj::Health = 100;
	int PlayerObj::Mana = 100;
	std::vector<bool> PlayerObj::Inventory;

PlayerObj::PlayerObj()
{
	model.LoadModel("./models/frame.obj");
	collidableType = "Player";
	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0;
	Inventory.resize(10); //only 4 currently used atm
	for(int i = 0; i < 10; i++)
	{
		Inventory[i] = false;
	}

	GameCollision::AddCollidable(PLAYER, this);
}

void PlayerObj::Display()
{
	glPushMatrix();
	GameObj::Display();
	glPopMatrix();

	if(GameCollision::CollidesWith(this->model.GetCollisionSphere(), TERRAIN))
	{
		std::cout << "Collision with terrain" << std::endl;
	}
}

void PlayerObj::ModifyHealth(int Change)
{
	Health += Change;
	if(Health > 100)
	{
		Health = 100;
	}
	else if(Health <= 0)
	{
		Death();
	}
}

void PlayerObj::Death()
{
	//stubbed
}