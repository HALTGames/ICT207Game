#include "AlligatorStates.h"
#include "Alligator.h"


//-----------------------------------------Seek Methods

AlligatorSeek* AlligatorSeek::Instance()
{
	static AlligatorSeek instance;

	return &instance;
}

void AlligatorSeek::Enter(Alligator* alligator)
{
	std::cout<<"Enter seek function called \n";
}


void AlligatorSeek::Execute(Alligator* alligator)
{
	std::cout<<"Execute seek function called \n";
	alligator->SetVector(alligator->PlayerPos - alligator->GameObj::position);

	alligator->Move();


}

void AlligatorSeek::Exit(Alligator* alligator)
{
	std::cout<<"Exit seek function called \n";

}


//-----------------------------------------------Next methods