#pragma once

#include <iostream>
#include "..\gameobj.h"
#include "..\GameCollision.h"
#include <vector>

class PlayerObj :
	public GameObj
{
public:
	PlayerObj();

	virtual void Display();

	void ModifyHealth(int Change);
	bool ModifyMana(int Change);
	

	void Death();
	//Setters
	void SetHealth(int H) {Health = H;}
	void SetMana(int M) {Mana = M;}
	void SetInventoryStatus(int i, bool value) {Inventory[i] = value;}

	//Getters
	int GetHealth() const {return Health;}
	int GetMana() const {return Mana;}
	bool GetInventoryStatus(int i) const {return Inventory[i];}

private:
	static int Health;
	static int Mana;
	static std::vector<bool> Inventory;
};

