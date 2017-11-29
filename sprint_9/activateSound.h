#ifndef _ActivateSound
#define _ActivateSound

// Strategy pattern
#include "soundInterface.h"

// Play Sounds
#include "playScorpionSoundCommand.h"
#include "playFleaSoundCommand.h"
#include "playSpiderSoundCommand.h"
#include "playCentipedeSoundCommand.h"
#include "playBulletSoundCommand.h"

// End Sounds
#include "endScorpionSoundCommand.h"
#include "endFleaSoundCommand.h"
#include "endSpiderSoundCommand.h"
#include "endCentipedeSoundCommand.h"
#include "endBulletSoundCommand.h"

class ActivateSound : public soundInterface
{
public:
	ActivateSound() = default;

	// Play soundsvc 
	void playScorpionSound()	{ commandPlayScorpionSound.execute(); };
	void playFleaSound()		{ commandPlayFleaSound.execute(); };
	void playSpiderSound()		{ commandPlaySpiderSound.execute(); };
	void playCentipedeSound()	{ commandPlayCentipedeSound.execute(); };
	void playBulletSound()		{ commandPlayBulletSound.execute(); };

	// End sounds
	void endScorpionSound()		{ commandEndScorpionSound.execute(); };
	void endFleaSound()			{ commandEndFleaSound.execute(); };
	void endSpiderSound()		{ commandEndSpiderSound.execute(); };
	void endCentipedeSound()	{ commandEndCentipedeSound.execute(); };
	void endBulletSound()		{ commandEndBulletSound.execute(); };

private:

	// Play Commands
	playScorpionSoundCommand	commandPlayScorpionSound;
	playFleaSoundCommand		commandPlayFleaSound;
	playSpiderSoundCommand		commandPlaySpiderSound;
	playCentipedeSoundCommand	commandPlayCentipedeSound;
	playBulletSoundCommand		commandPlayBulletSound;

	// End Commands
	endScorpionSoundCommand		commandEndScorpionSound;
	endFleaSoundCommand			commandEndFleaSound;
	endSpiderSoundCommand		commandEndSpiderSound;
	endCentipedeSoundCommand	commandEndCentipedeSound;
	endBulletSoundCommand		commandEndBulletSound;

};

#endif _ActivateSound