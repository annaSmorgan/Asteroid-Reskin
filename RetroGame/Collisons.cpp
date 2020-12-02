//created by Anna Morgan
//created in 2020
//this file sets up the collisions 
//includes
#include "Collisons.h"
#include "Scene.h"
#include "Vector2D.h"
//namespace
using namespace olc;

bool Collisons::ShipCollisons(Vector2D shipPos, Vector2D asteroidPos, Vector2D sizeA, Vector2D sizeS)
{
	//seperating out the vectors into variables
	float shipX = shipPos.GetX();
	float shipY = shipPos.GetY();
	float shipW = sizeS.GetX();
	float shipH = sizeS.GetY();
	float asteroidX = asteroidPos.GetX();
	float asteroidY = asteroidPos.GetY();
	float asteroidW = sizeA.GetX();
	float asteroidH = sizeA.GetY();
	//creating a box collison area around both images based on their sprite sizes
	if (shipX < (asteroidX + asteroidW) && 
		(shipX + shipW) > asteroidX &&
		shipY < (asteroidY + asteroidH) &&
		(shipY + shipH) > asteroidY
		)
	{
		return true; //if one box overlaps the other
	}

	return false;

}

bool Collisons::BulletCollisons(Vector2D bulletPos, Vector2D asteroidPos, Vector2D sizeA, Vector2D sizeB)
{
	//seperating out the vectors into variables
	float bulletX = bulletPos.GetX();
	float bulletY = bulletPos.GetY();
	float bulletW = sizeB.GetX();
	float bulletH = sizeB.GetY();
	float asteroidX = asteroidPos.GetX();
	float asteroidY = asteroidPos.GetY();
	float asteroidW = sizeA.GetX();
	float asteroidH = sizeA.GetY();
	//creating a box collison area around both images based on their sprite sizes
	if (bulletX < (asteroidX + asteroidW) &&
		(bulletX + bulletW) > asteroidX&&
		bulletY < (asteroidY + asteroidH) &&
		(bulletY + bulletH) > asteroidY
		)
	{
		return true;//if one box overlaps the other
	}

	return false;
}

bool Collisons::PowerUpCollisons(Vector2D powerUpPos, Vector2D shipPos, Vector2D sizeS, Vector2D sizeP)
{
	//seperating out the vectors into variables
	float powerUpX = powerUpPos.GetX();
	float powerUpY = powerUpPos.GetY();
	float powerUpW = sizeP.GetX();
	float powerUpH = sizeP.GetY();
	float shipX = shipPos.GetX();
	float shipY = shipPos.GetY();
	float shipW = sizeS.GetX();
	float shipH = sizeS.GetY();
	//creating a box collison area around both images based on their sprite sizes
	if (powerUpX < (shipX + shipW) &&
		(powerUpX + powerUpW) > shipX&&
		powerUpY < (shipY + shipH) &&
		(powerUpY + powerUpH) > shipY
		)
	{
		return true;//if one box overlaps the other
	}

	return false;

}
