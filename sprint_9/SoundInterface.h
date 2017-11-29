// Sound interface
// Joseph Walker

#ifndef _soundInterface
#define _soundInterface

#include "Game Components\TEAL\CommonElements.h"

class soundInterface
{
public:
	// Abstract methods
	virtual void playScorpionSound() = 0;
	virtual void playFleaSound() = 0;
	virtual void playSpiderSound() = 0;
	virtual void playCentipedeSound() = 0;
	virtual void playBulletSound() = 0;

	virtual void endScorpionSound() = 0;
	virtual void endFleaSound() = 0;
	virtual void endSpiderSound() = 0;
	virtual void endCentipedeSound() = 0;
	virtual void endBulletSound() = 0;
};

#endif _soundInterace