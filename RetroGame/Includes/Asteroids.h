//created by Anna Morgan
//created in 2020
//this file sets up asteroids cpp
#ifndef _ASTEROIDS_H
#define _ASTEROIDS_H
//includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
//forward declaration
class Scene;

class Asteroids
{
public:
	// Forward declarations
	Asteroids();
	~Asteroids();
	
	// Functions
	void Update(Scene* pScene, float fElapsedTime);
	void Draw(Scene* pScene, float fElapsedTime);
	void WrapCoord(Scene* pScene, float inX, float inY);
	void Reset();
	void PowerUpEffect(float fElapsedTime);
	void IfHit();

	// Getters / Setters
	olc::Sprite* GetSprite() { return asteroid; }
	Vector2D& GetPosition() { return position; }
	Vector2D& GetSize() { return size; }
	void SetSprite(olc::Sprite* a_sprite) { asteroid = a_sprite; }
	void SetPosition(Vector2D a_position) { position = a_position; }

private:
	// Variables
	olc::Sprite* asteroid;
	olc::Sprite* asteroidFrozen;
	Vector2D position;
	Vector2D direction;
	Vector2D size;
	float rotation;
	float randomDirX;
	float randomDirY;
	float randomPosX;
	float randomPosY;
	bool hit;
	
};

#endif //!_ASTEROIDS_H