#ifndef _CentipedeBase
#define _CentipedeBase

#include "Game Components\TEAL\CommonElements.h"
#include "CentipedeMoveCollection.h"
#include "CentipedeMoveState.h"
#include "MushroomGrid.h"
#include "ScoreManager.h"

class Bullet;
class CentipedeSegment;

class CentipedeBase : public GameObject
{
public:
	// Accessors
	sf::Vector2f getPosition() { return prvtPosition; };
	float getRotation() { return prvtRotation; };

	// Movement States
	const CentipedeMoveState* CentipedeBase::getCurrentState() { return pCurrentState; };
	const CentipedeMoveState* CentipedeBase::getPreviousState() { return pPreviousState; };
	const CentipedeMoveState* CentipedeBase::getNextState() { return pNextState; };
	const void CentipedeBase::setNextState(const CentipedeMoveState* state) { pNextState = state; };

	// Position pointers
	CentipedeBase *next = nullptr;
	CentipedeBase *prev = nullptr;

protected:
	CentipedeBase() = default;

	// Movement Directions
	sf::Vector2f prvtPosition;
	float prvtRotation;
	int frameCounter;

	// Movement States
	const CentipedeMoveState* pCurrentState;
	const CentipedeMoveState* pPreviousState;
	const CentipedeMoveState* pNextState;	

	// Rotation
	//float rotateUp = 90.0f;
	//float rotateDown = -90.0f;
	//float rotateLeft = 0.0f;
	//float rotateRight = 180.0f;
};

#endif CentipedeBase