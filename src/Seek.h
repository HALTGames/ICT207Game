#include "gameworld/State.h"
#include <iostream>

class Seek: public State<class entity_type>
{
private:
	Seek(){}
	//may need copy constructer, assignment operator and destructer here

public:
	static Seek* Instance();

	virtual void Enter(entity_type* entity);
	virtual void Execute(entity_type* entity);
	virtual void Exit(entity_type* entity);


};




void Seek::Enter(entity_type* entity)
{
	std::cout<<"Enter seek function called \n";
}


template<class entity_type>
void Seek::Execute(entity_type* entity)
{
	std::cout<<"Execute seek function called \n";
	entity->SetVector(entity->PlayerPos - entity->GameObj::position);

	entity->Move();


}

void Seek::Exit(entity_type* entity)
{
	std::cout<<"Exit seek function called \n";

}