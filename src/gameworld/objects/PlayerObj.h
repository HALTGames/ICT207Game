#pragma once

#include <iostream>
#include "..\gameobj.h"
#include "..\GameCollision.h"
#include <vector>

class PlayerObj :
	public GameObj
{
public:
	enum Spells
	{
		MagicMissile = 1,
		Protection = 2,
		
	};
	PlayerObj();

	virtual void Display();

	void ModifyHealth(int Change);
	bool ModifyMana(int Change);
	
	void Death();

	void SelectSpell(int i);

	//Setters
	void SetHealth(int H) {Health = H;}
	void SetMana(int M) {Mana = M;}
	void SetInventoryStatus(int i, bool value) {Inventory[i] = value;}


	//Getters
	int GetHealth() const {return Health;}
	int GetMana() const {return Mana;}
	bool GetInventoryStatus(int i) const {return Inventory[i];}
	int GetSelectedSpell() const {return SelectedSpell;}

private:
	void SetSpell(Spells s) {SelectedSpell = s;}

	static int Health;
	static int Mana;
	static std::vector<bool> Inventory;
	static Spells SelectedSpell;
	static int ProtectionTimer;
};

