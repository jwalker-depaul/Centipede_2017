#include "CentipedeSegment.h"
#include "MoveFSM.h"

CentipedeSegment::CentipedeSegment()
{
	// Sprite
	prvtMainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeSegment"), 8, 2, 15.0f);
	prvtMainSprite.SetAnimation(animationStart, animationStop);
	prvtMainSprite.setOrigin(prvtMainSprite.getTextureRect().width / prvtScale, prvtMainSprite.getTextureRect().height / prvtScale);
	prvtMainSprite.setScale(prvtScale, prvtScale);

	// Collision
	bitmap = &ResourceManager::GetTextureBitmap("CentipedeSegment");
	SetCollider(prvtMainSprite, *bitmap);
	RegisterCollision<CentipedeSegment>(*this);

	// Array
	frameCounter = 0;

	// Movement
	pPreviousState = &MoveFSM::StateNoMovement;
	pCurrentState = &MoveFSM::StateNoMovement;
	pNextState = &MoveFSM::StateNoMovement;
}

/**************************
***   Virtual Methods   ***
**************************/
void CentipedeSegment::Update()
{
	// Check for new states
	if (pNextState != nullptr)
	{
		if (next != nullptr)
		{
			next->setNextState(pCurrentState);
		}
		pCurrentState = pNextState;
		pNextState = nullptr;
	}

	// Update the sprite
	prvtMainSprite.Update();

	prvtPosition.x += (pCurrentState->GetMoveOffsets())->speedX;
	prvtPosition.y += (pCurrentState->GetMoveOffsets())->speedY;
	prvtRotation = (pCurrentState->GetMoveOffsets())->rotation;

	prvtMainSprite.setPosition(prvtPosition);
	prvtMainSprite.setRotation(prvtRotation);
}

void CentipedeSegment::Draw()
{
	WindowManager::MainWindow.draw(prvtMainSprite);
}

void CentipedeSegment::Destroy()
{
	next = nullptr;
	prev = nullptr;
	DeregisterCollision<CentipedeSegment>(*this);
}

/**************************
***   Created Methods   ***
**************************/

void CentipedeSegment::prvtSetNextState(const CentipedeMoveState* state)
{
	pNextState = state;
}

CentipedeSegment* CentipedeSegment::Initialize(sf::Vector2f position, int numSegments = 0)
{
	prvtReset();
	prvtPosition = position;
	prvtNumSegments = numSegments;
	RegisterCollision<CentipedeSegment>(*this);

	prvtMainSprite.setPosition(prvtPosition);
	prvtCreateSegment(position, prvtNumSegments);

	return this;
}

void CentipedeSegment::prvtCreateSegment(sf::Vector2f position, int numSegments)
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

void CentipedeSegment::prvtReset()
{
	next = nullptr;
	prev = nullptr;
	frameCounter = 0;

	pCurrentState = &MoveFSM::StateNoMovement;
}

/*********************
***   Collisions   ***
*********************/

void CentipedeSegment::Collision(Bullet *other)
{

	CritterDeathFactory::CreateExplosion(prvtPosition);
	if (prev != nullptr)
	{
		prev->next = nullptr;
	}

	if (next != nullptr)
	{
		CentipedeHead *centipedeHead = CentipedeHeadFactory::CreateCentipedeHead(next->getPosition(), next->getCurrentState(), 0);

		if (next->next != nullptr)
		{
			centipedeHead->next = next->next;
			next->next->prev = centipedeHead;
		}
		next->MarkForDestroy();

	}

	MushroomGrid::createMushroom(MushroomGrid::convertScreenToGrid(prvtPosition));

	MarkForDestroy();
}