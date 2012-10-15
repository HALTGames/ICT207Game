#include "BirdStates.h"
#include "Bird.h"


//-----------------------------------------Seek Methods

Seek* Seek::Instance()
{
	static Seek instance;

	return &instance;
}

void Seek::Enter(Bird* bird)
{
	std::cout<<"Enter seek function called \n";
}


void Seek::Execute(Bird* bird)
{
	std::cout<<"Execute seek function called \n";
	bird->SetVector(bird->PlayerPos - bird->GameObj::position);

	bird->Move();


}

void Seek::Exit(Bird* bird)
{
	std::cout<<"Exit seek function called \n";

}


//-----------------------------------------------Next methods