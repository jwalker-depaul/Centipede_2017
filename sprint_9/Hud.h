#ifndef _HUD
#define _HUD

#include "Game Components\TEAL\CommonElements.h"
#include <list>
#include "AwesomeFont.h"

class Glyph;

// Game object to appear on screen
class HUD : public GameObject
{
public:
	static void Initialize();

	// Update score
	static void updateCurrentScore(int score) { Instance().prvtUpdateCurrentScore(score); };
	static void updateHighScore(int highScore) { Instance().prvtUpdateHighScore(highScore); };
	static void decrementPlayerLives(int lives) { Instance().prvtDecrementPlayerLives(lives); }

	//static void Terminate();

private:
	static HUD* ptrInstance;

	HUD() = default;
	HUD(const HUD&) = delete;
	HUD& operator = (const HUD&) = delete;
	~HUD();

	static HUD& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new HUD;
		}
		return *ptrInstance;
	}

	// Fonts
	AnimatedSprite ScoreFont;
	AwesomeFont myfont;

	// Display text
	std::string currentScoreText;
	std::string highScoreText;

	// Glyph symbols
	std::list<Glyph> scoreSymbols;
	std::list<Glyph> highScoreSymbols;

	// Text positions
	sf::Vector2f nextScorePosition;
	sf::Vector2f nextHighScorePosition;

	// Blaster lives
	int playerLives;
	int blasterSpriteSize = 2;
	AnimatedSprite blasterLives;
	float blastLivesScale = 1.0f;
	sf::Vector2f blasterPositions[3];
	void prvtDecrementPlayerLives(int lives);
	
	//Virtual methods
	virtual void Draw();

	// Methods
	void prvtUpdateCurrentScore(int score);
	void prvtUpdateHighScore(int highScore);



};

#endif _HUD