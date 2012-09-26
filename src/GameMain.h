#pragma once
#define GLUT_DISABLE_ATEXIT_HACK

#include <gl\freeglut.h>
#include "glm.h"

		/**
		 * @class GameMain
		 * @brief This class controls our game loop, it is used to distinguish our game stuff from everything in shays world / shays game loop. It handles resetting of the game world, as well as setting it up.
		 * 
		 * @author Hamish Carrier
		 * @version 1.3.19 
		 * @date 16/09/2012 
		 *
		 */


class GameMain
{
public:
	GameMain(void);
	~GameMain(void);

		/** 
		 * @brief Used to setup and run our Game Loop
		 *
		 * @return void
		 */
	void GameLoop();
		/** 
		 * @brief Function used in rendering our world, fed into glut display function.
		 * 
		 * @return void
		 */
	static void RenderWorld(void);
		/** 
		 * @brief Function used to overwrite shays keyboard callback function (stub for now)
		 * 
		 * @param int key stub variable
		 * @param int x stub variable
		 * @param int y stub variable
		 *
		 * @return void
		 */
	static void EmptyFunc(int key, int x, int y);
		/** 
		 * @brief Function used to overwrite shays keymap callback function (stub for now)
		 * 
		 * @param char key stub variable
		 * @param int x stub variable
		 * @param int y stub variable
		 *
		 * @return void
		 */
	static void KeyMap(unsigned char key, int x, int y);
		/** 
		 * @brief Function used to overwrite shays mouse callback function (stub for now)
		 * 
		 * @param int button stub variable
		 * @param int state stub variable
		 * @param int x stub variable
		 * @param int y stub variable
		 *
		 * @return void
		 */
	static void Mouse(int button, int state, int x, int y);
		/** 
		 * @brief Used to import our island model
		 *
		 * @return void
		 */
	static void DrawModel();

private:

};

