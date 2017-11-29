#ifndef _playScorpionSoundCommand
#define _playScorpionSoundCommand

#include "SoundCommand.h"

class playScorpionSoundCommand : public SoundCommand
{
public:
	virtual void execute() override;
};

#endif _playScorpionSoundCommand