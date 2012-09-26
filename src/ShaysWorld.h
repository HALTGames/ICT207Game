#pragma once

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <time.h>
#include <string.h>

#include "AbstractWorld.h"
#include "camera.h"
#include "texturedPolygons.h"
#include "Wave.h"

class ShaysWorld: public AbstractWorld
{
public:
	ShaysWorld(void);
	~ShaysWorld(void);

	void Display();

	void Keyboard(unsigned char Key, int KeyX, int KeyY);

	void Mouse(int Button, int State, int MouseX, int MouseY);

	void SpecialKeyFunc();

	void Init();

protected:
	Wave wave;

	GLMmodel* pmodel1;
	GLMmodel* stairs_model;
	GLMmodel* display_model;
	GLMmodel* billboard_model;
	GLMmodel* roof_model;
	GLMmodel* upper_model;
	GLMmodel* bannister_model;
	GLMmodel* wall_model;
	GLMmodel* frame_model;

	GLdouble movementSpeed;
	GLdouble rotationSpeed;

	int XY		;
	int XZ		;
	int YZ		;
	int YZ_FLIP ;
	int XY_FLIP ;

	// PLAIN TYPES
	int FLAT_PLAIN	;
	int XY_PLAIN	;
	int ZY_PLAIN	;

	// TEXTURES
	// Grass Textures
	int GRASS						;
	int GRASS_2						;
	int GRASS_HILL					;
	// Pavement Textures
	int PAVEMENT					;
	int PAVEMENT_TOP				;
	int PAVEMENTSIDE_LEFT			;
	int PAVEMENTSIDE_RIGHT			;
	int PAVEMENTSIDE_TOP			;
	int PAVEMENT_CORNER_1			;
	int PAVEMENT_CORNER_2			;
	int PAVEMENT_FLIP				;
	int PAVEMENT_TOP_FLIP			;
	int PAVEMENT_16					;
	int DOORPAVE_1					;
	// Wall Brick Textures
	int WALL_BRICK_YZ				
	int WALL_BRICK_XY				;
	int WALL_BRICK_XY_87WIDTH		;
	int WALL_BRICK_GAP_YZ			;
	int WALL_BRICK_GAP2_YZ			;
	int	WALL_BRICK_USD_YZ			;
	int WALL_BRICK_XY_END			;
	int WALL_BRICK_YZ_END			;
	int	WALL_GAP_1					;
	int WALL_BRICK_3_4				;
	int SHADOW_BRICK				;
	int WALL_BRICK_SEC_SIGN			;
	// Window Post Textures
	int WINDOWPOST_CHANC_FRONT		;
	int WINDOWPOST_CHANC_RIGHT	   ;
	int WINDOWPOST_CHANC_LEFT	    ;
	int WINDOWLEDGE_CHANC_FRONT		;
	int WINDOWLEDGE_CHANC_TOP		;
	int WINDOWPOST_PHYSSCI_FRONT	;
	int WINDOWPOST_PHYSSCI_RIGHT	;
	int WINDOWPOST_PHYSSCI_LEFT		;
	int	WINDOWPOST_LIB_FRONT		;
	int	WINDOWPOST_LIB_LEFT			;
	int	WINDOWPOST_LIB_RIGHT		;
	// Door Post Textures
	int DOOR_POST_SECURITY			;
	// Window Ledge Textures
	int WINDOWLEDGE_PS_FRONT		;
	int WINDOWLEDGE_PS_TOP			;
	int WINDOWLEDGE_PS_BOTT			;
	int WINDOWLEDGE_LIB_A			;
	int WINDOWLEDGE_LIB_B			;
	int WINDOWLEDGE_LIB_TOP_A		;
	int WINDOWLEDGE_LIB_TOP_B		;
	int WINDOW_LEDGE_END_1			;
	int WINDOW_LEDGE_END_2			;
	// Main Post Textures
	int	MAIN_POST					;
	int	MAIN_POST_2					;
	// Door Post Textures
	int DOOR_POST_CHANC				;
	int DOOR_SIDEPOST_CHANC			;
	int DOOR_POST_LIB				;
	// Coloured Posts Textures
	int PURPLE_POST					;
	int PURPLE_POSTSIDE				;
	int RED_POST					;
	int RED_POSTSIDE				;
	// Roof Textures
	int ROOF_TOP					;
	int ROOF_TOP_LIB				;
	int ROOF_PLANKS					;
	int ROOF_BEAM_1					;
	int ROOF_PLANKS_2				;
	int ROOF_BEAM_2					;
	int BELOW_ROOF_FILL				;
	int ROOF_BEAM_3					;
	int ROOF_BEAM_4					;
	int ROOF_BEAM_3_TOP				;
	// KBLT Textures
	int KBLT						;
	int KBLT_EDGE					;
	int KBLT_EDGE_2					;
	int KBLT_EDGE_CORNER			;
	int KBLT_SIDE_1					;
	int KBLT_SIDE_2					;
	// Sign and Other Textures
	int NEXUS_SIGN					;
	int NEXUS_SIDE					;
	int SECURITY_SIGN				;
	int SECURITY_SIGN_2				;
	int SIGN_1						;
	int SIGN_1_SIDE_1				;
	int SIGN_1_SIDE_2				;
	int SIGN_2						;
	int SIGN_2_SIDE					;
	int PSC_SIGN					;
	int PSC_SIGN_2					;
	int CO_SIGN						;
	int STA_TRAVEL					;
	int STA_TRAVEL_EDGE				;
	int STA_TRAVEL_BRACKET			;
	int STA_TRAVEL_2				;
	int STA_TRAVEL_BOTTOM			;
	int TOILET_MEN					;
	int TOILET_WOMEN				;
	int GS_SIGN						;
	int GS_SIGN_2					;
	int GS_SIGN_EDGE				;
	int MAP_2						;
	int GLASS_BOARD					;
	int GLASS_BOARD_2				;
	int GLASS_BOARD_3				;
	int GLASS_B_SIDE				;
	int RUSTY_MAN					;
	int NO_SMOKE_SIGN				;
	int CARPET						;
	// Drinks Machine Textures
	int DRINKS_SIDE					;
	int DRINKS_TOP					;
	int DRINKS_EDGE					;
	int DRINKS_SIDE_2				;
	int COKE_MACHINE				;
	int COFFEE_MACHINE				;
	int SWEET_MACHINE				;
	int MACHINE_SIDES				;
	int MACHINE_SIDES_2				;
	// Telephone Box Textures
	int TELEPHONE_BACK				;
	int TELEPHONE_FRONT				;
	int TELEPHONE_SIDE_1			;
	int TELEPHONE_FRONT_2			;
	int TELEPHONE_MAIN_SIDE			;
	int TELEPHONE_TOP_1				;
	int TELEPHONE_SIDE_2			;
	int TELEPHONE_TOP_2				;
	int TELEPHONE_BOTTOM			;
	int TELEPHONE_FILL				;
	int TELEPHONE_FRONT_3			;
	// Step Textures
	int STEPS_LIBRARY				;
	int STEPS_LIBRARY_TOP			;
	int	STEP_PAVING_1				;
	int	STEP_EDGE					;

