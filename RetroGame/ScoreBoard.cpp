//created by Anna Morgan
//created in 2020
//this file sets up the display of the score
// includes
#include "ScoreBoard.h"
#include "Includes/Scene.h"
#include "Vector2D.h"
//namespace
using namespace olc;

ScoreBoard::ScoreBoard()
{
	//load sprites
	title = new Sprite("Resources/title.png");
	dragonImg = new Sprite("Resources/icySideWays.png");
}

void ScoreBoard::Draw(Scene* pScene)
{
	//draw the title which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() / 2.0f) - 75, 10, title);
	//draw the dragon img which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() - 100), 30, dragonImg);
	//draw the text for the title previous score
	pScene->DrawString(5, (float)pScene->ScreenHeight() - 140, "Previous Score:", WHITE, 1U);
	//draw the previous scrore once conveted to string
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 120, ConvertScore(pScene->GetScore()), CYAN, 1U);
	//go back to the menu
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 110, "Back     press 1", BLUE, 1U);
}

float ScoreBoard::UserChoice(Scene* pScene)
{//if 1 is pressed on keyboard or numpad
	if (pScene->GetKey(Key::NP1).bPressed || pScene->GetKey(Key::K1).bPressed)
	{
		return 1.0f;
	}
}

std::string ScoreBoard::ConvertScore(int score)
{//converts the int into a string
	std::string stringScore = std::to_string(score);
	return stringScore;
}
