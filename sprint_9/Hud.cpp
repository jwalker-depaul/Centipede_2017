#include "HUD.h"
#include "WaveManager.h"

HUD* HUD::ptrInstance = nullptr;

void HUD::Initialize()
{
	// blaster Lives
	Instance().blasterLives = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 1, 1);
	Instance().blasterLives.SetAnimation(0, 0);
	Instance().blasterLives.setScale(Instance().blastLivesScale, Instance().blastLivesScale);

	Instance().playerLives = WaveManager::getPlayerLives();

	// Begin Hud
	Instance().prvtUpdateCurrentScore(0);
	Instance().prvtUpdateHighScore(9001);
}

/**************************************
***         Virtual Methods         ***
**************************************/

void HUD::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = scoreSymbols.begin(); it != scoreSymbols.end(); it++)
		it->Draw();

	// blasterLives draw
	for (int i = 0; i < playerLives; i++)
	{
		blasterLives.setPosition(blasterPositions[i]);
		WindowManager::MainWindow.draw(blasterLives);
	}

	std::list<Glyph>::iterator HS_it;
	for (HS_it = highScoreSymbols.begin(); HS_it != highScoreSymbols.end(); HS_it++)
		HS_it->Draw();
}

/**************************************
***         Created Methods         ***
**************************************/

void HUD::prvtUpdateCurrentScore(int score)
{
	currentScoreText = Tools::ToString(score);
	nextScorePosition = { float(WindowManager::MainWindow.getSize().x / 8),0 };

	for (size_t i = 0; i < currentScoreText.length(); i++)
	{
		scoreSymbols.push_back(myfont.GetGlyph(currentScoreText.at(i), nextScorePosition));
		nextScorePosition.x += myfont.CellWidth() * blasterSpriteSize; // x2 becauase the scale of the sprites are 2. 
	}

	//stores locaions to draw Blaster icons next to the current score. 
	for (int i = 0; i < playerLives; i++)
	{
		blasterPositions[i] = nextScorePosition;
		nextScorePosition.x += myfont.CellWidth() * blasterSpriteSize;
	}
}

void HUD::prvtUpdateHighScore(int highScore)
{
	highScoreText = Tools::ToString(highScore);
	nextHighScorePosition = { 200, 0 };

	for (size_t i = 0; i < highScoreText.length(); i++)
	{
		highScoreSymbols.push_back(myfont.GetGlyph(highScoreText.at(i), nextHighScorePosition));
		nextHighScorePosition.x += myfont.CellWidth() * 2;
	}
}

void HUD::prvtDecrementPlayerLives(int lives)
{
	playerLives = lives;
	for (int i = 0; i < playerLives; i++)
	{
		blasterLives.setPosition(blasterPositions[i]);
		WindowManager::MainWindow.draw(blasterLives);
	}
}

HUD::~HUD()
{
	ptrInstance = nullptr;
}