//created by Anna Morgan
//created in 2020
//this file sets up ship cpp
#ifndef SHIP_H
#define SHIP_H

// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"

// Forward declarations
class Scene;

class Ship 
{
public:
	// Constructor / Destructor
	Ship();
	~Ship() {}

	// Functions
	void Update(Scene* pScene, float fElapsedTime);
	void Draw(Scene* pScene, float fElapsedTime);
	void WrapCoord(Scene* pScene, float inX, float inY, float inX2, float inY2);
	void Reset();


	// Getters / Setters
	olc::Sprite* GetSprite() { return playerSprite; }
	Vector2D& GetPosition() { return position; }
	Vector2D& GetPositionB() { return bulletPosition; }
	void SetSprite(olc::Sprite* a_sprite) { playerSprite = a_sprite; }
	void SetPosition(Vector2D a_position) { position = a_position; }
	void SetIsFire(bool bulletFired) { isFired = bulletFired; }
	Vector2D& GetSize() { return size; }
	Vector2D& GetSizeB() { return sizeB; }

protected:
	// Variables
	olc::Sprite* playerSprite;
	olc::Sprite* playerSprite2;
	olc::Sprite* playerSprite3;
	Vector2D position;
	Vector2D forward;
	Vector2D size;
	Vector2D sizeB;
	float acceleration;
	float rotation;
	float whenToChangeSprite = 0.0f;
	//enum for player sprites
	enum playerSprites
	{
		WINGSNORMAL,
		WINGSRAISED,
		BREATHINGICE
	};
	playerSprites currentPlayerSprite = WINGSNORMAL;
	//bullet variables
	olc::Sprite* projectileSprite;
	Vector2D bulletPosition;
	Vector2D bulletForward;
	float bulletRotation;
	float bulletSpeed;
	float isFired;

};

#endif //!SHIP_H
