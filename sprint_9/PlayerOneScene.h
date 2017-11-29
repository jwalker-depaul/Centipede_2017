#ifndef _PlayerOneScene
#define _PlayerOneScene

#include "Game Components\TEAL\CommonElements.h"
#include "Game Components\KeyEventTest.h"

// Player
#include "Blaster.h"

// Mushroom
#include "MushroomGrid.h"
#include "Mushroom.h"
#include "MushroomFactory.h"

// Manager
#include "WaveManager.h"

class PlayerOneScene : public Scene
{
public:
	virtual void Initialize();

	virtual void Terminate();
};

#endif _PlayerOneScene