#ifndef _DeactivateSound
#define _DeactivateSound

#include "soundInterface.h"

class DeactivateSound : public soundInterface
{
public:
	DeactivateSound() {};

	// Define desired play strategy
	void playScorpionSound() {};
	void playFleaSound() {};
	void playSpiderSound() {};
	void playCentipedeSound() {};
	void playBulletSound() {};

	// End sounds
	void endScorpionSound() {};
	void endFleaSound() {};
	void endSpiderSound() {};
	void endCentipedeSound() {};
	void endBulletSound() {};
};

#endif _DeactivateSound