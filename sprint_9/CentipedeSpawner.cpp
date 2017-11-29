#include "CentipedeSpawner.h"
#include "MoveFSM.h"

CentipedeSpawner* CentipedeSpawner::ptrInstance = nullptr;

void CentipedeSpawner::Initialize()
{
	Instance().centipedeIntervalMinimum = WaveManager::getCentipedeIntervalMinimum();
	Instance().centipedeIntervalMaximum = WaveManager::getCentipedeIntervalMaximum();
	Instance().centipedeOnScreenMaximum = WaveManager::getCentipedeOnScreenMaximum();
	Instance().centipedeSegmentCount	= WaveManager::getCentipedeSegmentCount();
	Instance().alarmSet = false;
}

CentipedeHead* CentipedeSpawner::prvtSpawnCentipede(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments)
{
	return CentipedeHeadFactory::CreateCentipedeHead(position, movementState, numSegments);
}

void CentipedeSpawner::Update()
{
	centipedeOnScreenCount = CentipedeHeadFactory::getCentipedeOnScreenCount();

	if (centipedeOnScreenCount < centipedeOnScreenMaximum && alarmSet == false)
	{
		// Select random number in the range of min to max
		randomNumber = centipedeIntervalMinimum + (std::rand() % (centipedeIntervalMaximum - centipedeIntervalMinimum + 1));
		SetAlarm(0, (float)randomNumber);
		alarmSet = true;
	}
}

void CentipedeSpawner::Alarm0()
{
	spawnCentipede(centipedeStart, &MoveFSM::StateTurnDownSwitchToLeft, centipedeSegmentCount);
	//spawnCentipede(centipedeTest, &MoveFSM::StateTurnDownSwitchToLeft, centipedeSegmentCount);
	alarmSet = true;
}

CentipedeSpawner::~CentipedeSpawner()
{
	ptrInstance = nullptr;
}