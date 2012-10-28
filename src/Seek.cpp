#include "Seek.h"
//#include "gameworld\objects\AIObject.h"

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
	std::cout<<"Execute seek function called \n";
	//AI->SetVector(AI->GetPlayerPos() - AI->GetPosition());

	AI->Move();


}

void Seek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}