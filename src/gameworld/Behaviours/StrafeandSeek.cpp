#include "StrafeandSeek.h"
#include "../objects/AIObject.h"

StrafeandSeek *StrafeandSeek::Instance()
{
	static StrafeandSeek instance;

	return &instance;
}

void StrafeandSeek::Enter(AIObject* AI)
{
	std::cout<<"Enter seek function called \n";
}


void StrafeandSeek::Execute(AIObject* AI)
{
	if(time(NULL) > AI->DamageSeconds)
	{
	if(AI->TakeDamage())
	{
		AI->DamageSeconds = time(NULL);
	}
	}
	AI->SetVector(AI->GetPlayerPos(),  AI->GetPosition());
	AI->SetAngle(AI->GetPlayerPos(),  AI->GetPosition());
	if(AI->checker == 0)
	{
	AI->Move();
	}

	if((AI->GetDistanceFrom()<15)||(AI->checker == 1))
	{
		AI->checker = 1;
		if(time(NULL) > AI->GunSeconds+1)
		{
		AI->soundcontroller.playSound("AISpell");	
		AI->Fire();
		AI->GunSeconds =time(NULL);
		AI->seconds = time(NULL);
		}
		if(AI->GetDistanceFrom()>20)
		{
			AI->checker = 0;
		}
	}
	
}

void StrafeandSeek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}