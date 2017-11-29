// ScoreManager
// Joseph Walker

#include "ScoreManager.h"

// Commands
#include "commandAddMushroomDestroyedScore.h"

ScoreManager* ScoreManager::ptrInstance = nullptr;

ScoreManager::ScoreManager()
{
	prvtResetScore();
	highScoreStr = getHighScore();
	highScore = std::stoi(getHighScore());
}

void ScoreManager::Destroy()
{
	if (newHighScore)
	{
		std::ofstream outputFile;
		outputFile.open("highScore.txt");
		outputFile << highScore;
		outputFile.close();
	}
	ptrInstance = nullptr;
}

/**************************************
***         Created Methods         ***
**************************************/

void ScoreManager::prvtResetScore()
{
	totalScore = 0;
	prvtUpdateCurrentScoreHUD(totalScore);
}


std::string ScoreManager::getHighScore()
{
	std::ifstream Hight_Score_File;
	Hight_Score_File.open("highScore.txt");

	char c;
	Hight_Score_File.get(c);

	while (Hight_Score_File)
	{
		//ConsoleMsg::WriteLine("Char = " + Tools::ToString(c));
		highScoreStr += c;
		Hight_Score_File.get(c);
	}

	//ConsoleMsg::WriteLine("HIGHSCORE = " + highScoreStr);

	Hight_Score_File.close();

	return highScoreStr;
}

void ScoreManager::prvtAddScore(int score)
{
	totalScore += score;
	prvtUpdateCurrentScoreHUD(totalScore);
}

/**********************
***   HUD Methods   ***
**********************/

void ScoreManager::prvtUpdateCurrentScoreHUD(int score)
{
	HUD::updateCurrentScore(score);

	if (score > highScore)
	{
		highScore = score;
		prvtUpdateHighScoreHUD(highScore);
		newHighScore = true;
	}
}

void ScoreManager::prvtUpdateHighScoreHUD(int score)
{
	if (newHighScore)
	{
		std::ofstream outputFile;
		outputFile.open("highScore.txt");
		outputFile << highScore;
		outputFile.close();
	}
}

/*********************************
***         Add Scores         ***
*********************************/

void ScoreManager::prvtAddScorpionScore()
{
	scorpionScore.execute();
}

void ScoreManager::prvtAddFleaScore()
{
	fleaScore.execute();
}

void ScoreManager::prvtAddCentipedeSegmentScore()
{
	segmentScore.execute();
}

void ScoreManager::prvtAddCentipedeHeadScore()
{
	headScore.execute();
}

void ScoreManager::prvtAddDestroyMushroomScore()
{
	mushroomScore.execute();
}

void ScoreManager::prvtAddSpiderScore()
{
	spiderScore.execute();
}