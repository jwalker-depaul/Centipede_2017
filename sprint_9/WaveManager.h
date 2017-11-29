#ifndef _WaveManager
#define _WaveManager

#include "Game Components\TEAL\CommonElements.h"
#include <fstream>
#include <iostream>
#include "ScorpionSpawner.h"
#include "FleaSpawner.h"
#include "SpiderSpawner.h"
#include "CentipedeSpawner.h"
#include "BlasterManager.h"

class WaveManager : public GameObject
{
public:
	static void Initialize() { Instance().prvtInitialize(); };

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	
	/**********************************
	***   Critter Stats Accessors   ***
	**********************************/

	// Get Player Stats
	static int getPlayerLives() { return Instance().playerLives; };

	// Get Scorpion Stats
	static int getScorpionIntervalMinimum() { return Instance().scorpionIntervalMinimum; };
	static int getScorpionIntervalMaximum() { return Instance().scorpionIntervalMaximum; };
	static int getScorpionOnScreenMaximum() { return Instance().scorpionOnScreenMaximum; };

	// Get Flea Stats
	static int getFleaIntervalMinimum() { return Instance().fleaIntervalMinimum; };
	static int getFleaIntervalMaximum() { return Instance().fleaIntervalMaximum; };
	static int getFleaOnScreenMaximum() { return Instance().fleaOnScreenMaximum; };
	
	// Get Spider Stats
	static int getSpiderIntervalMinimum() { return Instance().spiderIntervalMinimum; };
	static int getSpiderIntervalMaximum() { return Instance().spiderIntervalMaximum; };
	static int getSpiderOnScreenMaximum() { return Instance().spiderOnScreenMaximum; };

	// Get Centipede Stats
	static int getCentipedeIntervalMinimum()	{ return Instance().centipedeIntervalMinimum; };
	static int getCentipedeIntervalMaximum()	{ return Instance().centipedeIntervalMaximum; };
	static int getCentipedeOnScreenMaximum()	{ return Instance().centipedeOnScreenMaximum; };
	static int getCentipedeSegmentCount()		{ return Instance().centipedeSegmentCount; };

private:
	static WaveManager* ptrInstance;
	WaveManager();
	WaveManager(const WaveManager&) = delete;
	WaveManager& operator = (const WaveManager&) = delete;
	~WaveManager();

	static WaveManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new WaveManager;
		}
		return *ptrInstance;
	}

	void prvtInitialize();

	/*************************
	***   File Variables   ***
	*************************/

	void prvtReadFromFile();
	static std::string setUpperCase(std::string text);
	std::ifstream fileStream; // Can't be initialized as static???
	char linesToRead[30]; // Buffer
	std::string line;

	/****************
	***   Stats   ***
	****************/

	template <typename T>
	void prvtSetStats(T &stat, std::string text);
	int prvtGetStatValue();

	/********************
	***   Set Stats   ***
	********************/
	void prvtSetDefaultValues();
	void prvtSetPlayerStats();
	void prvtSetScorpionStats();
	void prvtSetFleaStats();
	void prvtSetSpiderStats();
	void prvtSetCentipedeStats();

	/****************************
	***   Default Variables   ***
	****************************/

	//Defaults for when wave information isn't given in text file
	int defaultPlayerLives		= 3;
	int defaultIntervalMinimum	= 1;  
	int defaultIntervalMaximum	= 5;
	int defaultOnScreenMaximum	= 1;
	int defaultSetmentCount		= 6;

	/***********************
	***   Player Stats   ***
	***********************/
	bool playerValuesSet = false;
	int playerLives;

	/*****************************
	***   Scorpion Variables   ***
	*****************************/
	bool scorpionValuesSet = false;
	int scorpionIntervalMinimum; // Minimum spawn inbetween previous
	int scorpionIntervalMaximum; // Maximum spawn inbetween previous
	int scorpionOnScreenMaximum; // Maximum allowed on screen at a time

	/*************************
	***   Flea Variables   ***
	*************************/

	bool fleaValuesSet = false;
	int fleaIntervalMinimum; // Minimum spawn inbetween previous
	int fleaIntervalMaximum; // Maximum spawn inbetween previous
	int fleaOnScreenMaximum; // Maximum allowed on screen at a time

	/***************************
	***   Spider Variables   ***
	***************************/

	bool spiderValuesSet = false;
	int spiderIntervalMinimum; // Minimum spawn inbetween previous
	int spiderIntervalMaximum; // Maximum spawn inbetween previous
	int spiderOnScreenMaximum; // Maximum allowed on screen at a time

	/******************************
	***   Centipede Variables   ***
	******************************/

	bool centipedeValuesSet = false;
	int centipedeIntervalMinimum; // Minimum spawn inbetween previous
	int centipedeIntervalMaximum; // Maximum spawn inbetween previous
	int centipedeOnScreenMaximum; // Maximum allowed on screen at a time
	int centipedeSegmentCount;	  // Number of segments on main centipede
};

#endif _WaveManager