#ifndef _playCentipedeSoundCommand
#define _playCentipedeSoundCommand

#include "SoundCommand.h"

class playCentipedeSoundCommand : public SoundCommand
{
public:
	virtual void execute() override;
};

#endif _playCentipedeSoundCommand