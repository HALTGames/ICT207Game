#ifndef SCORE_H
#define SCORE_H




//class Bird;

class Score
{
private:
	Score();
	int score;
	//may need copy constructer, assignment operator and destructer here

public:
	static Score* Instance();

	void AddToScore(int addition);
	int GetScore();


};



#endif