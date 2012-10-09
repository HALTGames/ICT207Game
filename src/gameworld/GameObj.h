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
	 * \brief 
	 *
	 *
	 *
	 */
	bool IsOnScreen() const;


	// SETTERS
	bool SetModel(char* modelFile);

	void SetCollidableType(const string collideType);

	void SetPosition(const Vector3 pos);

	void ChangePosition(const Vector3 pos);

	void SetAngle(const int ang);

	void ChangeAngle(const int ang);


	// GETTERS
	string GetCollidableType() const;

	Vector3 GetPosition() const;

	int GetAngle() const;

	// getBoundingBox?
private:
	GameModel model; /**< the model of the game object */
	string collidableType; /**< the collision type */
	Vector3 position; /**< the current position of the object */
	int angle; /**< the current angle of the object */
};

//-----------------------------------------------------------------------------