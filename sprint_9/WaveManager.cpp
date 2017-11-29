#include "WaveManager.h"
#include "MoveFSM.h"

WaveManager* WaveManager::ptrInstance = nullptr;

WaveManager::WaveManager()
{
	RegisterInput(InputFlags::KeyPressed);
}

void WaveManager::prvtInitialize()
{
	prvtReadFromFile();
}

/***********************
***   File Parsing   ***
***********************/

void WaveManager::prvtReadFromFile()
{
	fileStream.open("wave_setup.txt");

	if (fileStream.is_open())
	{
		while (fileStream)
		{
			// Get first line
			fileStream.getline(linesToRead, sizeof(linesToRead));

			// Convert to string
			line = std::string(linesToRead);
			
			// Set to upper case for ease of parsing
			line = setUpperCase(line);

			// Set Player values
			if (line == "[PLAYER]")
			{
				prvtSetPlayerStats();
				playerValuesSet = true;
			}

			// Set critter values
			if (line == "[SCORPION]")
			{
				prvtSetScorpionStats();
				scorpionValuesSet = true;
			}

			if (line == "[FLEA]")
			{
				prvtSetFleaStats();
				fleaValuesSet = true;
			}

			if (line == "[SPIDER]")
			{
				prvtSetSpiderStats();
				spiderValuesSet = true;
			}

			if (line == "[CENTIPEDE]")
			{
				prvtSetCentipedeStats();
				centipedeValuesSet = true;
			}
		}
	}

	fileStream.close();

	prvtSetDefaultValues();
}

std::string WaveManager::setUpperCase(std::string text)
{
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
}

template <typename T>
void WaveManager::prvtSetStats(T &stat, std::string txtName)
{
	// Get line from the file
	fileStream.getline(linesToRead, sizeof(linesToRead));
	line = std::string(linesToRead);
	line = setUpperCase(line);

	std::string statStr = "";

	// Seperate statistics by space
	while (line != "")
	{
		// If the string from file equals the given txtName
		if (line.find(txtName) != std::string::npos)
		{
			stat = prvtGetStatValue();
			ConsoleMsg::WriteLine(txtName + " = " + Tools::ToString(stat));
			break;
		}

		fileStream.getline(linesToRead, sizeof(linesToRead));
		line = std::string(linesToRead);
	}
}

int WaveManager::prvtGetStatValue()
{
	// Temporary variables
	std::string returnString = "";
	int length = line.length();

	// Loop and parse through to find full value
	for (int i = 0; i < length; i++)
	{
		if (line[i] == '=')
		{
			for (int j = i + 2; j < length; j++)
			{
				returnString += (line[j]);
			}

			break;
		}
	}

	// Convert string to int and return
	return std::stoi(returnString);
}

/****************************
***   Set Critter Stats   ***
****************************/

void WaveManager::prvtSetDefaultValues()
{
	if (!scorpionValuesSet)
	{
		scorpionIntervalMinimum = defaultIntervalMinimum;
		scorpionIntervalMaximum = defaultIntervalMaximum;
		scorpionOnScreenMaximum = defaultOnScreenMaximum;
	}

	if (!fleaValuesSet)
	{
		fleaIntervalMinimum = defaultIntervalMinimum;
		fleaIntervalMaximum = defaultIntervalMaximum;
		fleaOnScreenMaximum = defaultOnScreenMaximum;
	}

	if (!spiderValuesSet)
	{
		spiderIntervalMinimum = defaultIntervalMinimum;
		spiderIntervalMaximum = defaultIntervalMaximum;
		spiderOnScreenMaximum = defaultOnScreenMaximum;
	}

	if (!centipedeValuesSet)
	{
		centipedeIntervalMinimum	= defaultIntervalMinimum;
		centipedeIntervalMaximum	= defaultIntervalMaximum;
		centipedeOnScreenMaximum	= defaultOnScreenMaximum;
		centipedeSegmentCount		= defaultSetmentCount;
	}

	if (!playerValuesSet)
	{
		playerLives = defaultPlayerLives;
	}
}

void WaveManager::prvtSetPlayerStats()
{
	prvtSetStats(playerLives, "PLAYER LIVES");
}

void WaveManager::prvtSetScorpionStats()
{
	prvtSetStats(scorpionIntervalMinimum, "INTERVAL MINIMUM");
	prvtSetStats(scorpionIntervalMaximum, "INTERVAL MAXIMUM");
	prvtSetStats(scorpionOnScreenMaximum, "MAXIMUM ON SCREEN");
}

void WaveManager::prvtSetFleaStats()
{
	prvtSetStats(fleaIntervalMinimum, "INTERVAL MINIMUM");
	prvtSetStats(fleaIntervalMaximum, "INTERVAL MAXIMUM");
	prvtSetStats(fleaOnScreenMaximum, "MAXIMUM ON SCREEN");
}

void WaveManager::prvtSetSpiderStats()
{
	prvtSetStats(spiderIntervalMinimum, "INTERVAL MINIMUM");
	prvtSetStats(spiderIntervalMaximum, "INTERVAL MAXIMUM");
	prvtSetStats(spiderOnScreenMaximum, "MAXIMUM ON SCREEN");
}

void WaveManager::prvtSetCentipedeStats()
{
	prvtSetStats(centipedeIntervalMinimum, "INTERVAL MINIMUM");
	prvtSetStats(centipedeIntervalMaximum, "INTERVAL MAXIMUM");
	prvtSetStats(centipedeOnScreenMaximum, "MAXIMUM ON SCREEN");
	prvtSetStats(centipedeSegmentCount, "NUMBER OF SEGMENTS");
}

/**********************
***   Alarm Tests   ***
**********************/

void WaveManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{

	// FOR TESTING PURPOSES

	if (k == sf::Keyboard::Num1)
	{
		ScorpionSpawner::spawnScorpion();
	}

	if (k == sf::Keyboard::Num2)
	{
		FleaSpawner::spawnFlea();
	}

	if (k == sf::Keyboard::Num3)
	{
		SpiderSpawner::spawnSpider();
	}

	if (k == sf::Keyboard::Num4)
	{
		CentipedeSpawner::spawnCentipede({ 248, -8 }, &MoveFSM::StateTurnDownSwitchToLeft, 2);
	}
}

WaveManager::~WaveManager()
{
	DeregisterInput();
	ptrInstance = nullptr;
}