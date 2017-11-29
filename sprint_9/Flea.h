#ifndef _Flea
#define _Flea

#include "Game Components\TEAL\CommonElements.h"
#include "MushroomGrid.h"
#include "CritterDeathFactory.h"
#include "ScoreManager.h"
#include "SoundManager.h"

//Forward Declerations
class Bullet;

class Flea : public GameObject
{
public:
	Flea();

	Flea* Initialize();

	// Collision
	virtual void Collision(GameObject * go) {};
	void Collision(Bullet * other);

private:

	// Virtual Methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Created Methods
	void prvtResetFlea();
	void Explode();
	sf::Vector2f prvtSetSpawn();

	// Position
	float prvtCurrentSpeed;
	float prvtMaxSpeed = 4;
	float prvtMinSpeed = 2;
	float prvtWindowSizeY;
	int prvtSpriteSize;
	sf::Vector2f prvtPosition;
	sf::Vector2f prvtRandomCollumn;

	// Mushroom spawning
	int prvtRandom;
	int prvtCollumns = 30;
	int frameCounter;
	int frequency = 5;

	// Sprite
	AnimatedSprite MainSprite;
	float animationFPS = 15.0f;
	float spriteScale = 1.0f;
	int animationStart = 0;
	int animationStop = 3;
	float offScreen = -8.0f;

	// Collision
	CollisionTools::TextureBitmap* bitmap;

	// Health
	int health = 2;
	int healthMax = 2;
};

#endif _Flea
