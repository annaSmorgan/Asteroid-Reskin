//created by Anna Morgan
//created in 2020
//this file sets up and runs the scene, this is where all functions and classes are run from
//defines
#define  OLC_PGEX_SOUND
// Includes
#include "Scene.h"
#include "Ship.h"
#include "Asteroids.h"
#include "Vector3D.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Settings.h"
#include "Collisons.h"
#include "ScoreBoard.h"
#include "olcPGEX_Sound.h"
#include "PowerUP.h"
#include "Help.h"

Scene::Scene()
{
	sAppName = "Dragon Reskin Of Asteroid";//give the application name
}

// Called once at the start, so create things here
bool Scene::OnUserCreate()
{
	// Create a new instances
	settings = new Settings();
	playerShip = new Ship();
	for (int i = 0; i < settings->GetDifficulty(); i++)
	{
		asteroids[i] = new Asteroids;
	}
	splashScreen = new SplashScreen();
	menu = new Menu();
	scoreBoard = new ScoreBoard();
	help = new Help();
	powerup = new PowerUp();
	//set the hit counter to 0
	hitCounter = 0;
	/*olc::SOUND::AudioSample* sound = new olc::SOUND::AudioSample("Resources/dragonSound.mp3");*/
	return true;
}

// Called once per frame
bool Scene::OnUserUpdate(float fElapsedTime)
{
	// UPDATE
	/////////////////////////////

	// Should we quit?
	if (GetKey(olc::Key::ESCAPE).bPressed)
	{
		return false;
	}
	switch (currentGameState) //switch on the game state
	{
		case SPLASH: //splash screen
		{
			//start a countdown for the splash screen
			splashDuration += fElapsedTime;
			Clear(olc::Pixel()); //clear the screen
			if (splashDuration <= 5.0f) //while its below the time limit
			{
				splashScreen->Draw(this); //tun the splash draw function
				/*olc::SOUND::PlaySample(olc::SOUND::LoadAudioSample(sound), true);*/
			}
			else if (splashDuration > 5.0f)//once timer is up
			{
				splashDuration = 0.0f; //Reset the timer
				currentGameState = MENU; //move game state to the menu
			}
			break;
		}
		case MENU://main menu
		{
			Clear(olc::Pixel()); // clear the screen
			float userMenuInput = menu->UserChoice(this); //store the result of this function in a float
			if (userMenuInput == 1.0f) //if 1 pressed
			{
				currentGameState = GAMEPLAY; //move to gameplay state
			}
			else if (userMenuInput == 2.0f)//if 1 pressed
			{
				currentGameState = SETTINGS;//move to settings state
			}
			else if (userMenuInput == 3.0f)//if 1 pressed
			{
				currentGameState = SCORES;//move to scores state
			}
			else if (userMenuInput == 4.0f)//if 1 pressed
			{
				currentGameState = HELP;//move to help state
			}
			
			menu->Draw(this); //run the draw fucntion for the menu
			break;
		}
		case SETTINGS://game settings
		{
			Clear(olc::Pixel()); // clear the screen
			float userSettingsInput = settings->UserChoice(this);//store the result of this function in a float
			if (userSettingsInput == 4.0f)//if 4 pressed
			{
				currentGameState = MENU;//move game state to the menu
			}

			settings->Draw(this); //run the draw fucntion for the menu
			break;
		}
		case SCORES://scoreboard
		{
			LoadScore();//load the txt holding scores
			Clear(olc::Pixel()); // clear the screen
			float userScoreInput = scoreBoard->UserChoice(this);//store the result of this function in a float
			if (userScoreInput == 1.0f)//if 1 pressed
			{
				currentGameState = MENU;//move game state to the menu
			}
			scoreBoard->Draw(this); //run the draw fucntion for the menu
			break;
		}
		case HELP:
		{
			Clear(olc::Pixel()); // clear the screen
			float userScoreInput = help->UserChoice(this);//store the result of this function in a float
			if (userScoreInput == 1.0f)//if 1 pressed
			{
				currentGameState = MENU;//move game state to the menu
			}
			help->Draw(this); //run the draw fucntion for the menu
			break;
		}
		case GAMEPLAY: //main game
		{
			//clear screen
			Clear(olc::Pixel());
			// Update our player ship
			playerShip->Update(this, fElapsedTime);
			//Update the asteriods
			for (int i = 0; i < settings->GetDifficulty(); i++)
			{
				asteroids[i]->Update(this, fElapsedTime);
			}
			//update the power up
			powerup->Update(this, fElapsedTime);

			// DRAW
			/////////////////////////////

			// Clear the previous frame
			Clear(olc::Pixel());

			// Enables alpha blending
			SetPixelMode(olc::Pixel::ALPHA);

			// Draw the score
			DrawString(ScreenWidth()/2 - 25, 3, "Score: "+ConvertScore(playerScore), olc::DARK_YELLOW, 1U);
			//draw the player
			playerShip->Draw(this, fElapsedTime);
			//draw the asteroids
			for (int i = 0; i < settings->GetDifficulty(); i++)
			{
				asteroids[i]->Draw(this, fElapsedTime);
			}
			//draw the power up
			powerup->Draw(this, fElapsedTime);

			//checking for collisons with the ship and asteroid
			for (int i = 0; i < settings->GetDifficulty(); i++)//loop through all asteroids
			{//if there was a collsions
				if (collisons->ShipCollisons(playerShip->GetPosition(), asteroids[i]->GetPosition(), asteroids[i]->GetSize(), playerShip->GetSize()) == true)
				{
					currentGameState = MENU;//send back to menu game state
					playerShip->Reset();//Reset player
					powerup->Reset();//Reset power up
					SaveScore();//save the score to the txt
					playerScore = 0;//Reset the score
					for (int j = 0; j < settings->GetDifficulty(); j++)//loop through asteroids
					{
						asteroids[j]->Reset();//Reset asteroid
						hitCounter = 0; //Reset hit counter
					}
					
				}
			}
			//checking for collisons with the bullets and asteroid
			for (int i = 0; i < settings->GetDifficulty(); i++)//loop through all asteroids
			{//if there was a collsions
				if (collisons->BulletCollisons(playerShip->GetPositionB(), asteroids[i]->GetPosition(), asteroids[i]->GetSize(), playerShip->GetSizeB()) == true)
				{
					IncreaseScore();//increase the score
					asteroids[i]->IfHit(); //mark asteroid as hit
					hitCounter++; //increase hit counter
				}		
				
			}
			//checking for collisons with power up and ship
			if (collisons->PowerUpCollisons(powerup->GetPosition(), playerShip->GetPosition(), playerShip->GetSize(), powerup->GetSize()) == true)
			{//if there was a collsions
				powerup->IfHit();//mark power up as hit
				BigIncreaseScore();//increase the score
				for (int j = 0; j < settings->GetDifficulty(); j++)//loop through all asteroids
				{//run the power up function on asteroid
					asteroids[j]->PowerUpEffect(fElapsedTime);
				}
			}
			//checks if all asteroids are hit
			if (hitCounter >= settings->GetDifficulty())
			{
				BigIncreaseScore();//increases score
				for (int j = 0; j < settings->GetDifficulty(); j++)//loops through all asteroids
				{
					asteroids[j]->Reset();//Resets asteroids
					hitCounter = 0; //rests hit counter
				}
			}

			return true;

			break;
		}
		default:
		{
			break;
		}
	}
}

void Scene::LoadScore()
{
	std::fstream file;//open a fstream
	file.open("Resources/save.txt");//open the txt file
	file >> previousScore;//store data from file in previous score
	file.close();//close file
}

std::string Scene::ConvertScore(int score)
{
	//converts the int into a string
	std::string stringScore = std::to_string(score);
	return stringScore;
	
}

void Scene::SaveScore()
{
	std::fstream file;//open a fstream
	file.open("Resources/save.txt");//open the txt file
	file << playerScore << std::endl;//stores player score in file
	file.close();//close file
}


