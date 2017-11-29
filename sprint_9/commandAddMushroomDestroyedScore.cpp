#include "commandAddMushroomDestroyedScore.h"
#include "ScoreManager.h"

void CommandAddMushroomDestroyedScore::execute()
{
	ScoreManager::AddScore(ScoreManager::mushroomDestroyedPoints);
}