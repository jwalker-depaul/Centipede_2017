#ifndef _playBulletSoundCommand
#define _playBulletSoundCommand

#include "SoundCommand.h"

class playBulletSoundCommand : public SoundCommand
{
public:
	virtual void execute() override;
};

#endif _playBulletSoundCommand