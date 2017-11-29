#ifndef _SpiderSpawner
#define _SpiderSpawner

#include "Game Components\TEAL\CommonElements.h"
#include "SpiderFactory.h"
#include "WaveManager.h"

class SpiderSpawner : public GameObject
{
public:
	static void Initialize();
	static Spider* spawnSpider() { return Instance().prvtSpawnSpider(); };
	virtual void Update();
	virtual void Alarm0();

private:
	// Setup instance
	static SpiderSpawner* ptrInstance;

	static SpiderSpawner& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new SpiderSpawner;
		}
		return *ptrInstance;
	}

	~SpiderSpawner();

	Spider* prvtSpawnSpider();

	int spiderOnScreenCount;
	int spiderIntervalMinimum; // Minimum spawn inbetween previous
	int spiderIntervalMaximum; // Maximum spawn inbetween previous
	int spiderOnScreenMaximum; // Maximum allowed on screen at a time

	int randomNumber;
	bool alarmSet;

};

#endif _SpiderSpawner