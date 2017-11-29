#include "commandAddFleaScore.h"
#include "ScoreManager.h"

void CommandAddFleaScore::execute()
{
	ScoreManager::AddScore(ScoreManager::fleaPoints);
}