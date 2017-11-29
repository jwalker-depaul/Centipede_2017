#ifndef _MushroomGrid
#define _MushroomGrid

#include "Game Components\TEAL\CommonElements.h"

class Mushroom;

class MushroomGrid : public GameObject
{
public:
	// Field Creation
	static void initializeNullGrid()	{ Instance().privInitializeNullGrid(); };
	static void createField()			{ Instance().privCreateField(); };

	// Mushroom Methods
	static Mushroom* getMushroom(sf::Vector2i position) { return Instance().prvtGetMushroom(position); }
	static void deleteMushroom(sf::Vector2f position) { Instance().prvtDeleteMushroom(position); };
	static bool createMushroom(sf::Vector2i position) { return Instance().prvtCreateMushroom(position); };
	static bool setPoisonMushroom(sf::Vector2i position) { return Instance().prvtSetPoisonMushroom(position); }

	// Conversion Methods
	static sf::Vector2f convertGridToScreen(sf::Vector2i position) { return Instance().prvtConvertGridToScreen(position); };
	static sf::Vector2i convertScreenToGrid(sf::Vector2f position) { return Instance().prvtConvertScreenToGrid(position); };

	// Mushroom Check
	static bool isMushroom(sf::Vector2i position) { return Instance().prvtIsMushroom(position); };
	static bool isPoisonMushroom(sf::Vector2i position) { return Instance().prvtIsPoisonMushroom(position); }

	//Zones
	static const int BOTTOM_ROW		= 31;
	static const int TOP_PLAYER_ROW = 20;
	static const int WEST_WALL		= (8 / 16);
	static const int EAST_WALL		= (472 / 16); // 472 centipede width, 480 actual width
	static const int SOUTH_WALL		= 504; // 504 centipede height, 512 actual height

private:

	/********************
	***   Singleton   ***
	********************/

	static MushroomGrid* ptrInstance;

	MushroomGrid()									= default;
	MushroomGrid(const MushroomGrid&)				= delete; // Prevent copy construction
	MushroomGrid& operator = (const MushroomGrid&)	= delete; // Prevent assignment
	~MushroomGrid();

	static MushroomGrid& Instance()
	{
		if (!ptrInstance) ptrInstance = new MushroomGrid;

		return *ptrInstance;
	}

	/******************
	***   Methods   ***
	******************/
	
	// Field creation
	void MushroomGrid::privInitializeNullGrid();
	void MushroomGrid::privCreateField();

	// Mushroom Methods
	Mushroom* MushroomGrid::prvtGetMushroom(sf::Vector2i position);
	void MushroomGrid::prvtDeleteMushroom(sf::Vector2f position);
	bool MushroomGrid::prvtCreateMushroom(sf::Vector2i position);
	bool MushroomGrid::prvtSetPoisonMushroom(sf::Vector2i position);

	// Conversion methods
	sf::Vector2f prvtConvertGridToScreen(sf::Vector2i position);
	sf::Vector2i prvtConvertScreenToGrid(sf::Vector2f position);

	// Mushroom Check
	bool MushroomGrid::prvtIsMushroom(sf::Vector2i position);
	bool MushroomGrid::prvtIsPoisonMushroom(sf::Vector2i position);

	// Positioning
	sf::Vector2i gridLocation;
	sf::Vector2f screenLocation;

	// Row and Collumn setup
	static const int prvtMushroomRows		= 32; //32
	static const int prvtMushroomCollumns	= 30; //30
	static const int prvtMushroomsPerRow	= 2; //2
	Mushroom* prvtMushroomArray[prvtMushroomCollumns][prvtMushroomRows];

	int randomCollumn;
	int spriteSize = 16;

};

#endif _MushroomGrid