#include "SpiderSpawner.h"

SpiderSpawner* SpiderSpawner::ptrInstance = nullptr;

void SpiderSpawner::Initialize()
{
	Instance().spiderIntervalMinimum = WaveManager::getSpiderIntervalMinimum();
	Instance().spiderIntervalMaximum = WaveManager::getSpiderIntervalMaximum();
	Instance().spiderOnScreenMaximum = WaveManager::getSpiderOnScreenMaximum();
	Instance().alarmSet = false;
}

Spider* SpiderSpawner::prvtSpawnSpider()
{
	return SpiderFactory::CreateSpider();
}

void SpiderSpawner::Update()
{
	spiderOnScreenCount = SpiderFactory::getSpiderOnScreenCount();

	if (spiderOnScreenCount < spiderOnScreenMaximum && alarmSet == false)
	{
		// Select random number in the range of min to max
		randomNumber = spiderIntervalMinimum + (std::rand() % (spiderIntervalMaximum - spiderIntervalMinimum + 1));
		SetAlarm(0, (float)randomNumber);
		alarmSet = true;
	}
}

void SpiderSpawner::Alarm0()
{
	spawnSpider();
	alarmSet = false;
}

SpiderSpawner::~SpiderSpawner()
{
	ptrInstance = nullptr;
}