#include "endFleaSoundCommand.h"
#include "SoundManager.h"

void endFleaSoundCommand::execute()
{
	SoundManager::cmdEndFleaSound();
}