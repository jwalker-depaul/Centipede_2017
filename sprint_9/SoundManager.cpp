#include "SoundManager.h"
#include "activateSound.h"
#include "deactivateSound.h"

SoundManager* SoundManager::ptrInstance;

void SoundManager::Initialize()
{
	Instance().activateStrategy = new ActivateSound();
	Instance().deactivateStrategy = new DeactivateSound();

	Instance().prvtChooseStrategy(Instance().activateStrategy);

	Instance().RegisterInput(InputFlags::KeyPressed);
}

SoundManager::~SoundManager()
{
	DeregisterInput();
	ptrInstance = nullptr;
}

void SoundManager::prvtChooseStrategy(soundInterface* strategy)
{
	Instance().strategy = strategy;
}

void SoundManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::M)
	{
		if (Instance().strategy == Instance().activateStrategy)
			prvtChooseStrategy(deactivateStrategy);
		else
			prvtChooseStrategy(activateStrategy);
	}
}

/*******************
***   Commands   ***
*******************/

void SoundManager::cmdPlayScorpionSound()
{
	if (!Instance().isScorpionSoundPlaying)
	{
		Instance().ScorpionSound.setBuffer(ResourceManager::GetSound("ScorpionSound"));
		Instance().ScorpionSound.setVolume(15);
		Instance().ScorpionSound.setLoop(true);
		Instance().ScorpionSound.play();

		Instance().isScorpionSoundPlaying = true;
	}

}

void SoundManager::cmdPlayFleaSound()
{
	if (!Instance().isFleaSoundPlaying)
	{
		Instance().FleaSound.setBuffer(ResourceManager::GetSound("FleaStep"));
		Instance().FleaSound.setVolume(15);
		Instance().FleaSound.play();

		Instance().isFleaSoundPlaying = true;
	}
}

void SoundManager::cmdPlaySpiderSound()
{
	if (!Instance().isSpiderSoundPlaying)
	{
		Instance().SpiderSound.setBuffer(ResourceManager::GetSound("SpiderStep"));
		Instance().SpiderSound.setVolume(15);
		Instance().SpiderSound.setLoop(true);
		Instance().SpiderSound.play();

		Instance().isSpiderSoundPlaying = true;
	}
}

void SoundManager::cmdPlayCentipedeSound()
{
	if (!Instance().isCentipedeSoundPlaying)
	{
		Instance().CentipedeSound.setBuffer(ResourceManager::GetSound("CentipedeStep"));
		Instance().CentipedeSound.setVolume(15);
		Instance().CentipedeSound.setLoop(true);
		Instance().CentipedeSound.play();

		Instance().isCentipedeSoundPlaying = true;
	}
}

void SoundManager::cmdPlayBulletSound()
{
	if (!Instance().isBulletSoundPlaying)
	{
		Instance().BulletSound.setBuffer(ResourceManager::GetSound("Fire_1"));
		Instance().BulletSound.setVolume(15);
		Instance().BulletSound.play();

		Instance().isBulletSoundPlaying = true;
	}
}

void SoundManager::cmdEndScorpionSound()
{
	Instance().ScorpionSound.stop();
	Instance().isScorpionSoundPlaying = false;
}

void SoundManager::cmdEndFleaSound()
{
	Instance().FleaSound.stop();
	Instance().isFleaSoundPlaying = false;
}

void SoundManager::cmdEndSpiderSound()
{
	Instance().SpiderSound.stop();
	Instance().isSpiderSoundPlaying = false;
}

void SoundManager::cmdEndCentipedeSound()
{
	Instance().CentipedeSound.stop();
	Instance().isCentipedeSoundPlaying = false;
}

void SoundManager::cmdEndBulletSound()
{
	Instance().BulletSound.stop();
	Instance().isBulletSoundPlaying = false;
}