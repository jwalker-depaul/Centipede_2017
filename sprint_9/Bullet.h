#ifndef _Bullet
#define _Bullet

#include "Game Components\TEAL\CommonElements.h"
#include "SoundManager.h"

class Mushroom;
class Flea;
class Scorpion;
class Spider;
class CentipedeHead;
class CentipedeSegment;

class Bullet : public GameObject
{
public:
	// Constructor
	Bullet();

	// Created methods
	void Initialize(sf::Vector2f position);

	// Collision
	virtual void Collision(GameObject *other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Flea* other);
	virtual void Collision(Scorpion* other);
	virtual void Collision(Spider* other);
	virtual void Collision(CentipedeHead* other);
	virtual void Collision(CentipedeSegment* other);

private:

	//Virtual methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	//Position
	float SPEED = 800;
	sf::Vector2f Pos;
	AnimatedSprite prvtMainSprite;

	//Collisions
	CollisionTools::TextureBitmap* prvtBitmap;
};

#endif _Bullet