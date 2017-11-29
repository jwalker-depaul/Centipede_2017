#ifndef _CentipedeSegment
#define _CentipedeSegment

#include "Game Components\TEAL\CommonElements.h"
#include "CritterDeathFactory.h"
#include "MushroomGrid.h"

// Centipede
#include "CentipedeBase.h"
#include "CentipedeHeadFactory.h"

// Movement
#include "CentipedeMoveState.h"
#include "CentipedeMoveCollection.h"

// Segment
#include "CentipedeSegmentFactory.h"

class CentipedeBase;

class CentipedeSegment : public CentipedeBase
{
public:
	CentipedeSegment();

	CentipedeSegment* Initialize(sf::Vector2f position, int numSegments);
	
	// Collisions
	virtual void Collision(GameObject *go) {};
	virtual void Collision(Bullet *other);
	void setNextState(const CentipedeMoveState* state) { prvtSetNextState(state); };

private:

	void prvtReset();

	// Virtual methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Sprite and Collision
	AnimatedSprite prvtMainSprite;
	CollisionTools::TextureBitmap *bitmap;
	float prvtScale = 2;
	int animationStart = 0;
	int animationStop = 7;

	// Direction Vectors
	sf::Vector2f *nextDirection;
	void prvtSetNextState(const CentipedeMoveState*);

	// Segments
	int prvtNumSegments;
	void prvtCreateSegment(sf::Vector2f position, int numSegments);
};

#endif _CentipedeSegment