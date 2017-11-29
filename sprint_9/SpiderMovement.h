#ifndef _SpiderMovement
#define _SpiderMovement

#include "Game Components\TEAL\CommonElements.h"

class SpiderMovement : public GameObject
{
protected:

	float speed = 2;

	// Movement directions
	sf::Vector2f moveUp = { 0, -speed };
	sf::Vector2f moveUpLeft = { -speed, -speed };
	sf::Vector2f moveUpRight = { speed, -speed };

	sf::Vector2f moveDown = { 0, speed };
	sf::Vector2f moveDownLeft = { -speed, speed };
	sf::Vector2f moveDownRight = { speed, speed };
};

#endif _SpiderMovment