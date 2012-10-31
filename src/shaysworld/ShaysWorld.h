#pragma once

#define GLUT_DISABLE_ATEXIT_HACK
#define PI 3.1415962654

#include <iostream>

#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <GL/freeglut.h>
#include "camera.h"
#include "texturedPolygons.h"
#include "Wave.h"

#include "../modelimporter/Model.h"

#include "../World.h"

class ShaysWorld 
	: public World
{
public:
	ShaysWorld(void);
	~ShaysWorld(void);

	// initializes setting
	virtual void Init();

	// display functions
	virtual void Display();

	virtual void Idle();

	virtual void Reshape(int w, int h);

	virtual void Keyboard(unsigned char key, int x, int y);

	// keyboard and mouse functions
	virtual void MovementKeys(int key, int x, int y);
	virtual void ReleaseKey(int key, int x, int y);
	virtual void ReleaseKeys(unsigned char key, int x, int y);

	virtual void Mouse(int button, int state, int x, int y);

	virtual void MouseMove(int x, int y);
	virtual void GUI();
	virtual void GUIinit();

	virtual void Exit();

private:
	GLdouble movementSpeed;
	GLdouble rotationSpeed;

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

	Wave wave;

	//void drawmodel_box();

	Model pmodel1;
	Model stairs_model;
	Model display_model;
	Model billboard_model;
	Model roof_model;
	Model upper_model;
	Model bannister_model;
	Model wall_model;
	Model frame_model;

	// calls display functions below to draw the backdrops
	void DrawBackdrop();
	// functions to display display lists (images) and bind them to a texture
	void DisplayAboveWindowBlock ();
	void DisplayBench ();
	void DisplayBricks ();
	void DisplayChancPosts ();
	void DisplayCylinders ();
	void DisplayDoorPaving ();
	void DisplayDoorPosts ();
	void DisplayEntranceSteps ();
	void DisplayExtras ();
	void DisplayGrass ();
	void DisplayLargerTextures ();
	void DisplayLibraryPosts ();
	void DisplayMainPosts ();
	void DisplayPavement ();
	void DisplayPhysSciPosts ();
	void DisplayPurplePosts ();
	void DisplayRedPosts ();
	void DisplayRoof();
	void DisplayStepBricks ();
	void DisplayLights ();
	void DisplayECL ();

	// calls functions to create display lists (below)
	void CreateTextureList();
	// creates display lists
	void DrawGrass ();
	void DrawChancPosts ();
	void DrawDoorPosts ();
	void DrawPurplePosts ();
	void DrawRedPosts ();
	void DrawMainPosts ();
	void DrawAboveWindowBlock ();
	void DrawDoorPaving ();
	void DrawPhysSciPosts ();
	void DrawLibraryPosts ();
	void DrawBricks ();
	void DrawPavement ();
	void DrawExtras ();
	void DrawRoof();
	void DrawEntranceSteps ();
	void DrawLargerTextures ();
	void DrawLights ();
	void DrawBench ();
	void DrawCylinders ();
	void DrawAngledRoofBeam (int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);
	void DrawAngledRoofBeam2 (int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);
	void DrawStepBricks ();
	void DrawMapExit ();
	void DrawECL ();


	void BindBridgeWall(GLint LR);
	void BindBuildingWall();
	void BindWallPosts(GLint LR);

	void IncrementFrameCount();

	// loads images and creates texture
	void CreateTextures();
	// creates bounding boxes for collsion detection
	void CreateBoundingBoxes();
	// creates different plains
	void CreatePlains();

	// deletes image and clears memory
	void DeleteImageFromMemory(unsigned char* tempImage);

	void CreateNewBoundingBoxes();

	void CreateNewPlains();

	void DrawModels();

	void Transition();

	// TEXTURE IMAGE AXISES
	enum
	{
		XY,
		XZ,
		YZ,
		YZ_FLIP,
		XY_FLIP
	};

	// PLAIN TYPES
	enum 
	{ 
		FLAT_PLAIN, 
		XY_PLAIN,
		ZY_PLAIN
	};

	enum
	{
		// TEXTURES
		// Grass Textures
		GRASS,
		GRASS_2					,
		GRASS_HILL				,
		// Pavement Textures
		PAVEMENT				,
		PAVEMENT_TOP			,
		PAVEMENTSIDE_LEFT		,	
		PAVEMENTSIDE_RIGHT		,	
		PAVEMENTSIDE_TOP		,
		PAVEMENT_CORNER_1		,	
		PAVEMENT_CORNER_2		,	
		PAVEMENT_FLIP			,	
		PAVEMENT_TOP_FLIP		,	
		PAVEMENT_16				,
		DOORPAVE_1				,	
		// Wall Brick Textures
		WALL_BRICK_YZ			,	
		WALL_BRICK_XY			,	
		WALL_BRICK_XY_87WIDTH	,	
		WALL_BRICK_GAP_YZ		,	
		WALL_BRICK_GAP2_YZ		,	
		WALL_BRICK_USD_YZ		,	
		WALL_BRICK_XY_END		,	
		WALL_BRICK_YZ_END		,	
		WALL_GAP_1				,	
		WALL_BRICK_3_4			,	
		SHADOW_BRICK			,	
		WALL_BRICK_SEC_SIGN		,	
		// Window Post Textures
		WINDOWPOST_CHANC_FRONT	,	
		WINDOWPOST_CHANC_RIGHT	 ,   
		WINDOWPOST_CHANC_LEFT	  ,  
		WINDOWLEDGE_CHANC_FRONT		,
		WINDOWLEDGE_CHANC_TOP	,	
		WINDOWPOST_PHYSSCI_FRONT,	
		WINDOWPOST_PHYSSCI_RIGHT,	
		WINDOWPOST_PHYSSCI_LEFT	,	
		WINDOWPOST_LIB_FRONT	,	
		WINDOWPOST_LIB_LEFT		,	
		WINDOWPOST_LIB_RIGHT	,	
		// Door Post Textures
		DOOR_POST_SECURITY		,	
		// Window Ledge Textures
		WINDOWLEDGE_PS_FRONT	,	
		WINDOWLEDGE_PS_TOP		,	
		WINDOWLEDGE_PS_BOTT		,	
		WINDOWLEDGE_LIB_A		,	
		WINDOWLEDGE_LIB_B		,	
		WINDOWLEDGE_LIB_TOP_A	,	
		WINDOWLEDGE_LIB_TOP_B	,	
		WINDOW_LEDGE_END_1		,	
		WINDOW_LEDGE_END_2		,	
		// Main Post Textures
		MAIN_POST			,		
		MAIN_POST_2			,		
		// Door Post Textures
		DOOR_POST_CHANC		,		
		DOOR_SIDEPOST_CHANC	,		
		DOOR_POST_LIB		,		
		// Coloured Posts Textures
		PURPLE_POST			,		
		PURPLE_POSTSIDE		,		
		RED_POST			,		
		RED_POSTSIDE		,		
		// Roof Textures
		ROOF_TOP			,		
		ROOF_TOP_LIB		,		
		ROOF_PLANKS			,	
		ROOF_BEAM_1			,	
		ROOF_PLANKS_2		,		
		ROOF_BEAM_2			,	
		BELOW_ROOF_FILL		,	
		ROOF_BEAM_3			,	
		ROOF_BEAM_4			,	
		ROOF_BEAM_3_TOP		,	
		// KBLT Textures
		KBLT				,		
		KBLT_EDGE			,		
		KBLT_EDGE_2			,	
		KBLT_EDGE_CORNER	,		
		KBLT_SIDE_1			,		
		KBLT_SIDE_2			,		
		// Sign and Other Textures
		NEXUS_SIGN			,		
		NEXUS_SIDE			,		
		SECURITY_SIGN		,		
		SECURITY_SIGN_2		,	
		SIGN_1				,		
		SIGN_1_SIDE_1		,		
		SIGN_1_SIDE_2		,		
		SIGN_2				,		
		SIGN_2_SIDE			,	
		PSC_SIGN			,		
		PSC_SIGN_2			,		
		CO_SIGN				,	
		STA_TRAVEL			,		
		STA_TRAVEL_EDGE		,	
		STA_TRAVEL_BRACKET	,		
		STA_TRAVEL_2		,		
		STA_TRAVEL_BOTTOM	,		
		TOILET_MEN			,		
		TOILET_WOMEN		,		
		GS_SIGN				,	
		GS_SIGN_2			,		
		GS_SIGN_EDGE		,		
		MAP_2				,		
		GLASS_BOARD			,	
		GLASS_BOARD_2		,		
		GLASS_BOARD_3		,		
		GLASS_B_SIDE		,		
		RUSTY_MAN			,		
		NO_SMOKE_SIGN		,		
		CARPET				,		
		// Drinks Machine Textures
		DRINKS_SIDE			,	
		DRINKS_TOP			,		
		DRINKS_EDGE			,	
		DRINKS_SIDE_2		,		
		COKE_MACHINE		,		
		COFFEE_MACHINE		,		
		SWEET_MACHINE		,		
		MACHINE_SIDES		,		
		MACHINE_SIDES_2		,	
		// Telephone Box Textures
		TELEPHONE_BACK		,		
		TELEPHONE_FRONT		,	
		TELEPHONE_SIDE_1	,		
		TELEPHONE_FRONT_2	,		
		TELEPHONE_MAIN_SIDE	,	
		TELEPHONE_TOP_1		,	
		TELEPHONE_SIDE_2	,		
		TELEPHONE_TOP_2		,	
		TELEPHONE_BOTTOM	,		
		TELEPHONE_FILL		,		
		TELEPHONE_FRONT_3	,		
		// Step Textures
		STEPS_LIBRARY		,		
		STEPS_LIBRARY_TOP	,		
		STEP_PAVING_1		,	
		STEP_EDGE			,	

		// Larger Window and Door Textures Etc
		WINDOW_1			,		
		WINDOW_2			,		
		WINDOW_3			,		
		WINDOW_4			,		
		WINDOW_5			,		
		WINDOW_6			,		
		WINDOW_7			,		
		WINDOW_8			,		
		WINDOW_9			,		
		WINDOW_10			,		
		WINDOW_11			,		
		WINDOW_12			,		
		WINDOW_13			,		
		WINDOW_14			,		
		WINDOW_14B			,		
		WINDOW_15			,		
		WINDOW_16			,		
		WINDOW_17			,		
		WINDOW_2B			,		
		WINDOW_2C			,		
		WINDOW_2US			,		
		WINDOW_3B			,		
		WINDOW_2USB			,	
		WINDOW_LIB_1		,		
		WINDOW_LIB_1A		,		
		WINDOW_LIB_1B		,		
		WINDOW_LIB_1C		,		
		WINDOW_LIB_US_A		,	
		WINDOW_LIB_US_B		,	
		WINDOW_LIB_DOOR_1	,		
		WINDOW_LIB_DOOR_2	,		
		WINDOW_LIB_LONG		,	
		ENTRANCE			,		
		ENTRANCE_2			,		
		EXIT_EAST			,		
		EXIT_WEST			,		
		CHANC_DOOR_1		,		
		CHANC_DOOR_2		,		
		WINDOW_2D			,		
		WINDOW_2E			,		
		WINDOW_1B			,		
		STEP_WINDOW			,	

		// Above Window Block Textures
		ABOVE_WINDOW_BLOCK		,	
		ABOVE_WINDOW_BLOCK_2	,	
		ABOVE_WINDOW_BLOCK_3	,	
		ABOVE_WINDOW_EDGE_3B	,	
		ABOVE_WINDOW_BLOCK_XY_3	,
		ABOVE_LIB				,
		ABOVE_UNDER_POSTS		,
		ABOVE_UNDER_POSTS_2		,
		ABOVE_WINDOW_UNDER_LIB	,	
		ABOVE_WINDOW_BLOCK_CHANC,	
		ABOVE_WINDOW_EDGE_3B_LIB,	
		ABOVE_WINDOW_EDGE_4B_LIB,	
		ABOVE_UNDER_4B			,	
		ABOVE_CHANC_TEXT		,	
		ABOVE_CHANC_TEXT_2		,	
		ABOVE_PHYS_SCI_TEXT		,
		ABOVE_CHANC_TEXT_3		,	
		ABOVE_LIB_TEXT			,	
		ABOVE_LIB_TEXT_2		,	
		ABOVE_TICKETS_TEXT		,	
		ABOVE_CHANC_EDGE		,	
		TOILET_DOOR_TOP			,
		// Light Fitting Textures
		LIGHT					,	
		LIGHT_SUPPORT			,
		LIGHT_SUPPORT_2			,
		// Bench Textures
		BENCH_TOP				,	
		BENCH_SIDE				,	
		BENCH_SIDE_2			,	
		BENCH_EDGE				,	
		BENCH_EDGE_TOP			,	
		BENCH_EDGE_SIDE			,
		BENCH_EDGE_TOP_2		,	
		BENCH_EDGE_2			,	
		BENCH_EDGE_3			,	
		// Ticket Counter and Ledge Textures
		TICKET_COUNTER_TOP		,	
		TICKET_COUNTER_EDGE		,
		TICKET_COUNTER_EDGE_2	,	
		TICKET_COUNTER_EDGE_3	,	
		TICKET_LEDGE			,	
		TICKET_LEDGE_EDGE		,	
		TICKET_LEDGE_EDGE_2		,
		// Wall by Steps Textures
		WALL_BRICK_STEPS_TOP	,	
		WALL_BRICK_STEPS		,	
		WALL_BRICK_STEPS_COVER	,	
		WALL_BRICK_STEPS_EDGE	,	
		WALL_BRICK_STEPS_EDGE_2	,
		// Extra Textures
		DRAINPIPE				,	
		COUNTER_TOP				,
		COUNTER_SIDE			,	
		// Welcome, Exit and Map Screens
		MAP						,
		WELCOME					,
		EXIT					,	
		NO_EXIT					,

		ME						,	
	};
};

