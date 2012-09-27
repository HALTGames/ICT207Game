#include "AbstractWorld.h"
#include "ShaysWorld.h"
#include "GameWorld.h"


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

void Select(bool Check);

AbstractWorld* Instance;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,500);
	glutCreateWindow("Window!");

	Instance = new ShaysWorld;
	Select(true);
	Instance->GameLoop();
	glutMainLoop();
	return(0);
}


void Select(bool Check)
{
	delete Instance;
	
	if(Check)
		Instance = new ShaysWorld;
	else
		Instance = new GameWorld;

}