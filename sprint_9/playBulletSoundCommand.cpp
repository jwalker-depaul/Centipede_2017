#include "playBulletSoundCommand.h"
#include "SoundManager.h"

void playBulletSoundCommand::execute()
{
	SoundManager::cmdPlayBulletSound();
}