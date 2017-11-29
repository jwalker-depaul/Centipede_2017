#ifndef _CentipedeSpawner
#define _CentipedeSpawner

#include "Game Components\TEAL\CommonElements.h"
#include "CentipedeHeadFactory.h"
#include "WaveManager.h"

class CentipedeSpawner : public GameObject
{
public:
	static void Initialize();
	static CentipedeHead* spawnCentipede(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments) { return Instance().prvtSpawnCentipede(position, movementState, numSegments); }
	virtual void Update();
	virtual void Alarm0();

private:
	// Setup instance
	static CentipedeSpawner* ptrInstance;

	static CentipedeSpawner& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new CentipedeSpawner;
		}
		return *ptrInstance;
	}

	~CentipedeSpawner();

	CentipedeHead* prvtSpawnCentipede(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments);
	
	// Start
	sf::Vector2f centipedeStart = { 248.0f, -8.0f };
	sf::Vector2f centipedeTest = { 248.0f, 328.0f };

	// Alarm setup
	int centipedeOnScreenCount;
	int centipedeIntervalMinimum; // Minimum spawn inbetween previous
	int centipedeIntervalMaximum; // Maximum spawn inbetween previous
	int centipedeOnScreenMaximum; // Maximum allowed on screen at a time
	int centipedeSegmentCount;	  // Number of segments for main centipede

	int randomNumber;
	bool alarmSet;
};

#endif _CentipedeSpawner