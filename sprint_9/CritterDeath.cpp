// CritterDeath
// Joseph Walker

#include "CritterDeath.h"

CritterDeath::CritterDeath()
{
	// Sprite
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CritterDeath"), 8, 2);
	MainSprite.SetAnimation(0, 15);
	MainSprite.scale(1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
}

void CritterDeath::Initialize(sf::Vector2f position)
{
	MainSprite.SetAnimation(0, 15);
	MainSprite.setPosition(position);
}

void CritterDeath::Update()
{
	if (MainSprite.IsLastAnimationFrame())
	{
		MarkForDestroy();
	}
	MainSprite.Update();
}

void CritterDeath::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}