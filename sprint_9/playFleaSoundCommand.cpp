#include "playFleaSoundCommand.h"
#include "SoundManager.h"

void playFleaSoundCommand::execute()
{
	SoundManager::cmdPlayFleaSound();
}