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
	AI->SetVector(AI->GetPlayerPos(),  AI->GetPosition());
	if(time(NULL) > AI->seconds+1)
	{
	AI->Move();
	if(AI->GetDistanceFrom()<0.5)
	{
		AI->seconds = time(NULL);
	}
	}

}

void Seek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}