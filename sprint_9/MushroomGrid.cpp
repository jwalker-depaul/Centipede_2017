#include "MushroomGrid.h"
#include <stdlib.h>
#include "MushroomFactory.h"

MushroomGrid* MushroomGrid::ptrInstance = nullptr;

/**************************
***   Created Methods   ***
**************************/

void MushroomGrid::privInitializeNullGrid()
{
	
	for (int row = 0; row < prvtMushroomRows; row++)
	{
		for (int collumn = 0; collumn < prvtMushroomCollumns; collumn++)
		{
			prvtMushroomArray[collumn][row] = nullptr;
		}
	}	
}

void MushroomGrid::privCreateField()
{
	// Set random mushrooms
	for (int row = 1; row < prvtMushroomRows - 1; row++)
	{
		for (int collumn = 0; collumn < prvtMushroomsPerRow; collumn++)
		{
			// Spread random spawn
			randomCollumn = rand() % prvtMushroomCollumns;
			gridLocation = { randomCollumn, row };

			// Convert random location to screen
			screenLocation = convertGridToScreen(gridLocation);

			// Create mushroom at location
			prvtCreateMushroom(gridLocation);
			//prvtCreateMushroom({ collumn, row }); Test to see the grid is created properly
		}
	}
}

/********************************************
***         Mushroom Manipulation         ***
********************************************/

Mushroom* MushroomGrid::prvtGetMushroom(sf::Vector2i position)
{
	if (isMushroom(position))
	{
		return prvtMushroomArray[position.y][position.x];
	}
	else return nullptr;
}

void MushroomGrid::prvtDeleteMushroom(sf::Vector2f position)

{
	sf::Vector2i ArrayPosition = convertScreenToGrid(position);
	prvtMushroomArray[ArrayPosition.x][ArrayPosition.y] = nullptr;
}

bool MushroomGrid::prvtCreateMushroom(sf::Vector2i position)
{
	// Check if mushroom already exists at position
	if (prvtMushroomArray[position.x][position.y] != nullptr)
	{
		// Mushroom already exist at location
		return false;
	}

	// Create mushroom at location
	prvtMushroomArray[position.x][position.y] = MushroomFactory::CreateMushroom(convertGridToScreen(position), this);
	return true;
}

bool MushroomGrid::prvtSetPoisonMushroom(sf::Vector2i position)
{
	// If there is a mushroom present
	if (isMushroom(position))
	{
		prvtGetMushroom(position)->setPoisonMushroom();
		return true;
	}

	// No mushroom present
	else
	{
		return false;
	}
}

/*****************************************
***         Conversion Methods         ***
*****************************************/

sf::Vector2f MushroomGrid::prvtConvertGridToScreen(sf::Vector2i position)
{
	return sf::Vector2f{ (float)(position.x * spriteSize) + (spriteSize / 2), (float)(position.y * spriteSize) + (spriteSize / 2) };
}

sf::Vector2i MushroomGrid::prvtConvertScreenToGrid(sf::Vector2f position)
{
	return sf::Vector2i(int(position.x / spriteSize), int(position.y / spriteSize));
}

/*********************************
***       Mushroom Check       ***
*********************************/

bool MushroomGrid::prvtIsMushroom(sf::Vector2i position)
{
	if (position.x < 0 ||
		position.x > BOTTOM_ROW ||
		position.y < 0 ||
		position.y > EAST_WALL) return false;
	
	else if (prvtMushroomArray[position.y][position.x] != nullptr) return true;
	else return false;
}

bool MushroomGrid::prvtIsPoisonMushroom(sf::Vector2i position)
{
	if (prvtIsMushroom(position))
	{
		if (prvtGetMushroom(position)->isPoisionMushroom())
			return true;
		return false;
	}
	return false;
}

MushroomGrid::~MushroomGrid()
{
	MushroomFactory::Terminate();
	DeregisterInput();
	ptrInstance = nullptr;
}