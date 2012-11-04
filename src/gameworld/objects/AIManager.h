#include "Bird.h"
#include "Alligator.h"
#include "Shooter.h"
#include "Strafer.h"
#include <time.h>
#include "../Score.h"

/**
 *\class AIManager
 *\brief AIManager class implementation.
 *
 *This class manages the multiple lists 
 *of AI objects, including update and deleting them
 *
 *
 *\author Arran Ford
 */
class AIManager
{
public:
	///Default constructer
	AIManager();
	///Default Destructer
	~AIManager();

	/**
	*\brief Update function for AI lists
	*
	*This function will iterate through each of the AI lists
	*updating them with player postion and displaying them
	*
	*\param Vector3 PlayerPoss
	*/
	void UpdateAI(Vector3 PlayerPoss);

	/**
	*\brief checks if it's okay to spawn a new ai
	* 
	*if three seconds have passed since the last time 
	*ai were created this function will call the create
	*AI function
	*
	*/
	void CheckForAICreate();

	/**
	*\brief Adds new AI to game
	*
	*randomly picks an ai to create and adds
	*it to the AI list through random numbers and
	*if statements, odds are skewed towards weaker AI
	*being spawned more often
	*/
	void CreateAI();

	/**
	*\brief deletes AI
	*
	*This function iterates though each AI list
	*and checks whether their health is zero, if
	*so the the AI is removed from the list.
	*
	*/
	void WipeAI();
	

private:
	///Bird list iterator
	list<Bird*>::iterator itr;
	///Shooter list iterator
	list<Shooter*>::iterator itrs;
	///Alligator list iterator
	list<Alligator*>::iterator itra;
	///Strafer list iterator
	list<Strafer*>::iterator itrst;
	///Vector of the players current position
	Vector3 PlayerPos;
	///used in timer functions
	int minuser;
	///time variable
	time_t seconds;
	///integer used in random AI selection
	int RandomAI;
	///Vector used in AI placement
	Vector3 Placement;
	///List of birds
	list<Bird*> BirdList;
	///List of shooter
	list<Shooter*> ShooterList;
	///list of alligators
	list<Alligator*> AlligatorList;
	///list of strafers
	list<Strafer*> StraferList;

};