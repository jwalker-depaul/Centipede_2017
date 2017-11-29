#ifndef _Mushroom
#define _Mushroom

#include "Game Components\TEAL\CommonElements.h"
#include "ScoreManager.h"
#include "MushroomGrid.h"

class Bullet;
class Spider;

class Mushroom : public GameObject 
{
public:
	Mushroom();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

	Mushroom* Initialize(sf::Vector2f position, MushroomGrid* mushroomGrid);

	// Collisions
	virtual void Collision(GameObject *other) {};
	virtual void Collision(Bullet* other);
	virtual void Collision(Spider* other);

	// Created Methods
	sf::Vector2f getPosition() { return prvtPosition; };

	// Poision Mushrooms
	bool isPoisionMushroom()
	{
		return prvtPoisonMushroom;
	}
	void setPoisonMushroom()
	{
		prvtSetPoisonMushroom();
	}

private:

	void prvtReset();

	// Virtual methods
	virtual void Draw();
	virtual void Destroy();

	// Variables
	int prvtHealth = 0;
	int prvtMaxHealth = 2;
	int prvtKeyFrame = 0; // First frame of animation
	MushroomGrid* prvtMushroomGrid;
	bool prvtPoisonMushroom = false;

	// Position
	sf::Vector2f prvtPosition;
	sf::Vector2f prvtLocalArrayLocation; // Location recorded in MushroomGrid

	// Sprite variables
	AnimatedSprite prvtMainSprite; // On screen sprite
	int prvtSpriteTextureColumns		= 4;
	int prvtSpriteTextureRows			= 2;
	float prvtSpriteScale				= 1.0f;
	float prvtSpriteTextureRectDivision = 2.0f;

	// Collisions
	CollisionTools::TextureBitmap* bitmap;

	// Created Methods
	void prvtSetPoisonMushroom();


};

#endif _Mushroom
