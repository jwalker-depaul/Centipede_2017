#include "BlasterManager.h"
#include "BlasterFactory.h"
#include "WaveManager.h"
#include "Hud.h"

BlasterManager* BlasterManager::ptrInstance = nullptr;

void BlasterManager::Initialize()
{
	Instance().playerLives = WaveManager::getPlayerLives();
}

void BlasterManager::Terminate()
{
	BlasterFactory::Terminate();
	ptrInstance = nullptr;
}

Blaster* BlasterManager::prvtCreatePlayerOne()
{
	BlasterKeyboard* keyboardStrategy = new BlasterKeyboard();
	inAttractorScene = false;
	return BlasterFactory::createBlaster(keyboardStrategy);
}

Blaster* BlasterManager::prvtCreatePlayerTwo()
{
	BlasterKeyboard* keyboardStrategy = new BlasterKeyboard();
	inAttractorScene = false;
	return BlasterFactory::createBlaster(keyboardStrategy);
}

Blaster* BlasterManager::prvtCreateAttractorPlayer()
{
	// SWITCH TO AI STRATEGY
	BlasterAI* aiStrategy = new BlasterAI();
	inAttractorScene = true;
	return BlasterFactory::createBlaster(aiStrategy);
}

void BlasterManager::prvtPlayerDied()
{
	if (inAttractorScene)
	{
		SetAlarm(1, 3);
	}
	else
	{
		SetAlarm(0, 3);
	}
	playerLives--;
	HUD::decrementPlayerLives(playerLives);
}

void BlasterManager::Alarm0()
{
	prvtCreatePlayerOne();
}

void BlasterManager::Alarm1()
{
	prvtCreateAttractorPlayer();
}