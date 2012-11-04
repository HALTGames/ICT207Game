#include "Score.h"

float Score::HighScore = 0;
float Score::TotalScore = 0;

bool Score::instanceFlag = false;
Score* Score::singleton = 0;

Score* Score::GetInstance()
{
	if(!instanceFlag)
	{
		singleton = new Score();
		instanceFlag = true;
		return singleton;
	}
	else
	{
		return singleton;
	}
}

void Score::Modify(float Mod)
{
	TotalScore += Mod;
}

void Score::CheckHighScore()
{
	if(TotalScore > HighScore)
	{
		HighScore = TotalScore;
	}
}