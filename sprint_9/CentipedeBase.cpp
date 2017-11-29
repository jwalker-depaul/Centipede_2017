#include "CentipedeBase.h"

sf::Vector2f *CentipedeBase::getDirection()
{
	return previousDirection;
}

sf::Vector2f CentipedeBase::getPosition()
{
	return position;
}

const CentipedeMoveState* CentipedeBase::getPreviousState()
{
	return pPreviousState;
}