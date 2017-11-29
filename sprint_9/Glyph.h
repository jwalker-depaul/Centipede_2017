#ifndef _Glyph
#define _Glyph

#include "SFML\Graphics.hpp"

class SpriteSheet; // forward declaration

class Glyph
{
private:
	SpriteSheet* sprsheet;
	int cellIndex;
	sf::Vector2f position;

public:
	Glyph();
	Glyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void Draw();
};


#endif _Glyph