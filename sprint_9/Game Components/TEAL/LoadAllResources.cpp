// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../../PlayerOneScene.h"
#include "../../AttractorScene.h"

void ResourceManager::LoadAllResources()
{
	//SetStartScene(new PlayerOneScene);
	SetStartScene(new AttractorScene);
	
	/****************************
	***         Fonts         ***
	****************************/

	AddFont("MyDefaultFont", "../Game Components/TEAL/Arial.ttf");
	AddTexture("Alphabet", "../Game Components/Sprites/FONT.bmp");

	/******************************
	***         Sprites         ***
	******************************/

	// Player
	AddTexture("Blaster", "../Game Components/Sprites/blaster.png");
	AddTexture("Bullet", "../Game Components/Sprites/bullet.png");
	AddTexture("CritterDeath", "../Game Components/Sprites/death.png");

	// Mushroom
	AddTexture("Mushroom", "../Game Components/Sprites/mushroom.png");

	// Critters
	AddTexture("Scorpion", "../Game Components/Sprites/scorpion.png");
	AddTexture("Flea", "../Game Components/Sprites/flea.png");
	AddTexture("Spider", "../Game Components/Sprites/spider.png");

	// Centipede
	AddTexture("CentipedeHead", "../Game Components/Sprites/centipede_head.png");
	AddTexture("CentipedeBody", "../Game Components/Sprites/centipede_body.png");
	AddTexture("CentipedeSegment", "../Game Components/Sprites/centipede_segment.png");

	/*****************************
	***         Sounds         ***
	*****************************/

	// Player
	AddSound("BlasterDeath", "../Game Components/Sounds/death.wav");
	AddSound("Fire_1", "../Game Components/Sounds/fire1.wav");

	// Critters
	AddSound("EnemyDeath", "../Game Components/Sounds/kill.wav");
	AddSound("ScorpionSound", "../Game Components/Sounds/scorpion_new.wav");
	AddSound("SpiderSpawn", "../Game Components/Sounds/spider_new.wav");
	AddSound("SpiderStep", "../Game Components/Sounds/spiderloop.wav");
	AddSound("FleaStep", "../Game Components/Sounds/flea_new.wav");

	// Mushroom
	AddSound("MushroomBonus", "../Game Components/Sounds/bonus.wav");

	// Centipede
	AddSound("CentipedeSpawn", "../Game Components/Sounds/newBeat.wav");
	AddSound("CentipedeStep", "../Game Components/Sounds/beat.wav");
}

