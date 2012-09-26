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

	int XY		0
	int XZ		1
	int YZ		2
	int YZ_FLIP 3
	int XY_FLIP 4

	// PLAIN TYPES
	int FLAT_PLAIN	0
	int XY_PLAIN	1
	int ZY_PLAIN	2

	// TEXTURES
	// Grass Textures
	int GRASS						1
	int GRASS_2						2
	int GRASS_HILL					3
	// Pavement Textures
	int PAVEMENT					4
	int PAVEMENT_TOP				5
	int PAVEMENTSIDE_LEFT			6
	int PAVEMENTSIDE_RIGHT			7
	int PAVEMENTSIDE_TOP			8
	int PAVEMENT_CORNER_1			9
	int PAVEMENT_CORNER_2			10
	int PAVEMENT_FLIP				11
	int PAVEMENT_TOP_FLIP			12
	int PAVEMENT_16					13
	int DOORPAVE_1					14
	// Wall Brick Textures
	int WALL_BRICK_YZ				15
	int WALL_BRICK_XY				16
	int WALL_BRICK_XY_87WIDTH		17
	int WALL_BRICK_GAP_YZ			18
	int WALL_BRICK_GAP2_YZ			19
	int	WALL_BRICK_USD_YZ			20
	int WALL_BRICK_XY_END			21
	int WALL_BRICK_YZ_END			22
	int	WALL_GAP_1					23
	int WALL_BRICK_3_4				24
	int SHADOW_BRICK				25
	int WALL_BRICK_SEC_SIGN			216
	// Window Post Textures
	int WINDOWPOST_CHANC_FRONT		26
	int WINDOWPOST_CHANC_RIGHT	    27
	int WINDOWPOST_CHANC_LEFT	    28
	int WINDOWLEDGE_CHANC_FRONT		29
	int WINDOWLEDGE_CHANC_TOP		30
	int WINDOWPOST_PHYSSCI_FRONT	31
	int WINDOWPOST_PHYSSCI_RIGHT	32
	int WINDOWPOST_PHYSSCI_LEFT		33
	int	WINDOWPOST_LIB_FRONT		34
	int	WINDOWPOST_LIB_LEFT			35
	int	WINDOWPOST_LIB_RIGHT		36
	// Door Post Textures
	int DOOR_POST_SECURITY			37
	// Window Ledge Textures
	int WINDOWLEDGE_PS_FRONT		38
	int WINDOWLEDGE_PS_TOP			39
	int WINDOWLEDGE_PS_BOTT			40
	int WINDOWLEDGE_LIB_A			41
	int WINDOWLEDGE_LIB_B			42
	int WINDOWLEDGE_LIB_TOP_A		43
	int WINDOWLEDGE_LIB_TOP_B		44
	int WINDOW_LEDGE_END_1			45
	int WINDOW_LEDGE_END_2			46
	// Main Post Textures
	int	MAIN_POST					47
	int	MAIN_POST_2					48
	// Door Post Textures
	int DOOR_POST_CHANC				49
	int DOOR_SIDEPOST_CHANC			50
	int DOOR_POST_LIB				215
	// Coloured Posts Textures
	int PURPLE_POST					51
	int PURPLE_POSTSIDE				52
	int RED_POST					53
	int RED_POSTSIDE				54
	// Roof Textures
	int ROOF_TOP					55
	int ROOF_TOP_LIB				56
	int ROOF_PLANKS					57
	int ROOF_BEAM_1					58
	int ROOF_PLANKS_2				59
	int ROOF_BEAM_2					60
	int BELOW_ROOF_FILL				61
	int ROOF_BEAM_3					62
	int ROOF_BEAM_4					63
	int ROOF_BEAM_3_TOP				64
	// KBLT Textures
	int KBLT						65
	int KBLT_EDGE					66
	int KBLT_EDGE_2					67
	int KBLT_EDGE_CORNER			68
	int KBLT_SIDE_1					69
	int KBLT_SIDE_2					70
	// Sign and Other Textures
	int NEXUS_SIGN					71
	int NEXUS_SIDE					72
	int SECURITY_SIGN				73
	int SECURITY_SIGN_2				74
	int SIGN_1						75
	int SIGN_1_SIDE_1				76
	int SIGN_1_SIDE_2				77
	int SIGN_2						78
	int SIGN_2_SIDE					79
	int PSC_SIGN					80
	int PSC_SIGN_2					81
	int CO_SIGN						82
	int STA_TRAVEL					83
	int STA_TRAVEL_EDGE				84
	int STA_TRAVEL_BRACKET			85
	int STA_TRAVEL_2				86
	int STA_TRAVEL_BOTTOM			87
	int TOILET_MEN					88
	int TOILET_WOMEN				89
	int GS_SIGN						90
	int GS_SIGN_2					91
	int GS_SIGN_EDGE				92
	int MAP_2						93
	int GLASS_BOARD					94
	int GLASS_BOARD_2				95
	int GLASS_BOARD_3				96
	int GLASS_B_SIDE				97
	int RUSTY_MAN					98
	int NO_SMOKE_SIGN				99
	int CARPET						100
	// Drinks Machine Textures
	int DRINKS_SIDE					101
	int DRINKS_TOP					102
	int DRINKS_EDGE					103
	int DRINKS_SIDE_2				104
	int COKE_MACHINE				105
	int COFFEE_MACHINE				106
	int SWEET_MACHINE				107
	int MACHINE_SIDES				108
	int MACHINE_SIDES_2				109
	// Telephone Box Textures
	int TELEPHONE_BACK				110
	int TELEPHONE_FRONT				111
	int TELEPHONE_SIDE_1			112
	int TELEPHONE_FRONT_2			113
	int TELEPHONE_MAIN_SIDE			114
	int TELEPHONE_TOP_1				115
	int TELEPHONE_SIDE_2			116
	int TELEPHONE_TOP_2				117
	int TELEPHONE_BOTTOM			118
	int TELEPHONE_FILL				119
	int TELEPHONE_FRONT_3			120
	// Step Textures
	int STEPS_LIBRARY				121
	int STEPS_LIBRARY_TOP			122
	int	STEP_PAVING_1				123
	int	STEP_EDGE					124

	// Larger Window and Door Textures Etc
	int WINDOW_1					125
	int WINDOW_2					126
	int WINDOW_3					127
	int WINDOW_4					128
	int WINDOW_5					129
	int WINDOW_6					130
	int WINDOW_7					131
	int WINDOW_8					132
	int WINDOW_9					133
	int WINDOW_10					134
	int WINDOW_11					135
	int WINDOW_12					136
	int WINDOW_13					137
	int WINDOW_14					138
	int WINDOW_14B					139
	int WINDOW_15					140
	int WINDOW_16					141
	int WINDOW_17					142
	int WINDOW_2B					143
	int WINDOW_2C					144
	int WINDOW_2US					145
	int WINDOW_3B					146
	int WINDOW_2USB					147
	int WINDOW_LIB_1				148
	int WINDOW_LIB_1A				149
	int WINDOW_LIB_1B				150
	int WINDOW_LIB_1C				151
	int WINDOW_LIB_US_A				152
	int WINDOW_LIB_US_B				153
	int WINDOW_LIB_DOOR_1			154
	int WINDOW_LIB_DOOR_2			155
	int WINDOW_LIB_LONG				156
	int ENTRANCE					157
	int ENTRANCE_2					158
	int EXIT_EAST					159
	int EXIT_WEST					220
	int CHANC_DOOR_1				160
	int CHANC_DOOR_2				161
	int WINDOW_2D					162
	int WINDOW_2E					163
	int WINDOW_1B					164
	int STEP_WINDOW					221

	// Above Window Block Textures
	int ABOVE_WINDOW_BLOCK			165
	int ABOVE_WINDOW_BLOCK_2		166
	int ABOVE_WINDOW_BLOCK_3		167
	int ABOVE_WINDOW_EDGE_3B		168
	int ABOVE_WINDOW_BLOCK_XY_3		169
	int	ABOVE_LIB					170
	int	ABOVE_UNDER_POSTS			171
	int ABOVE_UNDER_POSTS_2			172
	int ABOVE_WINDOW_UNDER_LIB		173
	int ABOVE_WINDOW_BLOCK_CHANC	174
	int ABOVE_WINDOW_EDGE_3B_LIB	175
	int ABOVE_WINDOW_EDGE_4B_LIB	176
	int ABOVE_UNDER_4B				177
	int ABOVE_CHANC_TEXT			178
	int ABOVE_CHANC_TEXT_2			179
	int ABOVE_PHYS_SCI_TEXT			180
	int ABOVE_CHANC_TEXT_3			181
	int ABOVE_LIB_TEXT				182
	int ABOVE_LIB_TEXT_2			183
	int ABOVE_TICKETS_TEXT			184
	int ABOVE_CHANC_EDGE			185
	int TOILET_DOOR_TOP				186
	// Light Fitting Textures
	int LIGHT						187
	int	LIGHT_SUPPORT				188
	int	LIGHT_SUPPORT_2				189
	// Bench Textures
	int BENCH_TOP					190
	int BENCH_SIDE					191
	int BENCH_SIDE_2				192
	int BENCH_EDGE					193
	int BENCH_EDGE_TOP				194
	int BENCH_EDGE_SIDE				195
	int BENCH_EDGE_TOP_2			196
	int BENCH_EDGE_2				197
	int BENCH_EDGE_3				198
	// Ticket Counter and Ledge Textures
	int TICKET_COUNTER_TOP			200
	int TICKET_COUNTER_EDGE			201
	int TICKET_COUNTER_EDGE_2		202
	int TICKET_COUNTER_EDGE_3		203
	int TICKET_LEDGE				204
	int TICKET_LEDGE_EDGE			205
	int TICKET_LEDGE_EDGE_2			206
	// Wall by Steps Textures
	int WALL_BRICK_STEPS_TOP		207
	int WALL_BRICK_STEPS			208
	int WALL_BRICK_STEPS_COVER		209
	int WALL_BRICK_STEPS_EDGE		210
	int WALL_BRICK_STEPS_EDGE_2		211
	// Extra Textures
	int DRAINPIPE					212
	int COUNTER_TOP					213
	int COUNTER_SIDE				214
	// Welcome, Exit and Map Screens
	int MAP							217
	int WELCOME						218
	int EXIT						219
	int NO_EXIT						222

private:

};

