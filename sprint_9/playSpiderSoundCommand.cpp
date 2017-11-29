#include "playSpiderSoundCommand.h"
#include "SoundManager.h"

void playSpiderSoundCommand::execute()
{
	SoundManager::cmdPlaySpiderSound();
}