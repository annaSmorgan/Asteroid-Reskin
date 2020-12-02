//created by Anna Morgan
//created in 2020
//this file sets up the menu display
// includes
#include "Includes/Menu.h"
#include "Includes/Scene.h"
#include "Vector2D.h"
//namespace
using namespace olc;

Menu::Menu()
{
	title = new Sprite("Resources/title.png");
	dragonImg = new Sprite("Resources/icySideWays.png");
}

void Menu::Draw(Scene* pScene)
{
	//draw the title which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() / 2.0f) - 75, 10, title);
	//draw the dragon img which is a png
	pScene->DrawSprite(((float)pScene->ScreenWidth() - 100), 30, dragonImg);
	//draw the text for the menu
	pScene->DrawString(40, (float)pScene->ScreenHeight() - 160, "Menu", WHITE, 2U);
	//play gameplay option
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 130, "Play       press 1", CYAN, 1U);
	//open the settings option
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 120, "Settings   press 2", DARK_CYAN, 1U);
	//open the scoreboard option
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 110, "Scores     press 3", BLUE, 1U);
	//open the help option
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 100, "Help       press 4", DARK_BLUE, 1U);
	//close the application
	pScene->DrawString(1, (float)pScene->ScreenHeight() - 90, "Exit       press esc", DARK_YELLOW, 1U);
}

float Menu::UserChoice(Scene* pScene)
{//if 1 if pressed on num pad or keyboard
	if (pScene->GetKey(Key::NP1).bPressed || pScene->GetKey(Key::K1).bPressed)
	{
		return 1.0f;
	}
	//if 2 if pressed on num pad or keyboard
	else if (pScene->GetKey(Key::NP2).bPressed || pScene->GetKey(Key::K2).bPressed)
	{
		return 2.0f;
	}
	//if 3 if pressed on num pad or keyboard
	else if (pScene->GetKey(Key::NP3).bPressed || pScene->GetKey(Key::K3).bPressed)
	{
		return 3.0f;
	}
	//if 4 if pressed on num pad or keyboard
	else if (pScene->GetKey(Key::NP4).bPressed || pScene->GetKey(Key::K4).bPressed)
	{
		return 4.0f;
	}
	
}
