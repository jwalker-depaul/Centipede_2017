#ifndef _endBulletSoundCommand
#define _endBulletSoundCommand

#include "SoundCommand.h"

class endBulletSoundCommand : public SoundCommand
{
public:
	virtual void execute() override;
};

#endif _endBulletSoundCommand