#include "SceneController.h"
#include "PlayerOneScene.h"

SceneController* SceneController::ptrInstance = nullptr;

void SceneController::Initialize()
{
	Instance().RegisterInput(InputFlags::KeyPressed);
}

SceneController::~SceneController()
{
	DeregisterInput();
}

void SceneController::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::Num1)
		SceneManager::ChangeScene(new PlayerOneScene);
}