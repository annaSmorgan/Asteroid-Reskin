//created by Anna Morgan
//created in 2020
//this file sets up and runs the asteroids/enemy 
//includes
#include "Asteroids.h"
#include "Scene.h"
#include "olcPGEX_Graphics2D.h"
//namespace
using namespace olc;

Asteroids::Asteroids()
{
	// Load sprite
	asteroid = new Sprite("Resources/fireball.png");
	asteroidFrozen = new Sprite("Resources/iceball.png");
	//random variables
	randomDirX = rand() % 40 - 20;
	randomDirY = rand() % 40 - 20;
	randomPosX = rand() % 256 + 32;
	randomPosY = rand() % 240 + 1;
	position = { randomPosX, randomPosY };// Set the position 
	direction = { randomDirX, randomDirY };//set direction
	rotation = 0.0f; //set rotation
	size = { (float)asteroid->width, (float)asteroid->height }; //set size of sprite
	hit = false;  //set whether it was fit to false
}

void Asteroids::Update(Scene* pScene, float fElapsedTime)
{
	srand(std::time(0));//setting a seed value to the random function
	//setting the x and y for easier access
	float x = position.GetX(); 
	float y = position.GetY();
	//increase the position by the direction	
	position.SetX(x + direction.GetX() * fElapsedTime);
	position.SetY(y + direction.GetY() * fElapsedTime);
	//increase the rotation
	rotation += 0.3 * fElapsedTime;
	//wrap the coordinations around the screen
	WrapCoord(pScene, x, y);
	
}

void Asteroids::Draw(Scene* pScene, float fElapsedTime)
{
	GFX2D::Transform2D asteroidTransform; //create a transform
	asteroidTransform.Rotate(rotation);//rotate the transform
	asteroidTransform.Translate(position.GetX(), position.GetY()); //move transform to positon
	GFX2D::DrawSprite(asteroid, asteroidTransform); //draw the sprite according to the transform
	
}

void Asteroids::WrapCoord(Scene* pScene, float inX, float inY)
{
	if (hit == false) // only if the asteroid was not hit
	{
		if (inX < 0.0f) //if x is below 0
		{
			position.SetX(inX + (float)pScene->ScreenWidth()); //move the position to the other side of the screen
		}
		if (inX >= (float)pScene->ScreenWidth()) //if bigger then the screen width
		{
			position.SetX(inX - (float)pScene->ScreenWidth());//move the position to the other side of the screen
		}
		if (inY < 0.0f)//if y is below 0
		{
			position.SetY(inY + (float)pScene->ScreenHeight());//move the position to the other side of the screen
		}
		if (inY >= (float)pScene->ScreenHeight()) //if bigger then the screen height
		{
			position.SetY(inY - (float)pScene->ScreenHeight());//move the position to the other side of the screen
		}
	}
	else if (hit == true) // if it was hit 
	{
		position = { 4000, 4000 }; //move way beyond the screen dimensions
		direction = { 0,0 }; //stop it moving 
	}
}

void Asteroids::Reset()
{
	//set all the variables back to their starting points
	hit = false;
	randomDirX = rand() % 40 - 20;
	randomDirY = rand() % 40 - 20;
	randomPosX = rand() % 256 + 32;
	randomPosY = rand() % 240 + 1;
	position = { randomPosX, randomPosY };
	direction = { randomDirX, randomDirY };
	rotation = 0.0f;
}

void Asteroids::PowerUpEffect(float fElapsedTime)
{
	direction = { -1, -1 }; //lower the direction, so theyre more uniform and slower moving
	
}

void Asteroids::IfHit()
{
	 hit = true; //set to true as asteroid was hit

}
