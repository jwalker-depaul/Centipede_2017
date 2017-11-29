#include "CritterDeathFactory.h"

CritterDeathFactory* CritterDeathFactory::ptrInstance = nullptr;

void CritterDeathFactory::privCreateCritterExplosion(sf::Vector2f position)
{
	CritterDeath* critterDeath;

	if (recycledItems.empty())
	{
		critterDeath = new CritterDeath();
	}

	else
	{
		critterDeath = recycledItems.top();
		recycledItems.pop();
	}

	critterDeath->Initialize(position);
}

void CritterDeathFactory::privRecycleCritterExplosion(GameObject *critterDeath)
{
	recycledItems.push((CritterDeath*)critterDeath);
}

CritterDeathFactory::~CritterDeathFactory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

void CritterDeathFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}