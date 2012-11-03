#include "Bird.h"
#include "Alligator.h"
#include "Shooter.h"
#include "Strafer.h"
#include <time.h>


class AIManager
{
public:
	AIManager();
	~AIManager();
	void UpdateAI();
	void CheckForAICreate();
	void CreateAI();
	void WipeAI();
	

private:
	int minuser;
	time_t seconds;
	int RandomAI;
	Vector3 Placement;
	list<Bird*> *BirdList;
	list<Shooter*> *ShooterList;
	list<Alligator*> *AlligatorList;
	list<Strafer*> *StraferList;

};