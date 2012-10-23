#include "BirdStates.h"
#include "Bird.h"


//-----------------------------------------Seek Methods

BirdSeek* BirdSeek::Instance()
{
	static BirdSeek instance;

	return &instance;
}

void BirdSeek::Enter(Bird* bird)
{
	std::cout<<"Enter seek function called \n";
}


void BirdSeek::Execute(Bird* bird)
{
	std::cout<<"Execute seek function called \n";
	bird->SetVector(bird->PlayerPos - bird->GetPosition());

	bird->Move();


}

void BirdSeek::Exit(Bird* bird)
{
	std::cout<<"Exit seek function called \n";

}


//-----------------------------------------------Next methods