	// Larger Window and Door Textures Etc
	int WINDOW_1					;
	int WINDOW_2					;
	int WINDOW_3					;
	int WINDOW_4					;
	int WINDOW_5					;
	int WINDOW_6					;
	int WINDOW_7					;
	int WINDOW_8					;
	int WINDOW_9					;
	int WINDOW_10					;
	int WINDOW_11					;
	int WINDOW_12					;
	int WINDOW_13					;
	int WINDOW_14					;
	int WINDOW_14B					;
	int WINDOW_15					;
	int WINDOW_16					;
	int WINDOW_17					;
	int WINDOW_2B					;
	int WINDOW_2C					;
	int WINDOW_2US					;
	int WINDOW_3B					;
	int WINDOW_2USB					;
	int WINDOW_LIB_1				;
	int WINDOW_LIB_1A				;
	int WINDOW_LIB_1B				;
	int WINDOW_LIB_1C				;
	int WINDOW_LIB_US_A				;
	int WINDOW_LIB_US_B				;
	int WINDOW_LIB_DOOR_1			;
	int WINDOW_LIB_DOOR_2			;
	int WINDOW_LIB_LONG				;
	int ENTRANCE					;
	int ENTRANCE_2					;
	int EXIT_EAST					;
	int EXIT_WEST					;
	int CHANC_DOOR_1				;
	int CHANC_DOOR_2				;
	int WINDOW_2D					;
	int WINDOW_2E					;
	int WINDOW_1B					;
	int STEP_WINDOW					;

