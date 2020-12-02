//created by Anna Morgan
//created in 2020
//this file sets up power up cpp
#ifndef POWER_UP_H
#define POWER_UP_H
//includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
// Forward declarations
class Scene;

class PowerUp
{
public:
	// Constructor / Destructor
	PowerUp();
	~PowerUp();

	// Functions
	void Update(Scene* pScene, float fElapsedTime);
	void Draw(Scene* pScene, float fElapsedTime);
	void WrapCoord(float inX);
	void Reset();
	void IfHit();

	// Getters / Setters
	olc::Sprite* GetSprite() { return powerUpSprite; }
	Vector2D& GetPosition() { return positionP; }
	Vector2D& GetSize() { return size; }
	void SetSprite(olc::Sprite* a_sprite) { powerUpSprite = a_sprite; }
	void SetPosition(Vector2D a_position) { positionP = a_position; }

private:
	// Variables
	olc::Sprite* powerUpSprite;
	Vector2D positionP;
	Vector2D direction;
	Vector2D size;
	bool hit;
};
#endif //!POWER_UP_H