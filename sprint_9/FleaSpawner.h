#ifndef _FleaSpawner
#define _FleaSpawner

#include "Game Components\TEAL\CommonElements.h"
#include "FleaFactory.h"
#include "WaveManager.h"

class FleaSpawner : public GameObject
{
public:
	static void Initialize();
	static Flea* spawnFlea() { return prvtSpawnFlea(); };
	virtual void Update();
	virtual void Alarm0();

private:
	// Setup instance
	static FleaSpawner* ptrInstance;

	static FleaSpawner& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new FleaSpawner;
		}
		return *ptrInstance;
	}

	~FleaSpawner();

	static Flea* prvtSpawnFlea();

	int fleaOnScreenCount;
	int fleaIntervalMinimum; // Minimum spawn inbetween previous
	int fleaIntervalMaximum; // Maximum spawn inbetween previous
	int fleaOnScreenMaximum; // Maximum allowed on screen at a time

	int randomNumber;
	bool alarmSet;
};

#endif _FleaSpawner