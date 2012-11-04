#pragma once

//-----------------------------------------------------------------------------

#include <iostream>
#include "../ProjectileManager.h"
#include "..\gameobj.h"
#include "..\GameCollision.h"

#include <vector>

//-----------------------------------------------------------------------------

/**
 * \brief PlayerObj.h PlayerObj.cpp
 * \class PlayerObj
 * \brief PlayerObj class implementation.
 *
 * Sets up the player object and in addition to the functions provided by
 * GameObj, it also has functions for health, mana, inventory and spell
 * management.
 *
 * \author Hamish Carrier, Timothy Veletta
 * \date 22/10/12
 * \version 01 - Timothy Veletta, 22/10/12
 *		Set up the class with an Init, Display and Update function.
 * \version 02 - Timothy Veletta, 25/10/12
 *		Removes Init function for constructor.
 * \version 03 - Timothy Veletta, 27/10/12
 *		Removed Update function and puts functionality in Display function.
 * \version 04 - Hamish Carrier, 31/10/12
 *		Added functions for handling health and mana. Also added functions for
 *		handling spells and inventory.
 */
class PlayerObj :
	public GameObj
{
public:
	/**
	 * A list of all spells.
	 */
	enum Spells
	{
		MagicMissile = 1, /**< the magic missile spell */
		Protection = 2 /**< the protection spell */
	};

	/**
	 * \brief Sets up the player object.
	 *
	 * Sets up the player object including its model, position, angle, scale
	 * and initialises the invetory and adds the collidable sphere to the
	 * collision list.
	 */
	PlayerObj();

	/**
	 * \brief Displays the player object.
	 *
	 * Displays the player object at the specified position with the specified
	 * angle and scale.
	 */
	virtual void Display();

	/**
	 * \brief Changes the position.
	 *
	 * Changes the position of the player object, checks to see if the player
	 * is going to be colliding with something and if not allows the
	 * movement.
	 *
	 * \param pos the amount to move by
	 */
	virtual void ChangePosition(const Vector3 pos);

	/**
	 * \brief Changes the health.
	 *
	 * Changes the health amount of the player object by the amount specified.
	 * Does not allow the players health to go above 100 and if this means the 
	 * players health is less than 100, calls the death function.
	 *
	 * \param Change the amount to change health by
	 */
	void ModifyHealth(int Change);

	/**
	 * \brief Changes the mana.
	 *
	 * Changes the mana amount of the player by the specified amount. Does not
	 * allow the players mana to go above 100 and if this change were to leave
	 * the players mana below 0, does not allow the change.
	 *
	 * \param Change the amount to change mana by
	 * \retval whether or not mana amount was changed
	 */
	bool ModifyMana(int Change);
	
	/**
	 * \brief Kills the player.
	 *
	 * Kills the player when they sustain too much damage.
	 */
	void Death();

	/**
	 * \brief Shoots a projectile.
	 *
	 * Shoots a 'spell' projectile based on what spell is currently selected.
	 *
	 * \param x the x target of the projectile
	 * \param y the y target of the projectile
	 */
	void Shoot(int x, int y);

	/**
	 * \brief Changes spell. 
	 *
	 * Changes spell to the one specified.
	 *
	 * \param i the spell to change to
	 */
	void SelectSpell(int i);

	/**
	 * \brief Sets the status of an inventory item.
	 *
	 * Sets the status of the inventory item specified.
	 *
	 * \param i the inventory item to set
	 * \param value the value to change to
	 */
	void SetInventoryStatus(int i, bool value) {Inventory[i] = value;}

	/**
	 * \brief Gets the health.
	 *
	 * Gets the current health of the player.
	 *
	 * \retval the current health
	 */
	int GetHealth() const {return Health;}

	/**
	 * \brief Gets the current mana.
	 *
	 * Gets the current mana of the player.
	 *
	 * \retval the current mana
	 */
	int GetMana() const {return Mana;}

	/**
	 * \brief Gets the inventory status.
	 *
	 * Gets the inventory status of the input inventory item.
	 *
	 * \param i the inventory index
	 * \retval the status of the item
	 */
	bool GetInventoryStatus(int i) const {return Inventory[i];}

	/**
	 * \brief Returns selected spell.
	 *
	 * Returns the currently selected spell.
	 *
	 * \retval the currently selected spell
	 */
	int GetSelectedSpell() const {return SelectedSpell;}

private:
	/**
	 * \brief Sets the current spell.
	 *
	 * Sets the currently active spell.
	 *
	 * \param s the spell to change to
	 */
	void SetSpell(Spells s) {SelectedSpell = s;}

	static int Health; /**< the amount of health the player has */
	static int Mana; /**< the amount of mana the player has */
	static bool ProtectionStatus; /**< whether or not the player is protected */
	static int Timer; /**< the current time */
	static std::vector<bool> Inventory; /**< the players inventory */
	static Spells SelectedSpell; /**< the currently selected spell */
	static int ProtectionTimer; /**< a timer for the protection spell  */
};

//-----------------------------------------------------------------------------