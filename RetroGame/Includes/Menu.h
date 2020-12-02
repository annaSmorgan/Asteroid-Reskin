//created by Anna Morgan
//created in 2020
//this file sets up menu cpp
#ifndef MENU_H
#define MENU_H
// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class Menu
{
public:
	// Constructor / Destructor
	Menu();
	~Menu() {}

	//functions
	void Draw(Scene* pScene);
	float UserChoice(Scene* pScene);

private:
	//variables
	olc::Sprite* title;
	olc::Sprite* dragonImg;
};

#endif //!MENU_H