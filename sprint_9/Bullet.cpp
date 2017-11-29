#include "Bullet.h"

// Constructor
Bullet::Bullet()
{
	//Sprites
	prvtMainSprite = AnimatedSprite(ResourceManager::GetTexture("Bullet"), 1, 1, 1);
	prvtMainSprite.SetAnimation(0, 0);
	prvtMainSprite.setOrigin(prvtMainSprite.getTextureRect().width / 2.0f, prvtMainSprite.getTextureRect().height / 2.0f);

	//Collision
	prvtBitmap = &ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(prvtMainSprite, *prvtBitmap);
	RegisterCollision<Bullet>(*this);
}

/**************************************
***         Created Methods         ***
**************************************/

// The factory calls this to create the bullet
void Bullet::Initialize(sf::Vector2f position)
{
	Pos = position;
	RegisterCollision<Bullet>(*this);
	SoundManager::playBulletSound();
}

/**************************************
***         Virtual Methods         ***
**************************************/

void Bullet::Update()
{
	prvtMainSprite.Update();

	Pos.y -= Game::FrameTime() * SPEED;

	if (Pos.y < 0)
	{
		SoundManager::endBulletSound();
		MarkForDestroy();
	}


	prvtMainSprite.setPosition(Pos);
}

void Bullet::Draw()
{
	WindowManager::MainWindow.draw(prvtMainSprite);
}

void Bullet::Destroy()
{
	DeregisterCollision<Bullet>(*this);
}

/*********************
***   Collisions   ***
*********************/

void Bullet::Collision(Mushroom* other)
{
	SoundManager::endBulletSound();
	MarkForDestroy();
}

void Bullet::Collision(Flea* other)
{
	SoundManager::endBulletSound();
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	SoundManager::endBulletSound();
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	SoundManager::endBulletSound();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeHead* other)
{
	SoundManager::endBulletSound();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeSegment* other)
{
	SoundManager::endBulletSound();
	MarkForDestroy();
}