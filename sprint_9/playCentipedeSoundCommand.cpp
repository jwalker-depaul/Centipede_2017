#include "playCentipedeSoundCommand.h"
#include "SoundManager.h"

void playCentipedeSoundCommand::execute()
{
	SoundManager::cmdPlayCentipedeSound();
}