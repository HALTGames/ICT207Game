#include "SeekandShoot.h"
#include "../objects/AIObject.h"

SeekandShoot *SeekandShoot::Instance()
{
	static SeekandShoot instance;

	return &instance;
}

void SeekandShoot::Enter(AIObject* AI)
{
		
}


void SeekandShoot::Execute(AIObject* AI)
{
	if(time(NULL) > AI->DamageSeconds)
	{
	if(AI->TakeDamage())
	{
		AI->DamageSeconds = time(NULL);
	}
	}
	AI->SetAngle(AI->GetPlayerPos(),  AI->GetPosition());
	
	if(time(NULL) > AI->seconds+1)
	AI->SetVector(AI->GetPlayerPos(),  AI->GetPosition());
	
	AI->Move();
	if(AI->GetDistanceFrom()<9)
	{
		AI->seconds = time(NULL);
	}
	
	if(time(NULL) > AI->GunSeconds+1)
	{
		if(AI->GetDistanceFrom()<12)
		{
			AI->soundcontroller.playSound("AISpell");	
		AI->Fire();
		AI->GunSeconds = time(NULL);
		}
	}
}

void SeekandShoot::Exit(AIObject* AI)
{
	
}