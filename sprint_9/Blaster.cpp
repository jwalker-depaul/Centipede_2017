// Ship
// Joseph Walker, September 2016

#include "Blaster.h"
#include "BlasterManager.h"

Blaster::Blaster()
{
	
	//Barrier
	//prvtXMinBarrier already set
	prvtXMaxBarrier = float (WindowManager::MainWindow.getView().getSize().x - prvtBarrierOffset);
	//prvtYMinBarrier already set
	prvtYMaxBarrier = float (WindowManager::MainWindow.getView().getSize().y - prvtMainSprite.getTextureRect().height - prvtBarrierOffset);

	// Movement
	prvtCurrentPosition = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / prvtSpriteTextureRectDivision, WindowManager::MainWindow.getView().getSize().y);
	prvtNewMovementVector = sf::Vector2f(0, 0); //Stationary movement. Use += offset to change

	// Sprites
	prvtMainSprite = AnimatedSprite(ResourceManager::GetTexture("Blaster"), prvtSpriteTextureRows, prvtSpriteTextureColumns);
	prvtMainSprite.setOrigin(prvtMainSprite.getTextureRect().width / prvtSpriteTextureRectDivision, prvtMainSprite.getTextureRect().height / prvtSpriteTextureRectDivision);
	prvtMainSprite.setScale(prvtSpriteScale, prvtSpriteScale);
	prvtMainSprite.setPosition(prvtCurrentPosition);

	// Collision
	prvtBitmap = ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(prvtMainSprite, prvtBitmap);
	RegisterCollision<Blaster>(*this);
	
}

/**************************************
***         Virtual Methods         ***
**************************************/

void Blaster::Update() //Movement Controlls and starting position
{
	// Record past position
	prvtXPrevious = prvtCurrentPosition.x;
	prvtYPrevious = prvtCurrentPosition.y;

	// Update sprite
	prvtMainSprite.Update();

	// Update movement direction
	prvtNewMovementVector += prvtMovementDirection();

	// Update with new position
	prvtCurrentPosition += prvtNewMovementVector;

	// Keep player clamped inside the screen
	Tools::Clamp<float>(prvtCurrentPosition.x, prvtXMinBarrier, prvtXMaxBarrier);
	Tools::Clamp<float>(prvtCurrentPosition.y, prvtYMinBarrier, prvtYMaxBarrier);

	// Set position with updated position
	prvtMainSprite.setPosition(prvtCurrentPosition);

	// Stop gravity from moving the ship
	prvtNewMovementVector *= .0f;
}

void Blaster::Destroy()
{
	DeregisterCollision<Blaster>(*this);
}

void Blaster::Draw()
{
	WindowManager::MainWindow.draw(prvtMainSprite);
}

/***********************************
***       Strategy Methods       ***
***********************************/

void Blaster::prvtSetStrategy(BlasterInterface* strategy)
{
	this->prvtMovementStrategy = strategy;
}



/**************************
***   Created Methods   ***
**************************/

Blaster* Blaster::Initialize(BlasterInterface* strategy)
{
	setStrategy(strategy);
	return this;
}

void Blaster::Explode()
{
	CritterDeathFactory::CreateExplosion(prvtCurrentPosition);
	BlasterManager::playerDied();

	MarkForDestroy();
}

sf::Vector2f Blaster::prvtMovementDirection()
{
	return prvtMovementStrategy->movementDirection(prvtCurrentPosition);
}

/*********************************
***         Collisions         ***
*********************************/

void Blaster::Collision(Mushroom* other)
{
	prvtCurrentPosition.x = prvtXPrevious;
	prvtCurrentPosition.y = prvtYPrevious;
	prvtMainSprite.setPosition(prvtCurrentPosition);
}

void Blaster::Collision(Scorpion* other)
{
	Explode();
}

void Blaster::Collision(Flea* other)
{
	Explode();
}

void Blaster::Collision(Spider* other)
{
	Explode();
}

void Blaster::Collision(CentipedeHead* other)
{
	Explode();
}

void Blaster::Collision(CentipedeSegment* other)
{
	Explode();
}