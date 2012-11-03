#include "Score.h"

Score *Score::Instance()
{
	static Score instance;

	return &instance;
}

Score::Score()
{
	score = 0;
}