//created by Anna Morgan
//created in 2020
//this file sets up help cpp
#ifndef HELP_H
#define HELP_H
// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class Help
{
public:
	// Constructor / Destructor
	Help();
	~Help() {}

	//functions
	void Draw(Scene* pScene);
	float UserChoice(Scene* pScene);

private:
	//variables
	olc::Sprite* title;
	olc::Sprite* dragonImg;

};

#endif //!HELP_H