#pragma once

#include <iostream>
#include "..\gameobj.h"
#include "..\GameCollision.h"

class PlayerObj :
	public GameObj
{
public:
	PlayerObj();

	virtual void Display();

	void ModifyHealth(int Change);

	void Death();
	//Setters
	void SetHealth(int H) {Health = H;}
	void SetMana(int M) {Mana = M;}

	//Getters
	int GetHealth() const {return Health;}
	int GetMana() const {return Mana;}

private:
	static int Health;
	static int Mana;
};

