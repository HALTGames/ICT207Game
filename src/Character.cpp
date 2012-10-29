#include "Character.h"

	int Character::Health = 100;
	int Character::Mana = 100;

Character::Character(void)
{

}


Character::~Character(void)
{
}

void Character::ModifyHealth(int Change)
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

void Character::Death()
{
	//stubbed
}