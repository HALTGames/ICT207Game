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
	currentInstance = this;

	Init();
	glutDisplayFunc(AbstractWorld::displayCallback);
	glutKeyboardFunc(AbstractWorld::keyboardCallback);
	glutMouseFunc(AbstractWorld::mouseCallback);
	glutSpecialFunc(AbstractWorld::specialKeyFuncCallback);

}

/*int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,500);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(movementKeys);
	glutSpecialUpFunc(releaseKey);
	glutKeyboardUpFunc (releaseKeys);
	glutKeyboardFunc(keys);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);
	
	// ONLY USE IF REQUIRE MOUSE MOVEMENT
	//glutPassiveMotionFunc(mouseMove);
	//ShowCursor(FALSE);

	glutReshapeFunc(reshape);
	glutMainLoop();
	return(0);
}*/