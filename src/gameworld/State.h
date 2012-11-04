 #ifndef STATE_AI
 #define STATE_AI



/**
 *\class State
 *\brief State class implementation.
 *
 *This is an abstract class from which all
 *behaviours in game inherit
 *
 *
 *\author Arran Ford
 */
template<class entity_type>
class State
{
public:

	///Virtual Enter function
	virtual void Enter(entity_type*)=0;
	///Virtual Execute function
	virtual void Execute(entity_type*)=0;
	///Virtual Exit function
	virtual void Exit(entity_type*)=0;
	///Destructer
	virtual ~State(){}

};


#endif