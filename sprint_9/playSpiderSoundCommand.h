#ifndef _playSpiderSoundCommand
#define _playSpiderSoundCommand

#include "SoundCommand.h"

class playSpiderSoundCommand : public SoundCommand
{
public:
	virtual void execute() override;
};

#endif _playSpiderSoundCommand