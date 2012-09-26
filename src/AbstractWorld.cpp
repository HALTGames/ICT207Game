#include "AbstractWorld.h"

AbstractWorld* AbstractWorld::currentInstance = NULL;

AbstractWorld::AbstractWorld(void)
{
}


AbstractWorld::~AbstractWorld(void)
{
}


void AbstractWorld::GameLoop(void)
{
	Init();
	currentInstance = this;
	glutDisplayFunc(AbstractWorld::displayCallback);
	glutKeyboardFunc(AbstractWorld::keyboardCallback);
	glutMouseFunc(AbstractWorld::mouseCallback);
}
