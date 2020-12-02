//created by Anna Morgan
//created in 2020
//this file sets up and runs the splash screen display
//includes
#include "Includes/SplashScreen.h"
#include "Includes/Scene.h"
#include "Vector2D.h"
//namespace
using namespace olc;

SplashScreen::SplashScreen()
{
	//setting the sprites to their relative PNG files
	title  = new Sprite("Resources/title.png");
	dragon = new Sprite("Resources/dragonSplash.png");
}

void SplashScreen::Draw(Scene* pScene)
{
	//drawing the sprites to the screen
	pScene->DrawSprite(((float)pScene->ScreenWidth()/2.0f)-75, 10, title);
	pScene->DrawSprite(((float)pScene->ScreenWidth() / 2.0f) - 75, (float)pScene->ScreenHeight() -170, dragon);
}
