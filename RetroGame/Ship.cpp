//created by Anna Morgan
//created in 2020
//this file sets up and runs the player, checking for player input
//defines
#define  OLC_PGEX_GRAPHICS2D
// Includes
#include "Ship.h"
#include "Scene.h"
#include "olcPGEX_Graphics2D.h"

// Namespaces
using namespace olc;

Ship::Ship()
{
	// Load our sprite
	playerSprite = new Sprite("Resources/dragon.png");
	playerSprite2 = new Sprite("Resources/dragon2.png");
	playerSprite3 = new Sprite("Resources/dragon3.png");
	projectileSprite = new Sprite("Resources/iceball.png");
	
	// Set the starting variables
	position = { 20.0f, 120.0f};
	forward = { 0.0f, -1.0f };
	acceleration = 0.0f;
	rotation = 0.0f;
	size = { (float)playerSprite->width, (float)playerSprite->height };//set size of sprite
	//set the start varaibles for bullets
	isFired = false;
	bulletRotation = rotation;
	bulletPosition = position;
	bulletSpeed = 0.0f;
	sizeB = { (float)projectileSprite->width, (float)projectileSprite->height };//set size of sprite
	
}

void Ship::Update(Scene* pScene, float fElapsedTime)
{//setting the x and y for easier access
	float x = position.GetX();
	float y = position.GetY();
	// Forward
	if (pScene->GetKey(Key::W).bHeld)
	{//increasing the acceleration
		acceleration += 0.03f * fElapsedTime;
		//restricting the max speed
		if (acceleration >= 0.1f)
		{
			acceleration = 0.1f;
		}
	}
	else if (acceleration > 0.0f)
	{//start decreasing acceleration once not holding forward
		acceleration -= 0.05f * fElapsedTime;
	}

	//Rotation
	if (pScene->GetKey(Key::A).bHeld)
	{
		rotation += 0.001f; //increase rotation
	}
	else if (pScene->GetKey(Key::D).bHeld)
	{
		rotation -= 0.001f;//decrease rotation
	}
	//fire bullet on space
	if (pScene->GetKey(Key::SPACE).bReleased)
	{
		isFired = true;//set true
	}
	//if bullet wasnt fired set default values
	if (isFired == false)
	{
		bulletRotation = rotation;
		bulletPosition = position;
		bulletSpeed = 0.0f;
	}
	//bullet was fired adjust rotation and speed
	else if (isFired == true)
	{
		bulletRotation = bulletRotation;
		bulletSpeed += 0.1f*fElapsedTime;
		//restricting the max speed
		if (bulletSpeed >= 0.15f)
		{
			isFired = false;
		}
	}
	//wrapping the drawn spirits around the window, meaning theyll appear on the other side of the screen
	WrapCoord(pScene, x, y, bulletPosition.GetX(), bulletPosition.GetY());	
	
}

