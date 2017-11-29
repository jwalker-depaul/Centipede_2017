#include "endCentipedeSoundCommand.h"
#include "SoundManager.h"

void endCentipedeSoundCommand::execute()
{
	SoundManager::cmdEndCentipedeSound();
}