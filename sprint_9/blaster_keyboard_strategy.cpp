#include "blaster_keyboard_strategy.h"

// Constructor
BlasterKeyboard::BlasterKeyboard()
{
	RegisterInput(InputFlags::KeyPressed);
}

/*
	This reads from the keyboard input
	and chooses the correct direction to 
	move the blaster
*/
sf::Vector2f BlasterKeyboard::movementDirection(sf::Vector2f blasterPosition)
{
	movement = NO_MOVEMENT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement += LEFT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement += RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement += UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement += DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) fireBullet(blasterPosition);
	return movement;
}

void BlasterKeyboard::fireBullet(sf::Vector2f position)
{
	BulletFactory::CreateBullet(position);
}

BlasterKeyboard::~BlasterKeyboard()
{
	DeregisterInput();
}