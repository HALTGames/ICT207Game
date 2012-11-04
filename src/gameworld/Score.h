#ifndef SCORE_H
#define SCORE_H

class Score
{
public:
	
	~Score(void) {}//instanceFlag = false;}

	//static Score* GetInstance();

	float GetTotalScore() const {return TotalScore;}
	float GetHighScore() const {return HighScore;}

	void Modify(float Mod);
	void CheckHighScore();
	static Score* Instance();

private:
	//static bool instanceFlag;
	//static Score *singleton;
	
	Score(void)	{}

	void SetTotalScore(float T) {TotalScore = T;}
	void SetHighScore(float H){HighScore = H;}

	static float TotalScore;
	static float HighScore;
};



#endif