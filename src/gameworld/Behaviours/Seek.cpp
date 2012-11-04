#include "Seek.h"
#include "../objects/AIObject.h"

Seek *Seek::Instance()
{
	static Seek instance;

	return &instance;
}

void Seek::Enter(AIObject* AI)
{
	
	std::cout<<"Enter seek function called \n";
}


void Seek::Execute(AIObject* AI)
{
	//AI->TakeDamage();
	AI->SetVector(AI->GetPlayerPos(),  AI->GetPosition());
	AI->SetAngle(AI->GetPlayerPos(),  AI->GetPosition());
	if(time(NULL) > AI->seconds+1)
	{
	AI->Move();
	if(AI->Collide())
	{
		cout<<"COLLISSSOOOOOOOOOOOOOOOOOOOOOOOOOON \n";
		AI->DealDamage();
		AI->seconds = time(NULL);
	}
	}

}

void Seek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}