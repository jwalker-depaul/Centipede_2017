#ifndef _playFleaSoundCommand
#define _playFleaSoundCommand

#include "SoundCommand.h"

class playFleaSoundCommand : public SoundCommand
{
public:
	virtual void execute() override;
};

#endif _playFleaSoundCommand