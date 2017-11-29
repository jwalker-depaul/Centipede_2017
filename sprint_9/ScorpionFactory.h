// ScorpionFactory
// Joseph Walker

#ifndef _ScorpionFactory
#define _ScorpionFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Scorpion.h"

class ScorpionFactory
{
public:

	// Services/API
	static Scorpion* CreateScorpion() { return Instance().privCreateScorpion(); };
	static void RecycleScorpion(GameObject* scorpion) { Instance().privRecycleScorpion(scorpion); };

	static int getScorpionOnScreenCount() { return Instance().scorpionOnScreenCount; };

	static void Terminate();

private:
	// Singelton setup

	static ScorpionFactory *ptrInstance; // Game set up as a singleton

	ScorpionFactory() = default;
	ScorpionFactory(const ScorpionFactory&) = delete; // Prevent copy-construction
	ScorpionFactory& operator = (const ScorpionFactory&) = delete; // Prevent assignment
	~ScorpionFactory(); // Only this class can delete

	static ScorpionFactory & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ScorpionFactory;
		}
		return *ptrInstance;
	}

	std::stack<Scorpion*> recycledItems; // Back to be a non-static member

										 // Methods
	Scorpion* privCreateScorpion();
	void privRecycleScorpion(GameObject* scorpion);

	int scorpionOnScreenCount = 0;

};

#endif _ScorpionFactory