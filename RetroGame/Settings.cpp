//created by Anna Morgan
//created in 2020
//this file sets up the setting display and alters the amount of asteroids
// includes
#include "Includes/Settings.h"
#include "Includes/Scene.h"
#include "Vector2D.h"
//namespace
using namespace olc;

Settings::Settings()
{
	//load sprites
	title = new Sprite("Resources/title.png");
	dragonImg = new Sprite("Resources/icySideWays.png");
	//set the default difficulty
	difficultyValue = 6;
}

void Settings::Draw(Scene* pScene)
{
	//draw the title which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() / 2.0f) - 75, 10, title);
	//draw the dragon img which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() - 100), 30, dragonImg);
	//draw the text for the settings
	pScene->DrawString(5, (float)pScene->ScreenHeight() - 160, "Settings", WHITE, 2U);
	//set the difficulty to easy
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 130, "Easy     press 1", CYAN, 1U);
	//set the difficulty to normal
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 120, "Normal   press 2", DARK_CYAN, 1U);
	//go back to the menu
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 100, "Back     press 3", BLUE, 1U);
}

float Settings::UserChoice(Scene* pScene)
{//if 1 if pressed on num pad or keyboard
	if (pScene->GetKey(Key::NP1).bPressed || pScene->GetKey(Key::K1).bPressed)
	{
		difficultyValue = 3;//set difficulty by changing the amount of asteroids
		return 4.0f;
	}
	//if 2 if pressed on num pad or keyboard
	else if (pScene->GetKey(Key::NP2).bPressed || pScene->GetKey(Key::K2).bPressed)
	{
		difficultyValue = 6;//set difficulty by changing the amount of asteroids
		return 4.0f;
	}
	//if 2 if pressed on num pad or keyboard
	else if (pScene->GetKey(Key::NP3).bPressed || pScene->GetKey(Key::K3).bPressed)
	{
		return 4.0f;
	}

}
