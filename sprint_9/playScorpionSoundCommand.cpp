#include "playScorpionSoundCommand.h"
#include "SoundManager.h"

void playScorpionSoundCommand::execute()
{
	SoundManager::cmdPlayScorpionSound();
}