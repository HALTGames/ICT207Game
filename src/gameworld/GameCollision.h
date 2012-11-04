#pragma once

//-----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <list>
#include "../modelimporter/GameModel.h"
#include "GameObj.h"

//-----------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------

/**
 * Collidable type enum.
 */
typedef enum collidableType {
	PLAYER, /**< the player type */
	ENEMY, /**< the enemy type */
	TERRAIN, /**< terrain type */
	ENEMYPROJECTILE, /**< enemy projectile type */
	PLAYERPROJECTILE /**< player projectile type */
};

//-----------------------------------------------------------------------------

typedef list<GameObj*> objList;
typedef objList::iterator ItrObjList;
typedef objList::const_iterator CItrObjList;

typedef map<collidableType, objList > collisionMap;
typedef collisionMap::iterator ItrCollMap;
typedef collisionMap::const_iterator CItrCollMap;

//-----------------------------------------------------------------------------

/**
 * \file GameCollision.h GameCollision.cpp
 * \class GameCollision
 * \brief GameCollision class implementation.
 *
 * Sets up a list of collidable objects which is categorised based upon the
 * type of collidable. Allows other objects to check if they are colliding at
 * that time.
 *
 * \author Timothy Veletta
 * \date 29/09/12
 * \version 01 - Timothy Veletta 29/09/12
 *		Created the file with only a constructor and destructor.
 * \version 02 - Timothy Veletta, 26/10/12
 *		Added the collidableType enum, AddCollidable, CollidesWith and
 *		RemoveCollidable functions.
 */
class GameCollision
{
public:
	/**
	 * \brief Adds a collidable.
	 *
	 * Adds a collidable object based upon the object collidable type.
	 *
	 * \param type the type of collidable
	 * \param obj the game object
	 */
	static void AddCollidable(collidableType type, GameObj* obj);

	/**
	 * \brief Checks collision.
	 *
	 * Checks if the input collision sphere collides with any of the collidable
	 * types.
	 *
	 * \param sphere the collision sphere to compare
	 * \param type the type to check for collision
	 * \retval whether or not there was a collision
	 */
	static bool CollidesWith(CollisionSphere* sphere, collidableType type);

private:
	static collisionMap objCollision; /**< holds all the collidable game 
											objects */

	/**
	 * \brief Checks collision.
	 *
	 * Checks collision between collision spheres.
	 *
	 * \param sphere1 collision sphere one
	 * \param sphere2 collision sphere two
	 * \retval whether or not the two collided
	 */
	static bool CheckCollision(CollisionSphere* sphere1, 
								CollisionSphere* sphere2);
};

//-----------------------------------------------------------------------------