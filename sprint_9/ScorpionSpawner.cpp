#include "ScorpionSpawner.h"

ScorpionSpawner* ScorpionSpawner::ptrInstance = nullptr;

void ScorpionSpawner::Initialize()
{
	Instance().scorpionIntervalMinimum = WaveManager::getScorpionIntervalMinimum();
	Instance().scorpionIntervalMaximum = WaveManager::getScorpionIntervalMaximum();
	Instance().scorpionOnScreenMaximum = WaveManager::getScorpionOnScreenMaximum();
	Instance().alarmSet = false;
}

Scorpion* ScorpionSpawner::prvtSpawnScorpion()
{
	return ScorpionFactory::CreateScorpion();
}

void ScorpionSpawner::Update()
{
	scorpionOnScreenCount = ScorpionFactory::getScorpionOnScreenCount();

	if (scorpionOnScreenCount < scorpionOnScreenMaximum && alarmSet == false)
	{
		// Select random number in the range of min to max
		randomNumber = scorpionIntervalMinimum + (std::rand() % (scorpionIntervalMaximum - scorpionIntervalMinimum + 1));
		SetAlarm(0, (float)randomNumber);
		alarmSet = true;
	}
}

void ScorpionSpawner::Alarm0()
{
	spawnScorpion();
	alarmSet = false;
}

ScorpionSpawner::~ScorpionSpawner()
{
	ptrInstance = nullptr;
}