#include "blaster_ai_strategy.h"

BlasterAI::BlasterAI()
{
	movement = LEFT;
}


sf::Vector2f BlasterAI::movementDirection(sf::Vector2f blasterPosition)
{
	sf::Vector2f position = blasterPosition;

	if (frameCounter == maxFrames)
	{
		movement = getNewDirection();
		frameCounter = 0; // reset
	}

	else
	{
		frameCounter++;
	}

	fireBullet(position);

	return movement;
}

/**************************************
***       AI Movement Methods       ***
**************************************/

sf::Vector2f BlasterAI::getNewDirection()
{
	randomNumber = rand() % numberRange; // 0 - 15
	if (randomNumber <= 3)
	{
		newDirection = UP;

		// Possible diagonal direction
		newDirection += getDiagonalDirection(newDirection);
	}
	else if (randomNumber <= 7)
	{
		newDirection = DOWN;

		// Possible diagonal direction
		newDirection += getDiagonalDirection(newDirection);
	}
	else if (randomNumber <= 11)
	{
		newDirection = LEFT;

		// Possible diagonal direction
		newDirection += getDiagonalDirection(newDirection);
	}
	else if (randomNumber <= 15)
	{
		newDirection = RIGHT;

		// Possible diagonal direction
		newDirection += getDiagonalDirection(newDirection);
	}
	return newDirection;
}

sf::Vector2f BlasterAI::getDiagonalDirection(sf::Vector2f givenDirection)
{
	randomNumber = rand() % 2; // binary
	if (randomNumber == 0) return NO_MOVEMENT;

	else if (givenDirection == UP || givenDirection == DOWN)
	{
		if (randomNumber == 0) return LEFT;
		else return RIGHT;
	}

	else if (givenDirection == LEFT || givenDirection == RIGHT)
	{
		if (randomNumber == 0) return UP;
		else return DOWN;
	}
	return DOWN;
}


void BlasterAI::fireBullet(sf::Vector2f position)
{
	BulletFactory::CreateBullet(position);
}