#include "PoisonTurnDownSwitchToRight.h"
#include "MoveFSM.h"

PoisonTurnDownSwitchToRight::PoisonTurnDownSwitchToRight()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsTurnDownEndRight;
}

const CentipedeMoveState* PoisonTurnDownSwitchToRight::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();

	if (row != MushroomGrid::BOTTOM_ROW - 1)
		pNextState = &MoveFSM::StatePoisonTurnDownSwitchToLeft;
	else
		pNextState = &MoveFSM::StateTurnDownSwitchToLeft; // Turn off poison on last turn

	return pNextState;
}
