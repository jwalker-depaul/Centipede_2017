#include "AwesomeFont.h"
#include "Game Components\TEAL\ResourceManager.h"

AwesomeFont::AwesomeFont()
	: SpriteSheet(ResourceManager::GetTexture("Alphabet"), 16, 3)
{
}

// Computing the magic value of the cellIndex for each char
int AwesomeFont::CharToIndex(char& c)
{
	int cellIndex = 0;

	// This converts any lowercase key into an uppercase key
	if (c >= 'a' && c <= 'z')
		c -= 32;

	// Now selects which symbol to use
	if (c >= '0' && c <= '9')
		cellIndex = (int)c - (int) '0';
	else if (c >= 'A' && c <= 'Z')
		cellIndex = (int)c - (int) 'A' + 17;
	else
		switch (c)
		{
		case ' ':	// Space
			cellIndex = 16;
			break;
		case ':':	// Colon
			cellIndex = 10;
			break;
		case '/':	// Half
			cellIndex = 11;
			break;
		case '[':	// Copyright
			cellIndex = 12;
			break;
		case ']':	// Publisher
			cellIndex = 14;
			break;
		default:
			cellIndex = 16;
		}

	return cellIndex;
}