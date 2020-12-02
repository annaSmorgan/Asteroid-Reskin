//created by Anna Morgan
//created in 2020
//this file sets up score board cpp
#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H
// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class ScoreBoard 
{
public:
	// Constructor / Destructor
	ScoreBoard();
	~ScoreBoard();

	//functions
	void Draw(Scene* pScene);
	float UserChoice(Scene* pScene);
	std::string ConvertScore(int score);

private:
	//variables
	olc::Sprite* title;
	olc::Sprite* dragonImg;

};

#endif //!SCORE_BOARD_H