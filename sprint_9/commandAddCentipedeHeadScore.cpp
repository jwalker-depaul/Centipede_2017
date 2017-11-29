#include "commandAddCentipedeHeadScore.h"
#include "ScoreManager.h"

void CommandAddCentipedeHeadScore::execute()
{
	ScoreManager::AddScore(ScoreManager::centipedeHeadPoints);
}