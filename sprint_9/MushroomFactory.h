#ifndef _MushroomFactory
#define _MushroomFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Mushroom.h"
//#include "MushroomGrid.h"

class MushroomGrid;

class MushroomFactory
{
public:

	static Mushroom* CreateMushroom(sf::Vector2f position, MushroomGrid* mushroomGrid) { return Instance().privCreateMushroom(position, mushroomGrid); };
	static void RecycleMushroom(GameObject* mushroom) { Instance().privRecycleMushroom(mushroom); };

	static void Terminate();

private:
	static MushroomFactory* ptrInstance; // Using Singleton setup

	MushroomFactory() = default;
	MushroomFactory(const MushroomFactory&) = delete; // Prevent copy-construction
	MushroomFactory& operator = (const MushroomFactory&) = delete; // Prevent assignment
	~MushroomFactory();

	static MushroomFactory& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new MushroomFactory;
		}
		return *ptrInstance;
	}

	std::stack<Mushroom*> recycledItems; // Reset to non-static member

	Mushroom* privCreateMushroom(sf::Vector2f position, MushroomGrid* mushroomGrid);
	void privRecycleMushroom(GameObject* mushroom);
};

#endif _MushroomFactory
