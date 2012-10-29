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
	if(time(NULL) > AI->seconds+1)
	{
	AI->SetVector(AI->GetPlayerPos(),  AI->GetPosition());
	AI->Move();
	if(AI->Check())
	{
		AI->seconds = time(NULL);
	}
	}

}

void Seek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}