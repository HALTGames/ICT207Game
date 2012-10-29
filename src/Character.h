#pragma once
class Character
{
public:
	Character(void);
	~Character(void);

	void ModifyHealth(int Change);

	void Death();
	//Setters
	void SetHealth(int H) {Health = H;}
	void SetMana(int M) {Mana = M;}

	//Getters
	int GetHealth() const {return Health;}
	int GetMana() const {return Mana;}

private:
	int Health;
	int Mana;
};

