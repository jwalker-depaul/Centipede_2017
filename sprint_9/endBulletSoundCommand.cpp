#include "endBulletSoundCommand.h"
#include "SoundManager.h"

void endBulletSoundCommand::execute()
{
	SoundManager::cmdEndBulletSound();
}