#ifndef _AttractorScene
#define _AttractorScene

#include "Game Components\TEAL\CommonElements.h"
#include "Game Components\KeyEventTest.h"

// Player
#include "Blaster.h"

// Mushroom
#include "Mushroom.h"
#include "MushroomFactory.h"
#include "MushroomGrid.h"

// Managers
#include "WaveManager.h"
#include "SceneController.h"

class AttractorScene : public Scene
{
public:
	virtual void Initialize();

	virtual void Terminate();
};

#endif _AttractorScene