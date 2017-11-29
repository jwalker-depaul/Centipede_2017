#ifndef _ScoreManager
#define _ScoreManager

#include "Game Components\TEAL\CommonElements.h"
#include "Hud.h"
#include <fstream>
#include <iostream>

// Commands
#include "commandAddMushroomDestroyedScore.h"
#include "commandAddScorpionPoints.h"
#include "commandAddSpiderScore.h"
#include "commandAddFleaScore.h"
#include "commandAddCentipedeSegmentScore.h"
#include "commandAddCentipedeHeadScore.h"

class ScoreManager
{
public:
	
	static void ResetScore() { Instance().prvtResetScore(); };
	static int GetScore() { Instance().prvtGetCurrentScore(); };
	static void AddScore(int score) { Instance().prvtAddScore(score); };

	// Add Scores
	static void AddScorpionScore()			{ Instance().prvtAddScorpionScore(); };
	static void AddFleaScore()				{ Instance().prvtAddFleaScore(); };
	static void AddCentipedeSegmentScore()	{ Instance().prvtAddCentipedeSegmentScore(); };
	static void AddCentipedeHeadScore()		{ Instance().prvtAddCentipedeHeadScore(); };
	static void AddDestroyMushroomScore()	{ Instance().prvtAddDestroyMushroomScore(); };
	static void AddSpiderScore()			{ Instance().prvtAddSpiderScore(); };

	// Points
	static const int scorpionPoints = 1000;
	static const int fleaPoints = 200;
	static const int centipedeSegmentPoints = 10;
	static const int centipedeHeadPoints = 100;
	static const int mushroomDestroyedPoints = 1;
	static const int spiderFarPoints = 300;
	static const int spiderMediumPoints = 600;
	static const int spiderClosePoints = 900;

private:

	static ScoreManager* ptrInstance;					// set up as a singleton
	
	ScoreManager();									// Private constructor 
	ScoreManager(const ScoreManager&) = delete;				// Prevent copy-construction
	ScoreManager& operator=(const ScoreManager&) = delete;	// Prevent assignment
	~ScoreManager() = default;

	static ScoreManager& Instance()					// Access reference (all public methods will be static)
	{
		if (!ptrInstance)
		{
			ptrInstance = new ScoreManager;
		}
		return *ptrInstance;
	};

	// Virtual methods
	virtual void Destroy();

	// Adding score
	void prvtAddScorpionScore();
	void prvtAddFleaScore();
	void prvtAddCentipedeSegmentScore();
	void prvtAddCentipedeHeadScore();
	void prvtAddDestroyMushroomScore();
	void prvtAddSpiderScore();

	// Created methods
	void prvtResetScore();
	int prvtGetCurrentScore() { return totalScore; };
	std::string getHighScore();
	void prvtAddScore(int score);

	// HUD Methods
	void prvtUpdateCurrentScoreHUD(int score);
	void prvtUpdateHighScoreHUD(int score);

	// Scores
	int highScore;
	int totalScore;
	bool newHighScore = false;
	std::string highScoreStr;

	// Commands
	CommandAddMushroomDestroyedScore mushroomScore;
	CommandAddScorpionPoints scorpionScore;
	CommandAddSpiderScore spiderScore;
	CommandAddFleaScore fleaScore;
	CommandAddCentipedeSegmentScore segmentScore;
	CommandAddCentipedeHeadScore headScore;

};

#endif _ScoreManager