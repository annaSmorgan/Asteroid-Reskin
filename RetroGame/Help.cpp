//created by Anna Morgan
//created in 2020
//this file sets up the dispplay for helping the player play the game
// includes
#include "Includes/Help.h"
#include "Includes/Scene.h"
#include "Vector2D.h"
//namespace
using namespace olc;

Help::Help()
{
	//load sprites
	title = new Sprite("Resources/title.png");
	dragonImg = new Sprite("Resources/icySideWays.png");
}

void Help::Draw(Scene* pScene)
{
	//draw the title which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() / 2.0f) - 75, 10, title);
	//draw the dragon img which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() - 100), 30, dragonImg);
	//controls being written to screen
	pScene->DrawString(1, 70, "Controls", CYAN, 2U);
	pScene->DrawString(1, 90, "W - Forward", DARK_CYAN, 1U);
	pScene->DrawString(1, 100, "A - Turn Left", DARK_CYAN, 1U);
	pScene->DrawString(1, 110, "D - Turn Right", DARK_CYAN, 1U);
	pScene->DrawString(1, 120, "Space - Fire", DARK_CYAN, 1U);
	//objective written to screen
	pScene->DrawString(1, 145, "Objective", BLUE, 2U);
	pScene->DrawString(1, 165, "~ Shoot Fireballs For Points", DARK_BLUE, 1U);
	pScene->DrawString(1, 175, "~ Collect Ice Arrows - ", DARK_BLUE, 1U);
	pScene->DrawString(1, 185, "  To Slow The Fireballs", DARK_BLUE, 1U);
	pScene->DrawString(1, 195, "~ Keep Going For Higher Scores", DARK_BLUE, 1U);
	//go back to the menu
	pScene->DrawString((float)pScene->ScreenWidth() / 6, 215, "Back     press 1", DARK_YELLOW, 1U);
}

float Help::UserChoice(Scene* pScene)
{//if 1 if pressed on num pad or keyboard
	if (pScene->GetKey(Key::NP1).bPressed || pScene->GetKey(Key::K1).bPressed)
	{
		return 1.0f;
	}

}
