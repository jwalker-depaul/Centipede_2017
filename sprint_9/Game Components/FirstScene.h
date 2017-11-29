// FirstScene
// Andre Berthiaume, March 2013

#ifndef _FirstScene
#define _FirstScene

#include "TEAL\CommonElements.h"
#include "KeyEventTest.h"

// Player
#include "../Blaster.h"

// Mushroom
#include "../MushroomGrid.h"
#include "../Mushroom.h"
#include "../MushroomFactory.h"

// Manager
#include "../WaveManager.h"

class FirstScene : public Scene
{
public:
	virtual void Initialize();

	virtual void Terminate();
};

#endif _FirstScene