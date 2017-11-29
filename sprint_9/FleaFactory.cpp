// FleaFactroy
// Joseph Walker

#include "FleaFactory.h"

FleaFactory * FleaFactory::ptrInstance = nullptr;

Flea* FleaFactory::privCreateFlea()
{
	Flea *flea;

	if (recycledItems.empty())
	{
		flea = new Flea();
		flea->SetExternalManagement(RecycleFlea);
	}

	else
	{
		flea = recycledItems.top();
		recycledItems.pop();
		flea->RegisterToCurrentScene();
	}

	// Counter
	fleaOnScreenCount++;

	return flea->Initialize();
}

void FleaFactory::privRecycleFlea(GameObject *flea)
{
	recycledItems.push((Flea*)flea);
	
	// Counter
	fleaOnScreenCount--;
}

void FleaFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

FleaFactory::~FleaFactory()
{
	ConsoleMsg::WriteLine("Deleteing recycled items (" + Tools::ToString(recycledItems.size()) + ")");
	// Forces deletion of all recycled GameObjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	fleaOnScreenCount = 0;
}