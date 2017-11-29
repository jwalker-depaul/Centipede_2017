#ifndef _SceneController
#define _SceneController

#include "Game Components\TEAL\CommonElements.h"

class PlayerOneScene;
class AttractorScene;

class SceneController : public GameObject
{
public:
	static void Initialize();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

private:
	static SceneController* ptrInstance;

	static SceneController& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new SceneController;
		}
		return *ptrInstance;
	}

	~SceneController();

	// Scenes
	PlayerOneScene* playerOneScene;
	AttractorScene* attractorScene;
};

#endif _SceneController