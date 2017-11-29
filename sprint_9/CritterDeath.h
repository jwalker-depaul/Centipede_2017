#ifndef _CritterDeath
#define _CritterDeath

#include "Game Components\TEAL\CommonElements.h"

class CritterDeath : public GameObject
{
public:
	CritterDeath();

	void Initialize(sf::Vector2f position);

private:

	// Virtual Methods
	virtual void Update();
	virtual void Draw();

	AnimatedSprite MainSprite;

	sf::Vector2f prvtPosition;

};

#endif _CritterDeath