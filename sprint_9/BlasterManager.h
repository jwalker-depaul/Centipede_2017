#ifndef _BlasterManager
#define _BlasterManager

#include "Game Components\TEAL\CommonElements.h"
#include "blaster_keyboard_strategy.h"
#include "blaster_ai_strategy.h"
#include "blaster_interface.h"

class Blaster;

class BlasterManager : public GameObject
{
public:
	static void Initialize();

	static Blaster* createPlayerOne()		{ return Instance().prvtCreatePlayerOne(); };
	static Blaster* createPlayerTwo()		{ return Instance().prvtCreatePlayerTwo(); };
	static Blaster* createAttractorPlayer()	{ return Instance().prvtCreateAttractorPlayer(); };
	static void playerDied()				{ Instance().prvtPlayerDied(); };

	virtual void Alarm0();
	virtual void Alarm1();

	static void Terminate();

private:
	static BlasterManager *ptrInstance;

	BlasterManager() = default;
	BlasterManager(const BlasterManager&) = delete; // Prevents copy-construction
	BlasterManager* operator = (const BlasterManager&) = delete; // Prevent assignment
	~BlasterManager() = default; // Only this class can delete

	static BlasterManager & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new BlasterManager;
		}
		return *ptrInstance;
	}

	// Player Methods
	Blaster* prvtCreatePlayerOne();
	Blaster* prvtCreatePlayerTwo();
	Blaster* prvtCreateAttractorPlayer();
	void prvtPlayerDied();
	bool inAttractorScene = false;

	// Player Variables
	int playerLives;
	Blaster* currentBlaster;

	// Strategy
	BlasterKeyboard* keyboardStrategy;
};

#endif _BlasterManager