	// Above Window Block Textures
	int ABOVE_WINDOW_BLOCK			;
	int ABOVE_WINDOW_BLOCK_2		;
	int ABOVE_WINDOW_BLOCK_3		;
	int ABOVE_WINDOW_EDGE_3B		;
	int ABOVE_WINDOW_BLOCK_XY_3		;
	int	ABOVE_LIB					;
	int	ABOVE_UNDER_POSTS			;
	int ABOVE_UNDER_POSTS_2			;
	int ABOVE_WINDOW_UNDER_LIB		;
	int ABOVE_WINDOW_BLOCK_CHANC	;
	int ABOVE_WINDOW_EDGE_3B_LIB	;
	int ABOVE_WINDOW_EDGE_4B_LIB	;
	int ABOVE_UNDER_4B				;
	int ABOVE_CHANC_TEXT			;
	int ABOVE_CHANC_TEXT_2			;
	int ABOVE_PHYS_SCI_TEXT			;
	int ABOVE_CHANC_TEXT_3			;
	int ABOVE_LIB_TEXT				;
	int ABOVE_LIB_TEXT_2			;
	int ABOVE_TICKETS_TEXT			;
	int ABOVE_CHANC_EDGE			;
	int TOILET_DOOR_TOP				;
	// Light Fitting Textures
	int LIGHT						;
	int	LIGHT_SUPPORT				;
	int	LIGHT_SUPPORT_2				;
	// Bench Textures
	int BENCH_TOP					;
	int BENCH_SIDE					;
	int BENCH_SIDE_2				;
	int BENCH_EDGE					;
	int BENCH_EDGE_TOP				;
	int BENCH_EDGE_SIDE				;
	int BENCH_EDGE_TOP_2			;
	int BENCH_EDGE_2				;
	int BENCH_EDGE_3				;
	// Ticket Counter and Ledge Textures
	int TICKET_COUNTER_TOP			;
	int TICKET_COUNTER_EDGE			;
	int TICKET_COUNTER_EDGE_2		;
	int TICKET_COUNTER_EDGE_3		;
	int TICKET_LEDGE				;
	int TICKET_LEDGE_EDGE			;
	int TICKET_LEDGE_EDGE_2			;
	// Wall by Steps Textures
	int WALL_BRICK_STEPS_TOP		;
	int WALL_BRICK_STEPS			;
	int WALL_BRICK_STEPS_COVER		;
	int WALL_BRICK_STEPS_EDGE		;
	int WALL_BRICK_STEPS_EDGE_2		;
	// Extra Textures
	int DRAINPIPE					;
	int COUNTER_TOP					;
	int COUNTER_SIDE				;
	// Welcome, Exit and Map Screens
	int MAP							;
	int WELCOME						;
	int EXIT						;
	int NO_EXIT						;

	GameMain GameMainLoop;

	GLdouble stepIncrement;
	GLdouble angleIncrement;
	int frameCount;
	clock_t lastClock;

	// ratio of screen
	float ratio;
	// screen width and height
	int width, height;

	// display campus map
	bool DisplayMap;
	// display welcome screen
	bool DisplayWelcome;
	// display exit screen
	bool DisplayExit;
	// display light fittings
	bool lightsOn;
	// display ECL block
	bool displayECL;

	// varibles used for tarnslating graphics etc
	GLdouble step, step2, stepLength;

	// Glut Cylinder
	GLUquadricObj *glu_cylinder;

	// Stores raw image file
	unsigned char* image;

	// objects
	Camera cam;
	TexturedPolygons tp;

private:

};


