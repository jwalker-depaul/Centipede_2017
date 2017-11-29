#ifndef _ScorpionSpawner
#define _ScorpionSpawner

#include "Game Components\TEAL\CommonElements.h"
#include "ScorpionFactory.h"
#include "WaveManager.h"

class ScorpionSpawner : public GameObject
{
public:
	static void Initialize();
	static Scorpion* spawnScorpion() { return Instance().prvtSpawnScorpion(); };
	virtual void Update();
	virtual void Alarm0();

private:
	// Setup instance
	static ScorpionSpawner* ptrInstance;

	static ScorpionSpawner& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ScorpionSpawner;
		}
		return *ptrInstance;
	}
	
	~ScorpionSpawner();

	Scorpion* prvtSpawnScorpion();

	int scorpionOnScreenCount;
	int scorpionIntervalMinimum; // Minimum spawn inbetween previous
	int scorpionIntervalMaximum; // Maximum spawn inbetween previous
	int scorpionOnScreenMaximum; // Maximum allowed on screen at a time

	int randomNumber;
	bool alarmSet;

};


#endif _ScorpionSpawner