#ifndef _blasterKeyboard
#define _blasterKeyboard

#include "blaster_interface.h"

/*
	This class extends the interface
	for the strategy pattern
	Use this to define the 
	keyboard input strategy
*/
class BlasterKeyboard : public BlasterInterface
{
public:
	// Constructor and Destructor
	BlasterKeyboard();
	~BlasterKeyboard();

	// Define desired movement strategy
	sf::Vector2f movementDirection(sf::Vector2f blasterPosition) override;

private:
	void fireBullet(sf::Vector2f blasterPosition);

	// Movement direction variable
	sf::Vector2f movement;
};

#endif _blasterKeyboard