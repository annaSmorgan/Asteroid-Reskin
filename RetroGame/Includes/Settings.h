//created by Anna Morgan
//created in 2020
//this file sets up settings cpp
#ifndef SETTINGS_h
#define SETTINGS_h
// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class Settings
{
public:
	// Constructor / Destructor
	Settings();
	~Settings() {}

	//functions
	void Draw(Scene* pScene);
	float UserChoice(Scene* pScene);
	//getters
	int GetDifficulty() { return difficultyValue; }

private:
	//variables
	olc::Sprite* title;
	olc::Sprite* dragonImg;
	int difficultyValue;
	
};

#endif //!SETTINGS_h