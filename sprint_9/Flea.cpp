#include "Flea.h"

Flea::Flea()
{
	// Position
	prvtCurrentSpeed = prvtMinSpeed;
	prvtWindowSizeY = float(WindowManager::MainWindow.getView().getSize().y);

	// Sprite
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2, animationFPS);
	MainSprite.SetAnimation(animationStart, animationStop);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(spriteScale, spriteScale);
	prvtSpriteSize = MainSprite.getTextureRect().width;

	// Collision
	bitmap = &ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, *bitmap);

	// Mushrooms
	frameCounter = prvtSpriteSize / (int)prvtMinSpeed;
}

/**************************************
***         Virtual Methods         ***
**************************************/

void Flea::Update()
{
	MainSprite.Update();
	prvtPosition.y += prvtCurrentSpeed;

	// If past the bottom of the screen, destroy
	if (prvtPosition.y > prvtWindowSizeY)
	{
		SoundManager::endFleaSound();
		MarkForDestroy();
	}


	if (frameCounter == 0)
	{
		frameCounter = prvtSpriteSize / (int)prvtCurrentSpeed; // reset the frame counter

		prvtRandom = rand() % frequency;
		if (prvtRandom == 0)
		{
			sf::Vector2i tempPositionMushroom = MushroomGrid::convertScreenToGrid(prvtPosition);
			MushroomGrid::createMushroom({ tempPositionMushroom.x - 1, tempPositionMushroom.y });
		}

	}

	frameCounter--;

	MainSprite.setPosition(prvtPosition);
}

void Flea::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Flea::Destroy()
{
	health = healthMax;
	DeregisterCollision<Flea>(*this);

}

/**************************************
***         Created Methods         ***
**************************************/

Flea* Flea::Initialize()
{
	prvtResetFlea();

	prvtPosition = prvtSetSpawn();
	MainSprite.setPosition(prvtPosition);
	RegisterCollision<Flea>(*this);
	SoundManager::playFleaSound();

	return this;
}

sf::Vector2f Flea::prvtSetSpawn()
{
	prvtRandom = rand() % prvtCollumns;
	prvtRandom *= (prvtSpriteSize / 2);
	return { (float)prvtRandom, offScreen };
}

void Flea::prvtResetFlea()
{
	health = healthMax;
	prvtCurrentSpeed = prvtMinSpeed;
}

void Flea::Explode()
{
	ScoreManager::AddFleaScore();
	CritterDeathFactory::CreateExplosion(prvtPosition);
	SoundManager::endFleaSound();
	MarkForDestroy();
}

/*********************************
***         Collisions         ***
*********************************/

void Flea::Collision(Bullet *other)
{
	if (health == healthMax)
	{
		prvtCurrentSpeed = prvtMaxSpeed;
		health--;
	}
	else
	{
		Explode();
	}

}