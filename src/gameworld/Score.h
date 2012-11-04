#ifndef SCORE_H
#define SCORE_H

/**
*\class Score
*\brief keeps track of score
*
*this is a singleton class that stores
*the current score and has functions for updating it
*
*\author Hamish/arran
*/
class Score
{
public:
	
	///destructor
	~Score(void) {}//instanceFlag = false;}

	//static Score* GetInstance();
	///Gets the total score
	float GetTotalScore() const {return TotalScore;}
	///gets the high score
	float GetHighScore() const {return HighScore;}
	///modifies the current health by amount passed in
	void Modify(float Mod);
	///Checks if total score is higher than high score
	void CheckHighScore();
	///creates a static instance of score
	static Score* Instance();

private:
	//static bool instanceFlag;
	//static Score *singleton;
	///constructer for score
	Score(void)	{}
	///total score setter
	void SetTotalScore(float T) {TotalScore = T;}
	///High score setter
	void SetHighScore(float H){HighScore = H;}
	///The total score
	static float TotalScore;
	///The high score
	static float HighScore;
};



#endif