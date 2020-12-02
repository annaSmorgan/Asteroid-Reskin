//created by Anna Morgan
//created in 2020
//this file sets up and runs the power up so it moves across the screen
//includes
#include "PowerUP.h"
#include "Scene.h"
#include "olcPGEX_Graphics2D.h"
//namespace
using namespace olc;

PowerUp::PowerUp()
{
	// Load sprite
	powerUpSprite = new Sprite("Resources/powerUP.png");
	positionP = { 10000, 200 };	// Set the position 
	direction = { -350, 0 };//set direction
	size = { (float)powerUpSprite->width, (float)powerUpSprite->height };//set size of sprite
	hit = false;//set whether it was fit to false
}

void PowerUp::Update(Scene* pScene, float fElapsedTime)
{//setting the x for easier access
	float x = positionP.GetX();
	//increase the position by the direction	
	positionP.SetX(x + direction.GetX() * fElapsedTime);
	//wrap the coordinations around the screen  
	WrapCoord(positionP.GetX());
}

void PowerUp::Draw(Scene* pScene, float fElapsedTime)
{
	GFX2D::Transform2D powerUpTransform;//create a transform
	powerUpTransform.Translate(positionP.GetX(), positionP.GetY());//move transform to positon
	GFX2D::DrawSprite(powerUpSprite, powerUpTransform);//draw the sprite according to the transform

}

void PowerUp::WrapCoord(float inX)
{
	//checks to see if crossed the screen and resets if it has
	if (inX < 0.0f)
	{
		Reset();
	}
	
}
void PowerUp::Reset()
{//reset the variables to starting points
	hit = false;
	positionP = { 10000, 200 };
	direction = { -350, 0 };
}

void PowerUp::IfHit()
{//if hit move out of the screen and stop it moving
	positionP = { 4000, -200 };
	direction = { 0, 0 };
}

