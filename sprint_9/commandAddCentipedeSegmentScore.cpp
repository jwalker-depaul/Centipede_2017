#include "commandAddCentipedeSegmentScore.h"
#include "ScoreManager.h"

void CommandAddCentipedeSegmentScore::execute()
{
	ScoreManager::AddScore(ScoreManager::centipedeSegmentPoints);
}