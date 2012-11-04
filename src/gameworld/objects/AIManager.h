#include "Bird.h"
#include "Alligator.h"
#include "Shooter.h"
#include "Strafer.h"
#include <time.h>
#include "../Score.h"


class AIManager
{
public:
	AIManager();
	~AIManager();
	void UpdateAI(Vector3 PlayerPoss);
	void CheckForAICreate();
	void CreateAI();
	void WipeAI();
	

private:
	list<Bird*>::iterator itr;
	list<Shooter*>::iterator itrs;
	list<Alligator*>::iterator itra;
	list<Strafer*>::iterator itrst;

	Vector3 PlayerPos;
	int minuser;
	time_t seconds;
	int RandomAI;
	Vector3 Placement;
	list<Bird*> BirdList;
	list<Shooter*> ShooterList;
	list<Alligator*> AlligatorList;
	list<Strafer*> StraferList;

};