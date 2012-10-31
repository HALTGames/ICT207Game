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

bool PlayerObj::ModifyMana(int Change)
{
	Mana += Change;
	if(Mana > 100)
	{
		Mana = 100;
	}
	else if(Mana < 0)
	{
		//reverses the change
		Mana -= Change;
		return false;
	}
	return true;
}

void PlayerObj::Death()
{
	//stubbed
}