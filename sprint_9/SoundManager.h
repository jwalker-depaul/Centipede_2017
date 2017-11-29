#ifndef _SoundManager
#define _SoundManager

#include "Game Components\TEAL\CommonElements.h"
#include "soundInterface.h"
#include "activateSound.h"
#include "deactivateSound.h"

class SoundManager : public GameObject
{
public:

	static void Initialize();

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

	// Play sounds
	static void playScorpionSound()		{ Instance().strategy->playScorpionSound(); };
	static void playFleaSound()			{ Instance().strategy->playFleaSound(); };
	static void playSpiderSound()		{ Instance().strategy->playSpiderSound(); };
	static void playCentipedeSound()	{ Instance().strategy->playCentipedeSound(); };
	static void playBulletSound()		{ Instance().strategy->playBulletSound(); };

	// End sounds
	static void endScorpionSound()	{ Instance().strategy->endScorpionSound(); };
	static void endFleaSound()		{ Instance().strategy->endFleaSound(); };
	static void endSpiderSound()	{ Instance().strategy->endSpiderSound(); };
	static void endCentipedeSound() { Instance().strategy->endCentipedeSound(); };
	static void endBulletSound()	{ Instance().strategy->endBulletSound(); };

	// Commands
	static void cmdPlayScorpionSound();
	static void cmdPlayFleaSound();
	static void cmdPlaySpiderSound();
	static void cmdPlayCentipedeSound();
	static void cmdPlayBulletSound();
	static void cmdEndScorpionSound();
	static void cmdEndFleaSound();
	static void cmdEndSpiderSound();
	static void cmdEndCentipedeSound();
	static void cmdEndBulletSound();

private:
	static SoundManager * ptrInstance;
	SoundManager() = default;									// Private constructor 
	SoundManager(const SoundManager&) = delete;				// Prevent copy-construction
	SoundManager& operator=(const SoundManager&) = delete;	// Prevent assignment
	~SoundManager();

	static SoundManager& Instance()					// Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new SoundManager;
		return *ptrInstance;
	};

	// Strategy
	void prvtChooseStrategy(soundInterface* strategy);
	soundInterface* strategy;
	ActivateSound* activateStrategy;
	DeactivateSound* deactivateStrategy;

	// Sounds
	sf::Sound ScorpionSound;
	sf::Sound FleaSound;
	sf::Sound SpiderSound;
	sf::Sound CentipedeSound;
	sf::Sound BulletSound;

	// Booleans
	bool isScorpionSoundPlaying		= false;
	bool isFleaSoundPlaying			= false;
	bool isSpiderSoundPlaying		= false;
	bool isCentipedeSoundPlaying	= false;
	bool isBulletSoundPlaying		= false;
};

#endif _SoundManager