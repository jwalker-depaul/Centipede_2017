#ifndef _BlasterInterface
#define _BlasterInterface

#include "Game Components\TEAL\CommonElements.h"
#include "BulletFactory.h"

/*
	This is the strategy inteface
	holds the rules of the keyboard movement of the blaster
	as well as the ai control
*/

class BlasterInterface : public GameObject
{
public:
	virtual sf::Vector2f movementDirection(sf::Vector2f blasterPosition) = 0;

protected:
	sf::Vector2f NO_MOVEMENT = { 0, 0 };
	sf::Vector2f UP = { 0, -2 };
	sf::Vector2f DOWN = { 0, 2 };
	sf::Vector2f LEFT = { -2, 0 };
	sf::Vector2f RIGHT = { 2, 0 };
};

#endif _BlasterInterface