void Ship::Draw(Scene* pScene, float fElapsedTime)
{
	//player transform
	GFX2D::Transform2D playerTransform;
	//translate to middle of sprite
	playerTransform.Translate(-(playerSprite->width * 0.5f), -(playerSprite->height * 0.5f));
	////transform rotation
	playerTransform.Rotate(rotation);
	//find new forward
	forward.SetX(cos(-rotation));
	forward.SetY(sin(-rotation));
	////transform forward
	position += (forward * acceleration);
	//position in middle
	playerTransform.Translate(position.GetX(), position.GetY());
	//switch on the player sprite
	switch (currentPlayerSprite)
	{
		case WINGSNORMAL: //default sprite
		{
			if (isFired == true)//if fired
			{
				whenToChangeSprite = 0.0f;//reset timer
				currentPlayerSprite = BREATHINGICE; //move to other sprite
			}

			whenToChangeSprite += fElapsedTime; //create timer
			if (whenToChangeSprite <= 1.5f) //if under limit
			{	//draw transform
				GFX2D::DrawSprite(playerSprite, playerTransform);
			}
			else
			{
				whenToChangeSprite = 0.0f; //reset timer
				currentPlayerSprite = WINGSRAISED; //move to other sprite
			}
			break;
		}
		case WINGSRAISED: //other sprite while flying
		{
			if (isFired == true)//if fired
			{
				whenToChangeSprite = 0.0f;//reset timer
				currentPlayerSprite = BREATHINGICE;//move to other sprite
			}

			whenToChangeSprite += fElapsedTime;//create timer
			if (whenToChangeSprite <= 1.0f)//if under limit
			{//draw transform
				GFX2D::DrawSprite(playerSprite2, playerTransform);
			}
			else
			{
				whenToChangeSprite = 0.0f;//reset timer
				currentPlayerSprite = WINGSNORMAL;//move to other sprite
			}
			break;
		}
		case BREATHINGICE://sprite while firing
		{
			whenToChangeSprite += fElapsedTime;//create timer
			if (whenToChangeSprite <= 0.1f)//if under limit
			{//draw transform
				GFX2D::DrawSprite(playerSprite3, playerTransform);
			}
			else
			{
				whenToChangeSprite = 0.0f;//reset timer
				currentPlayerSprite = WINGSNORMAL;//move to other sprite
			}
			break;
		}
		default:
		{ 
			break;
		}

	}	

	//display bullet if fired
	if (isFired == true)
	{
		//bullet transform
		GFX2D::Transform2D bulletTransform;
		//translate to middle of sprite
		bulletTransform.Translate((playerSprite->width * 0.3f), -(playerSprite->height * 0.5f));
		////transform rotation
		bulletTransform.Rotate(bulletRotation);
		//find new forward
		bulletForward.SetX(cos(-bulletRotation));
		bulletForward.SetY(sin(-bulletRotation));
		////transform forward
		bulletPosition += (bulletForward * bulletSpeed);
		//position in middle
		bulletTransform.Translate(bulletPosition.GetX(), bulletPosition.GetY());
		//draw transform
		GFX2D::DrawSprite(projectileSprite, bulletTransform);
	}
}

void Ship::WrapCoord(Scene* pScene, float inX, float inY, float inX2, float inY2)
{
	//player
	if (inX < 0.0f) //if x is below 0
	{
		position.SetX(inX + (float)pScene->ScreenWidth());//move the position to the other side of the screen
	}
	if (inX >= (float)pScene->ScreenWidth())//if bigger then the screen width
	{
		position.SetX(inX - (float)pScene->ScreenWidth());//move the position to the other side of the screen
	}
	if (inY < 0.0f)//if y is below 0
	{
		position.SetY(inY + (float)pScene->ScreenHeight());//move the position to the other side of the screen
	}
	if (inY >= (float)pScene->ScreenHeight())//if bigger then the screen height
	{
		position.SetY(inY - (float)pScene->ScreenHeight());//move the position to the other side of the screen
	}
	//bullet
	if (inX2 < 0.0f)
	{
		bulletPosition.SetX(inX2 + (float)pScene->ScreenWidth());//move the position to the other side of the screen
	}
	if (inX2 >= (float)pScene->ScreenWidth())//if bigger then the screen width
	{
		bulletPosition.SetX(inX2 - (float)pScene->ScreenWidth());//move the position to the other side of the screen
	}
	if (inY2 < 0.0f)//if y is below 0
	{
		bulletPosition.SetY(inY2 + (float)pScene->ScreenHeight());//move the position to the other side of the screen
	}
	if (inY2 >= (float)pScene->ScreenHeight())//if bigger then the screen height
	{
		bulletPosition.SetY(inY2 - (float)pScene->ScreenHeight());//move the position to the other side of the screen
	}
	
}

void Ship::Reset()
{
	// Set the starting variables
	position = { 20.0f, 120.0f };
	forward = { 0.0f, -1.0f };
	acceleration = 0.0f;
	rotation = 0.0f;
	isFired = false;
	bulletRotation = rotation;
	bulletPosition = position;
	bulletSpeed = 0.0f;
}

