//created by Anna Morgan
//created in 2020
//this file sets up collisons cpp
#ifndef COLLISONS_H
#define COLLISONS_H
//includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class Collisons
{
public:

	// Functions
	bool ShipCollisons(Vector2D shipPos, Vector2D asteroidPos, Vector2D sizeA, Vector2D sizeS);
	bool BulletCollisons(Vector2D bulletPos, Vector2D asteroidPos, Vector2D sizeA, Vector2D sizeB);
	bool PowerUpCollisons(Vector2D powerUpPos, Vector2D shipPos, Vector2D sizeS, Vector2D sizeP);
	
};
#endif //!COLLISONS_H