//created by Anna Morgan
//created in 2020
//this file sets up scene cpp
#ifndef SCENE_H
#define SCENE_H

// Includes
#include "olcPixelGameEngine.h"

// Forward declarations
class Ship;
class Asteroids;
class SplashScreen;
class Menu;
class Settings;
class Collisons;
class Score;
class ScoreBoard;
class PowerUp;
class Help;

class Scene : public olc::PixelGameEngine
{
public:
	//constructor
	Scene();
	//overload functions
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	//functions
	void LoadScore();
	//getter
	int GetScore() { return previousScore; }

private:
	//class pointer 
	Ship* playerShip;
	SplashScreen* splashScreen;
	Menu* menu;
	Settings* settings;
	Asteroids* asteroids[9];
	Collisons* collisons;
	Score* score;
	ScoreBoard* scoreBoard;
	PowerUp* powerup;
	Help* help;
	//enum for game state
	enum gameStates
	{
		SPLASH,
		MENU,
		SETTINGS,
		SCORES,
		HELP,
		GAMEPLAY,
	};
	//private functions
	void IncreaseScore() { playerScore += 100; } // add 100 onto the player score
	void BigIncreaseScore() { playerScore += 500; } //add 500 onto player score
	std::string ConvertScore(int score);
	void SaveScore();
	//variables
	int hitCounter;
	int previousScore = 0;
	int playerScore = 0;

	float splashDuration = 0.0f; //a variable set to time how long the solash screen has been shown
protected:
	//current game state
	gameStates currentGameState = SPLASH;

};

#endif //!SCENE_H
