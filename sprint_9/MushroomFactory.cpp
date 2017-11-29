#include "MushroomFactory.h"

MushroomFactory *MushroomFactory::ptrInstance = nullptr;

Mushroom* MushroomFactory::privCreateMushroom(sf::Vector2f position, MushroomGrid* mushroomGrid)
{
	Mushroom *mushroom;

	// Recycle
	if (recycledItems.empty())
	{
		mushroom = new Mushroom();
		mushroom->SetExternalManagement(RecycleMushroom);
	}

	else
	{
		mushroom = recycledItems.top();
		recycledItems.pop();

		mushroom->RegisterToCurrentScene();
	}

	return mushroom->Initialize(position, mushroomGrid);
}

void MushroomFactory::privRecycleMushroom(GameObject *mushroom)
{
	recycledItems.push((Mushroom*)mushroom);
	//ConsoleMsg::WriteLine("Recycled Mushroom Stack Size: " + Tools::ToString(recycledItems.size()));
}

void MushroomFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

MushroomFactory::~MushroomFactory()
{
	// Forces deletion of all recycled GameObjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}