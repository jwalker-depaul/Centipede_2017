#include "SpiderFactory.h"

SpiderFactory* SpiderFactory::ptrInstance = nullptr;

Spider* SpiderFactory::privCreateSpider()
{
	Spider* spider;

	if (recycledItems.empty())
	{
		spider = new Spider();
		spider->SetExternalManagement(RecycleSpider);
	}

	else
	{
		spider = recycledItems.top();
		recycledItems.pop();
		spider->RegisterToCurrentScene();
	}

	// Counter
	spiderOnScreenCount++;

	return spider->Initialize();
}

void SpiderFactory::privRecycleSpider(GameObject* spider)
{
	recycledItems.push((Spider*)spider);

	// Counter
	spiderOnScreenCount--;
}

void SpiderFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

SpiderFactory::~SpiderFactory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}