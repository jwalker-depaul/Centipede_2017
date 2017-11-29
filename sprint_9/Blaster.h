// Ship
// Joseph Walker, September 2016

#ifndef _Blaster
#define _Blaster

#include "Game Components\TEAL\CommonElements.h"
#include "blaster_interface.h"
#include "CritterDeathFactory.h"

//Forward declarations
class Mushroom;
class Scorpion;
class Flea;
class Spider;
class CentipedeHead;
class CentipedeSegment;

class Blaster : public GameObject
{
public:
	Blaster();
	Blaster* Initialize(BlasterInterface* strategy);

	// Strategies
	void setStrategy(BlasterInterface* strategy) { prvtSetStrategy(strategy); }; // Accessor (Does this one help?)
	
	// Collision
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Scorpion* other);
	virtual void Collision(Flea* other);
	virtual void Collision(Spider* other);
	virtual void Collision(CentipedeHead* other);
	virtual void Collision(CentipedeSegment* other);

private:
	
	sf::Vector2f prvtMovementDirection();

	// Virtual methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Death
	void Explode();

	// Collisions
	CollisionTools::TextureBitmap prvtBitmap;

	// Barriers
	float prvtXMinBarrier = 8.0;
	float prvtXMaxBarrier;
	float prvtYMinBarrier = 342.0;
	float prvtYMaxBarrier;
	int prvtBarrierOffset = 8;

	// Positions
	sf::Vector2f prvtCurrentPosition;
	float prvtXPrevious;
	float prvtYPrevious;

	// Movement
	sf::Vector2f prvtNewMovementVector;
	float prvtSpeed = 230;
	float prvtOffset;

	// Sprites
	AnimatedSprite prvtMainSprite;
	int prvtSpriteTextureColumns		= 1;
	int prvtSpriteTextureRows			= 1;
	float prvtSpriteScale				= 1.0f;
	float prvtSpriteTextureRectDivision = 2.0f;
	
	// Strategy
	void prvtSetStrategy(BlasterInterface* strategy);
	BlasterInterface* prvtMovementStrategy;

};

#endif _Ship

