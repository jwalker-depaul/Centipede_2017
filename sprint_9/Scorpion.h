#ifndef _Scorpion
#define _Scorpion

#include "Game Components\TEAL\CommonElements.h"
#include "CritterDeathFactory.h"
#include "MushroomGrid.h"

// Manager includes
#include "ScoreManager.h"
#include "SoundManager.h"

//Forward Declerations
class Bullet;
class Mushroom;

class Scorpion : public GameObject
{
public:
	Scorpion();

	Scorpion* Initialize();

	//Collision
	virtual void Collision(GameObject * go) {};
	void Collision(Bullet * other);

private:
	//Virtual Methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Created Methods
	void Explode();
	sf::Vector2f prvtSetRandomSpawn();

	//Position
	int prvtRows = 31;
	int prvtSpriteSize = 16;
	int privRandomDirection; // 0 for left to right, 1 for right to left
	sf::Vector2f prvtPosition; //For use inside class
	float windowSizeX;
	float prvtRandomRow;
	float prvtSpeed = 200;

	//Sprite
	AnimatedSprite MainSprite;
	float animationFPS = 15.0f;
	sf::Vector2f prvtSpriteScale; // Not set; needs to be able to flip
	int animationStart = 0;
	int animationStop = 3;
	float offset = 8.0f;

	//Collision
	CollisionTools::TextureBitmap* bitmap;
};

#endif _Scorpion