#include "commandAddSpiderScore.h"
#include "ScoreManager.h"

void CommandAddSpiderScore::execute()
{
	ScoreManager::AddScore(ScoreManager::spiderClosePoints);
}