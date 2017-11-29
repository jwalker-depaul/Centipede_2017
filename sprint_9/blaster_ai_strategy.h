#ifndef _blasterAI
#define _blasterAI

#include "blaster_interface.h"

class BlasterAI : public BlasterInterface
{
public:
	BlasterAI();

	sf::Vector2f movementDirection(sf::Vector2f blasterPosition) override;

private:
	void fireBullet(sf::Vector2f blasterPosition);

	sf::Vector2f movement;
	sf::Vector2f newDirection;

	// Random direction
	int frameCounter = 0;
	int maxFrames = 50;
	int randomNumber;
	int numberRange = 16; // This is used to detect what set of numbers is assigned a direction

	/*
	UP = 0 -> 3
	DOWN = 4 -> 7
	LEFT = 8 -> 11
	RIGHT = 12 -> 15
	*/

	sf::Vector2f getNewDirection();
	sf::Vector2f getDiagonalDirection(sf::Vector2f givenDirection);
};

#endif _blasterAI