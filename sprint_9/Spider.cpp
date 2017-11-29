#include "Spider.h"

Spider::Spider()
{
	// Barriers
	windowSizeX = float(WindowManager::MainWindow.getView().getSize().x);

	// Sprite
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2, animationFPS);
	MainSprite.SetAnimation(animationStart, animationStop);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(spriteScale, spriteScale);

	// Collision
	bitmap = &ResourceManager::GetTextureBitmap("Spider");
	SetCollider(MainSprite, *bitmap);

	rightSideStart = windowSizeX + 8.0f;
}

/**************************
***   Virtual Methods   ***
**************************/

void Spider::Update()
{
	MainSprite.Update();

	// Time to change directions
	if (prvtPosition.y < topZone || prvtPosition.y > bottomZone)
	{
		if (prvtRandomSpawnDirection < 2)
			prvtCurrentDirection = prvtRandomRightMovement(prvtCurrentDirection);
		else
			prvtCurrentDirection = prvtRandomLeftMovement(prvtCurrentDirection);
	}

	// Off screen detection
	if (prvtRandomSpawnDirection < 2)
	{
		if (prvtPosition.x > windowSizeX)
		{
			MarkForDestroy();
			SoundManager::endSpiderSound();
		}
	}
	else
	{
		if (prvtPosition.x < 0)
		{
			MarkForDestroy();
			SoundManager::endSpiderSound();
		}
	}

	prvtMoveSpider(prvtCurrentDirection);
}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Spider::Destroy()
{
	DeregisterCollision<Spider>(*this);

}

/**************************
***   Created Methods   ***
**************************/

Spider* Spider::Initialize()
{
	
	prvtPosition = prvtSetRandomSpawn();

	if (prvtPosition.x == leftSideStart)
	{
		prvtCurrentDirection = prvtRandomRightMovement(prvtCurrentDirection);
	}
	else
	{
		prvtCurrentDirection = prvtRandomLeftMovement(prvtCurrentDirection);
	}

	MainSprite.setPosition(prvtPosition);
	RegisterCollision<Spider>(*this);

	SoundManager::playSpiderSound();

	return this;
}

sf::Vector2f Spider::prvtSetRandomSpawn()
{
	prvtRandomSpawnDirection = rand() % 4; // 0 -> 3
	if (prvtRandomSpawnDirection == 0)
	{
		prvtCurrentDirection += moveDownRight;
		return { leftSideStart, topZone };
	}
	if (prvtRandomSpawnDirection == 1)
	{
		prvtCurrentDirection += moveUpRight;
		return { leftSideStart, bottomZone };
	}
	if (prvtRandomSpawnDirection == 2)
	{
		prvtCurrentDirection += moveDownLeft;
		return { rightSideStart, topZone };
	}
	//if (prvtRandomSpawnDirection == 3)
	prvtCurrentDirection += moveUpLeft;
	return { rightSideStart, bottomZone };
}

void Spider::Explode()
{
	ScoreManager::AddSpiderScore();
	CritterDeathFactory::CreateExplosion(prvtPosition);
	SoundManager::endSpiderSound();
	MarkForDestroy();
}

/***************************
***   Movement Methods   ***
***************************/

void Spider::prvtMoveSpider(sf::Vector2f currentDirection)
{
	prvtPosition += currentDirection;
	MainSprite.setPosition(prvtPosition);
}

sf::Vector2f Spider::prvtRandomRightMovement(sf::Vector2f currentDirection)
{
	prvtRandomMovement = rand() % 2; // 0 or 1

	if (currentDirection == moveUp || currentDirection == moveUpRight)
	{
		if (prvtRandomMovement == 0)
			return moveDown;
		else
			return moveDownRight;
	}

	//if (currentDirection == moveDown || currentDirection == moveDownRight)
	if (prvtRandomMovement == 0)
		return moveUp;
	else
		return moveUpRight;
}

sf::Vector2f Spider::prvtRandomLeftMovement(sf::Vector2f currentDirection)
{
	prvtRandomMovement = rand() % 2; // 0 or 1

	if (currentDirection == moveUp || currentDirection == moveUpLeft)
	{
		if (prvtRandomMovement == 0)
			return moveDown;
		else
			return moveDownLeft;
	}


	//else if (currentDirection == moveDown || currentDirection == moveDownLeft)
	if (prvtRandomMovement == 0)
		return moveUp;
	else
		return moveUpLeft;
}

/*********************
***   Collisions   ***
*********************/

void Spider::Collision(Bullet *other)
{
	Explode();
}