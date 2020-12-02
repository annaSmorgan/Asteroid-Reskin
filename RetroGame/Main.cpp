//created by Anna Morgan
//created in 2020
//this file sets up the window and runs the game
//defines
#define OLC_PGE_APPLICATION
//includes
#include "olcPixelGameEngine.h"
#include "Scene.h"
#include "olcPGEX_Graphics2D.h"
#include "olcPGEX_Sound.h"

int main()
{
	// Entry point for our game
	Scene retroGameScene;
	if (retroGameScene.Construct(256, 240, 4, 4))//construct dimensions
	{
		retroGameScene.Start();
	}

	return 0;
}