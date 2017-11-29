#ifndef _CritterDeathFactory
#define _CritterDeathFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "CritterDeath.h"

class CritterDeathFactory
{
public:

	static void CreateExplosion(sf::Vector2f position)
	{
		Instance().privCreateCritterExplosion(position);
	}

	static void RecycleExplosion(GameObject *critterDeath)
	{
		Instance().privRecycleCritterExplosion(critterDeath);
	}

	static void Terminate();

private:

	static CritterDeathFactory *ptrInstance;

	CritterDeathFactory() = default;
	CritterDeathFactory(const CritterDeath&) = delete;
	CritterDeathFactory* operator = (const CritterDeathFactory&) = delete;
	~CritterDeathFactory();

	static CritterDeathFactory& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new CritterDeathFactory;
		}
		return *ptrInstance;
	}

	std::stack<CritterDeath*> recycledItems;

	// Created Methods
	void privCreateCritterExplosion(sf::Vector2f position);
	void privRecycleCritterExplosion(GameObject* critterDeath);

};

#endif _CritterDeathFactory
