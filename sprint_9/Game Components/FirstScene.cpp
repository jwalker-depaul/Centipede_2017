// FirstScene
// Andre Berthiaume, Macrch 2013

#include "FirstScene.h"

void FirstScene::Initialize()
{
	/********************
	***   Mushrooms   ***
	********************/

	MushroomGrid::initializeNullGrid(); // Null the mushroom grid
	MushroomGrid::createField();

	/***************************
	***       Managers       ***
	***************************/

	WaveManager::Initialize();
	HUD::Initialize();

	/**************************
	***       Blaster       ***
	**************************/
	BlasterManager::Initialize();
	BlasterManager::createPlayerOne();

	/*******************
	***   Spawners   ***
	*******************/

	ScorpionSpawner::Initialize();
	FleaSpawner::Initialize();
	SpiderSpawner::Initialize();
	CentipedeSpawner::Initialize();

	/************************
	***       Sound       ***
	************************/
	SoundManager::Initialize();
	
	/*****************************
	***       Collisions       ***
	*****************************/

	// Blaster Collisions
	CollisionTestPair<Blaster, Mushroom>();
	CollisionTestPair<Blaster, Scorpion>();
	CollisionTestPair<Blaster, Flea>();
	CollisionTestPair<Blaster, Spider>();
	CollisionTestPair<Blaster, CentipedeHead>();
	CollisionTestPair<Blaster, CentipedeSegment>();

	// Bullet Collisions
	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Bullet, CentipedeHead>();
	CollisionTestPair<Bullet, Spider>();
	CollisionTestPair<Bullet, CentipedeSegment>();

	// Critter Collisions
	CollisionTestPair<Mushroom, Spider>();
}

// Destroy all singletons (factories and managers)
void FirstScene::Terminate()
{
	BulletFactory::Terminate();
	BlasterManager::Terminate();
	CritterDeathFactory::Terminate();
	MushroomFactory::Terminate();

	// Critter factories
	CentipedeHeadFactory::Terminate();
	CentipedeSegmentFactory::Terminate();
	FleaFactory::Terminate();
	ScorpionFactory::Terminate();
	SpiderFactory::Terminate();
}