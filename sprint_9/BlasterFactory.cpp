#include "BlasterFactory.h"

BlasterFactory* BlasterFactory::ptrInstance = nullptr;

Blaster* BlasterFactory::prvtCreateBlaster(BlasterInterface* strategy)
{
	Blaster* blaster;

	if (recycledItems.empty())
	{
		blaster = new Blaster();
	}

	else
	{
		blaster = recycledItems.top();
		recycledItems.pop();
	}

	return blaster->Initialize(strategy);
}

void BlasterFactory::privRecycleBlaster(GameObject* blaster)
{
	recycledItems.push((Blaster*)blaster);
}

void BlasterFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

BlasterFactory::~BlasterFactory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}