//  Centipede
//  Joseph Walker, September 2016

#ifndef _CentipedeHead
#define _CentipedeHead

#include "Game Components\TEAL\CommonElements.h"

// Centipede
#include "CentipedeBase.h"
#include "MushroomGrid.h"

// Movement
#include "CentipedeMoveState.h"
#include "CentipedeMoveCollection.h"

// Segments
#include "CentipedeSegmentFactory.h"
#include "CentipedeHeadFactory.h"

// Sound
#include "SoundManager.h"

class CentipedeBase;

class CentipedeHead : public CentipedeBase
{
public:
	CentipedeHead();

	CentipedeHead* Initialize(sf::Vector2f position, const CentipedeMoveState* movementState , int numSegments);

	// Collisions
	virtual void Collision(GameObject *go) {};
	virtual void Collision(Bullet *other);

	// Position
	int getRow();
	int getColumn();
	const CentipedeMoveState* getPreviousState();

private:

	void prvtReset();

	// Sprite
	int animationStart = 0;
	int animationStop = 7;
	float spriteScale = 2;
	int frameCounterStop = 7;

	// Virtual methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Sprite and collision
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap *bitmap;

	// Direction Vectors
	sf::Vector2f *nextDirection;

	// Mushroom Check
	bool mushroomToRight = true;
	bool mushroomToLeft = false;

	// CentipedeSegments
	int prvtNumSegments;
	void prvtCreateCentipedeHead();
	void prvtCreateSegment(sf::Vector2f position, int numSegments);
};

#endif _Centipede