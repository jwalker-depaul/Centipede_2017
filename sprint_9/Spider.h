#ifndef _Spider
#define _Spider

#include "Game Components\TEAL\CommonElements.h"
#include "SpiderMovement.h"
#include "CritterDeathFactory.h"
#include "ScoreManager.h"
#include "SoundManager.h"

class Bullet;
class Mushroom;

class Spider : public SpiderMovement
{
public:
	Spider();

	Spider* Initialize();

	// Collision
	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* other);

private:

	// Virtual Methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Created Methods
	void Explode();

	// Barriers
	const float topZone = 380.0;
	const float bottomZone = 480.0;
	float windowSizeX;

	//Movement
	void prvtMoveSpider(sf::Vector2f currentDirection);
	int prvtRandomMovement;
	int prvtRandomSpawnDirection;
	sf::Vector2f prvtSetRandomSpawn();
	sf::Vector2f prvtRandomRightMovement(sf::Vector2f currentDirection);
	sf::Vector2f prvtRandomLeftMovement(sf::Vector2f currentDirection);
	sf::Vector2f prvtCurrentDirection;
	sf::Vector2f prvtPosition;

	// Sprite
	AnimatedSprite MainSprite;
	float animationFPS = 15.0f;
	int animationStart = 0;
	int animationStop = 7;
	float spriteScale = 2.0f;
	float leftSideStart = -8.0f;
	float rightSideStart;

	// Collision
	CollisionTools::TextureBitmap* bitmap;
};

#endif _Spider