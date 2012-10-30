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
	
}

void StrafeandSeek::Exit(AIObject* AI)
{
	std::cout<<"Exit seek function called \n";

}