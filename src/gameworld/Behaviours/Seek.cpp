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
	//std::cout<<"Execute seek function called \n";
	
	
	//cout<<AI->GetPosition().x<<"\n";
	//cout<<AI->GetPosition().x<<"\n";
	//cout<<AI->GetPosition().y<<"\n";
	//cout<<AI->GetPosition().z<<"\n";

	AI->SetVector(AI->GetPlayerPos(),  AI->GetPosition());
	//cout<<AI->GetPosition().x<<"\n";
	AI->Move();
	


}

void Seek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}