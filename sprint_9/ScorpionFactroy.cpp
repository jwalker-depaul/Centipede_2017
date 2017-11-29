// ScorpionFactory
// Joseph Walker

#include "ScorpionFactory.h"

ScorpionFactory *ScorpionFactory::ptrInstance = nullptr;

Scorpion* ScorpionFactory::privCreateScorpion()
{
	Scorpion *scorpion;

	if (recycledItems.empty())
	{
		scorpion = new Scorpion();
		scorpion->SetExternalManagement(RecycleScorpion);
	}

	else
	{
		scorpion = recycledItems.top();
		recycledItems.pop();

		scorpion->RegisterToCurrentScene();
	}

	// Counter
	scorpionOnScreenCount++;

	return scorpion->Initialize();
}

void ScorpionFactory::privRecycleScorpion(GameObject *scorpion)
{
	recycledItems.push((Scorpion*)scorpion);
	
	// Counter
	scorpionOnScreenCount--;
}

void ScorpionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

ScorpionFactory::~ScorpionFactory()
{
	ConsoleMsg::WriteLine("Deleteing recycled items (" + Tools::ToString(recycledItems.size()) + ")");
	// Forces deletion of all recycled GameObjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	scorpionOnScreenCount = 0;
}