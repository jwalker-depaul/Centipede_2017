#include "NoMovement.h"

NoMovement::NoMovement()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsNoMovement;
}

const CentipedeMoveState* NoMovement::GetNextState(CentipedeHead* centipede) const
{
	return centipede->getPreviousState();
}