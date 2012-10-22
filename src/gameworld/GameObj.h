#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

//-----------------------------------------------------------------------------

#include <string>
#include <GL\freeglut.h>

using namespace std;

#include "../Vector3.h"
#include "../modelimporter/GameModel.h"

//-----------------------------------------------------------------------------

/**
 * \brief GameObj.h GameObj.cpp
 * \class GameObj
 * \brief GameObj class implementation.
 *
 * Classifies all objects in the game and gives them a position, angle, model
 * and collidable type. 
 *
 * \author Timothy Veletta 
 * \date 09/10/12
 * \version 01 - Timothy Veletta, 09/10/12
 *		Created constructors, get and set functions as well as initialising,
 *		display and updating functions.
 */
class GameObj
{
public:
	/**
	 * \brief The default constructor.
	 *
	 * Calls the Init function.
	 */
	GameObj(void);

	/**
	 * \brief Secondary constructor.
	 *
	 * Sets the position, model file and collision type.
	 *
	 * \param pos the initial position of the object
	 * \param modelFile the model associated with the object
	 * \param collideType the collidable type of the object
	 */
	GameObj(const Vector3 pos, char* modelFile, const string collideType);

	/**
	 * \brief The default destructor.
	 *
	 * Destroys the game object.
	 */
	virtual ~GameObj(void);

	/**
	 * \brief Initialises the object.
	 *
	 * Sets the initial properties of the game object.
	 */
	virtual void Init();

	/**
	 * \brief Displays the object.
	 *
	 * Displays the object at the current position with the current angle.
	 */
	virtual void Display();

	/**
	 * \brief Updates the object.
	 *
	 * Updates the object every single loop. This would be used for anything
	 * that changes on its own.
	 */
	virtual void Update();

	/**
	 * \brief Whether or not the object is shown.
	 *
	 * Returns whether or not this GameObj is on the screen at the current 
	 * time.
	 *
	 * \retval whether or not this object is on the screen
	 */
	bool IsOnScreen() const;

	/**
	 * \brief Sets the model.
	 *
	 * Sets the model associated with this game object. This is the model that
	 * is displayed every draw loop.
	 *
	 * \param modelFile the relative file name
	 * \retval whether or loading the model was successful
	 */
	bool SetModel(char* modelFile);

	/**
	 * \brief Sets the collidable type.
	 *
	 * Sets the collidable type of the game object.
	 *
	 * \param collideType the collidable type
	 */
	void SetCollidableType(const string collideType);

	/**
	 * \brief Sets the position.
	 *
	 * Sets the position of the game object.
	 *
	 * \param pos the position of the object
	 */
	void SetPosition(const Vector3 pos);

	/**
	 * \brief Changes the position.
	 *
	 * Changes the position of the game object by adding the input vector to
	 * the current position vector.
	 *
	 * \param pos the amount to change the position
	 */
	void ChangePosition(const Vector3 pos);

	/**
	 * \brief Sets the angle.
	 *
	 * Sets the angle that the game object is facing. 0 degrees indicates the
	 * direction the object was originally facing when it was modelled.
	 *
	 * \param ang the angle of the game object.
	 */
	void SetAngle(const int ang);

	/**
	 * \brief Changes the angle.
	 *
	 * Changes the angle of the game object by adding the input angle to the
	 * current angle,
	 *
	 * \param ang the amount to change the angle
	 */
	void ChangeAngle(const int ang);


	/**
	 * \brief Gets the collidable type.
	 *
	 * Gets the collidable type of this game object.
	 *
	 * \retval the collidable type
	 */
	string GetCollidableType() const;

	/**
	 * \brief Gets the position.
	 *
	 * Gets the position of the game object.
	 *
	 * \retval the position of the game object
	 */
	Vector3 GetPosition() const;

	/**
	 * /brief Gets the angle.
	 *
	 * Gets the angle of the game object.
	 *
	 * \retval the angle of the game object
	 */
	int GetAngle() const;

	/**
	 * \brief Gets the identification number.
	 *
	 * Gets the identification number for this game object to make it easy to
	 * add or remove the object from the game world.
	 *
	 * \retval the identification number
	 */
	int GetIdentificationNumber() const;

protected:
	Vector3 position; /**< the current position of the object */
private:
	GameModel model; /**< the model of the game object */
	string collidableType; /**< the collision type */
	int angle; /**< the current angle of the object */

private:
	int identificationNumber; /**< identification number for the
									object */
	static int numObjects; /**< keeps a count of all game objects for
									identification number purposes */
};

//-----------------------------------------------------------------------------