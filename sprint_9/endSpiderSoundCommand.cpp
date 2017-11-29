#include "endSpiderSoundCommand.h"
#include "SoundManager.h"

void endSpiderSoundCommand::execute()
{
	SoundManager::cmdEndSpiderSound();
}