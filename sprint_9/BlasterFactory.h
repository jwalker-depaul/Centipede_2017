#ifndef _BlasterFactory
#define _BlasterFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Blaster.h"

class BlasterInterface;

class BlasterFactory
{
public:
	static Blaster* createBlaster(BlasterInterface* strategy) { return Instance().prvtCreateBlaster(strategy); }
	static void RecycleBlaster(GameObject* blaster) { Instance().privRecycleBlaster(blaster); }

	static void Terminate();

private:
	static BlasterFactory *ptrInstance;

	BlasterFactory() = default;
	BlasterFactory(const BlasterFactory&) = delete; // Prevents copy-construction
	BlasterFactory* operator = (const BlasterFactory&) = delete; // Prevent assignment
	~BlasterFactory(); // Only this class can delete

	static BlasterFactory & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new BlasterFactory;
		}
		return *ptrInstance;
	}

	std::stack<Blaster*> recycledItems;

	Blaster* prvtCreateBlaster(BlasterInterface* strategy);
	void privRecycleBlaster(GameObject* blaster);
};

#endif _BlasterFactory