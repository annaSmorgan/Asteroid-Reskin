//created by Anna Morgan
//created in 2020
//this file sets up splash screen cpp
#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H
// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class SplashScreen
{
public:
	// Constructor / Destructor
	SplashScreen();
	~SplashScreen() {}

	//functions
	void Draw(Scene* pScene);

private:
	//variables
	olc::Sprite* title;
	olc::Sprite* dragon;

};

#endif //!SPLASH_SCREEN_H