#include "FleaSpawner.h"

FleaSpawner* FleaSpawner::ptrInstance = nullptr;

void FleaSpawner::Initialize()
{
	Instance().fleaIntervalMinimum = WaveManager::getFleaIntervalMinimum();
	Instance().fleaIntervalMaximum = WaveManager::getFleaIntervalMaximum();
	Instance().fleaOnScreenMaximum = WaveManager::getFleaOnScreenMaximum();
	Instance().alarmSet = false;
}

Flea* FleaSpawner::prvtSpawnFlea()
{
	return FleaFactory::CreateFlea();
}

void FleaSpawner::Update()
{
	fleaOnScreenCount = FleaFactory::getFleaOnScreenCount();

	if (fleaOnScreenCount < fleaOnScreenMaximum && alarmSet == false)
	{
		// Select random number in the range of min to max
		randomNumber = fleaIntervalMinimum + (std::rand() % (fleaIntervalMaximum - fleaIntervalMinimum + 1));
		SetAlarm(0, (float)randomNumber);
		alarmSet = true;
	}
}

void FleaSpawner::Alarm0()
{
	spawnFlea();
	alarmSet = false;
}

FleaSpawner::~FleaSpawner()
{
	ptrInstance = nullptr;
}