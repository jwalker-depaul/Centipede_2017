//  Scorpion
//  Joseph Walker, September 2016

#include "Scorpion.h"

Scorpion::Scorpion()
{
	//Position
	windowSizeX = float(WindowManager::MainWindow.getView().getSize().x);

	//Sprite
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1, animationFPS);
	MainSprite.SetAnimation(animationStart, animationStop);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(prvtSpriteScale.x, prvtSpriteScale.y);

	//Collision
	bitmap = &ResourceManager::GetTextureBitmap("Scorpion");
	SetCollider(MainSprite, *bitmap);
}

/**************************************
***         Virtual Methods         ***
**************************************/

void Scorpion::Update()
{
	MainSprite.Update();
	prvtPosition.x += Game::FrameTime() * prvtSpeed;

	// Off screen detection
	if (privRandomDirection == 0)
	{
		// Left to right
		if (prvtPosition.x > windowSizeX)
		{
			MarkForDestroy();
			SoundManager::endScorpionSound();
		}
	}
	else 
	{
		// Right to left
		if (prvtPosition.x < 0)
		{
			MarkForDestroy();
			SoundManager::endScorpionSound();
		}
	}
	
	sf::Vector2i tempPosition = MushroomGrid::convertScreenToGrid(prvtPosition);
	if (MushroomGrid::isMushroom({ tempPosition.y, tempPosition.x }))
	{
		MushroomGrid::setPoisonMushroom({ tempPosition.y, tempPosition.x });
	}

	MainSprite.setPosition({ prvtPosition.x, prvtPosition.y });
}

void Scorpion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Scorpion::Destroy()
{
	DeregisterCollision<Scorpion>(*this);
}

/**************************************
***         Created Methods         ***
**************************************/

Scorpion* Scorpion::Initialize()
{
	// Set the spawn position, speed, and rotation
	prvtPosition = prvtSetRandomSpawn();

	// Update the rotation / scale
	MainSprite.setScale(prvtSpriteScale.x, prvtSpriteScale.y);

	// Set the position
	MainSprite.setPosition(prvtPosition);
	RegisterCollision<Scorpion>(*this);

	// Sound
	SoundManager::playScorpionSound();

	return this;
}

sf::Vector2f Scorpion::prvtSetRandomSpawn()
{
	// Choose random direction to move in
	privRandomDirection = rand() % 2;

	// Set random row
	prvtRandomRow = (float)(rand() % prvtRows - 1);
	prvtRandomRow *= prvtSpriteSize;
	prvtRandomRow += 8;

	// Move left to right
	if (privRandomDirection == 0)
	{
		// Left to Right
		prvtSpriteScale = { -1, 1 };
		prvtSpeed = prvtSpeed;
		return { -offset, prvtRandomRow };
	}
	else
	{
		// Right to Left
		prvtSpriteScale = { 1, 1 };
		prvtSpeed = -prvtSpeed;
		return { windowSizeX + offset, prvtRandomRow };
	}
}

void Scorpion::Explode()
{
	ScoreManager::AddScorpionScore();
	CritterDeathFactory::CreateExplosion(prvtPosition);
	SoundManager::endScorpionSound();
	MarkForDestroy();
}

/*********************************
***         Collisions         ***
*********************************/

void Scorpion::Collision(Bullet *other) //Collide with bullet
{
	Explode();
}