#include "Mushroom.h"

Mushroom::Mushroom()
{
	// Sprite
	prvtMainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), prvtSpriteTextureColumns, prvtSpriteTextureRows); // From load all resources
	prvtMainSprite.SetAnimation(prvtKeyFrame, prvtKeyFrame);
	prvtMainSprite.setOrigin(prvtMainSprite.getTextureRect().width / prvtSpriteTextureRectDivision, prvtMainSprite.getTextureRect().height / prvtSpriteTextureRectDivision);
	prvtMainSprite.setScale(prvtSpriteScale, prvtSpriteScale);

	//Collision
	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(prvtMainSprite, *bitmap);
}

Mushroom* Mushroom::Initialize(sf::Vector2f position, MushroomGrid* mushroomGrid)
{
	prvtReset();
	prvtPosition = position;
	prvtMushroomGrid = mushroomGrid;

	prvtMainSprite.SetAnimation(prvtKeyFrame, prvtKeyFrame);

	RegisterInput(InputFlags::KeyPressed);
	RegisterCollision<Mushroom>(*this);
	prvtMainSprite.setPosition(prvtPosition);

	return this;
}

void Mushroom::prvtReset()
{
	prvtKeyFrame = 0;
	prvtHealth = 0;
}

/**************************
***   Virtual Methods   ***
**************************/

void Mushroom::Draw() //Draws sprite in window
{
	WindowManager::MainWindow.draw(prvtMainSprite);
}

void Mushroom::Destroy() //Destroy call by "MarkForDestroy()"
{
	prvtMushroomGrid->deleteMushroom(prvtPosition);
	DeregisterCollision<Mushroom>(*this);
	DeregisterInput();
}

void Mushroom::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::P)
	{
		prvtSetPoisonMushroom();
	}
}

void Mushroom::prvtSetPoisonMushroom()
{
	prvtKeyFrame = 4 + prvtHealth;
	prvtMainSprite.SetAnimation(prvtKeyFrame, prvtKeyFrame);
	prvtPoisonMushroom = true;
}

/*********************
***   Collisions   ***
*********************/

void Mushroom::Collision(Bullet *other) //Collisions with bullet
{
	//Normal Mushrooms
	if (prvtHealth <= prvtMaxHealth)
	{
		prvtHealth ++;
		prvtKeyFrame ++;
		prvtMainSprite.SetAnimation(prvtKeyFrame, prvtKeyFrame);
	}
	else if (prvtHealth > prvtMaxHealth)
	{
		ScoreManager::AddDestroyMushroomScore();
		MarkForDestroy();
	}
}

void Mushroom::Collision(Spider* other)
{
	MarkForDestroy();
}