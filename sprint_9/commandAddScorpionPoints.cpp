#include "commandAddScorpionPoints.h"
#include "ScoreManager.h"

void CommandAddScorpionPoints::execute()
{
	ScoreManager::AddScore(ScoreManager::scorpionPoints);
}