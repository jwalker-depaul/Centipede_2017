// FleaFactory
// Joseph Walker

#ifndef _FleaFactory
#define _FleaFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Flea.h"

class FleaFactory
{
public:

	// Services/API
	static Flea* CreateFlea()
	{
		return Instance().privCreateFlea();
	};
	static void RecycleFlea(GameObject *flea) { Instance().privRecycleFlea(flea); };

	static int getFleaOnScreenCount() { return Instance().fleaOnScreenCount; };

	static void Terminate();

private:
	// Singelton setup

	static FleaFactory *ptrInstance;

	FleaFactory() = default;
	FleaFactory(const FleaFactory&) = delete; // Prevents copy-construction
	FleaFactory* operator = (const FleaFactory&) = delete; // Prevent assignment
	~FleaFactory(); // Only this class can delete

	static FleaFactory & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new FleaFactory;
		}
		return *ptrInstance;
	}

	std::stack<Flea*> recycledItems; // Back to be a non-static member

	Flea* privCreateFlea();
	void privRecycleFlea(GameObject* flea);

	int fleaOnScreenCount = 0;


};

#endif _FleaFactory