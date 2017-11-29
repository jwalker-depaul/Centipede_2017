//  CentipedeHead
//  Joseph Walker, September 2016

#include "CentipedeHead.h"
#include "MoveFSM.h"


CentipedeHead::CentipedeHead()
{

	//Sprite
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2, 15.0f);
	MainSprite.SetAnimation(animationStart, animationStop);
	MainSprite.setScale(spriteScale, spriteScale);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	//Collision
	bitmap = &ResourceManager::GetTextureBitmap("CentipedeHead");
	SetCollider(MainSprite, *bitmap);
	RegisterCollision<CentipedeHead>(*this);

	// Movement
	frameCounter = 0;
	pPreviousState = &MoveFSM::StateNoMovement;
	pCurrentState = &MoveFSM::StateMoveLeftAndDownwards;

	// CentipedeSegments
	prev = nullptr; // Ahead segment
}

/**************************************
***         Virtual Methods         ***
**************************************/

void CentipedeHead::Update()
{
	MainSprite.Update();

	/***         Movement control         ***/

	prvtPosition.x += (pCurrentState->GetMoveOffsets())->speedX;
	prvtPosition.y += (pCurrentState->GetMoveOffsets())->speedY;
	prvtRotation = (pCurrentState->GetMoveOffsets())->rotation;

	if (frameCounter == frameCounterStop) // Reached end of movment
	{
		if (next != nullptr)
		{
			next->setNextState(pCurrentState);
		}
		pPreviousState = pCurrentState;
		pCurrentState = pCurrentState->GetNextState(this);
		frameCounter = 0;
	}
	else
	{
		frameCounter ++;
	}

	MainSprite.setPosition(prvtPosition);
	MainSprite.setRotation(prvtRotation);
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void CentipedeHead::Destroy()
{
	next = nullptr;

	//Handle centipede
	DeregisterCollision<CentipedeHead>(*this);
}

/***************************************
***         Position Funtions        ***
***************************************/

int CentipedeHead::getRow()
{
	sf::Vector2i currentPosition = MushroomGrid::convertScreenToGrid(prvtPosition);
	return currentPosition.y;
}

int CentipedeHead::getColumn()
{
	sf::Vector2i currentPosition = MushroomGrid::convertScreenToGrid(prvtPosition);
	return currentPosition.x;
}

const CentipedeMoveState* CentipedeHead::getPreviousState()
{
	return pPreviousState;
}

/**************************************
***         Created Methods         ***
**************************************/

CentipedeHead* CentipedeHead::Initialize(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments)
{
	prvtReset();
	prvtPosition	= position; // Set starting position
	prvtNumSegments = numSegments; // Replace the default number of segments
	pCurrentState	= movementState; // Set movement state
	pPreviousState = movementState;
	
	MainSprite.setPosition(prvtPosition);
	RegisterCollision<CentipedeHead>(*this);
	prvtCreateSegment(prvtPosition, prvtNumSegments);

	SoundManager::playCentipedeSound();

	return this;
}


void CentipedeHead::prvtCreateSegment(sf::Vector2f position, int numSegments)
{
	//ConsoleMsg::WriteLine("numSegments = " + Tools::ToString(numSegments));
	if (numSegments > 0)
	{
		prvtNumSegments = --numSegments;
		CentipedeSegment* centipedeSegment;
		centipedeSegment = CentipedeSegmentFactory::CreateCentipedeSegment(position, prvtNumSegments);
		next = centipedeSegment;
		next->prev = this;
	}
}

void CentipedeHead::prvtCreateCentipedeHead()
{
	prvtNumSegments--;
	CentipedeHead *centipedeHead;

	centipedeHead = CentipedeHeadFactory::CreateCentipedeHead(next->getPosition(), next->getCurrentState() , 0);
	centipedeHead->frameCounter = frameCounter;

	if (next->next != nullptr)
	{
		centipedeHead->next = next->next;
		next->next->prev = centipedeHead;
	}
	next->MarkForDestroy();

	SoundManager::endCentipedeSound();
	MarkForDestroy();
}

void CentipedeHead::prvtReset()
{
	next = nullptr;
	prev = nullptr;
	frameCounter = 0;
}

/*********************************
***         Collisions         ***
*********************************/

void CentipedeHead::Collision(Bullet *other)
{
	ScoreManager::AddCentipedeHeadScore();
	MushroomGrid::createMushroom(MushroomGrid::convertScreenToGrid(prvtPosition));
	
	// Segment

	if (next != nullptr)
	{
		prvtCreateCentipedeHead();
	}
	
	SoundManager::endCentipedeSound();
	MarkForDestroy();
}