#include "PoisonTurnDownSwitchToLeft.h"
#include "MoveFSM.h"

PoisonTurnDownSwitchToLeft::PoisonTurnDownSwitchToLeft()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsTurnDownEndLeft;
}

const CentipedeMoveState* PoisonTurnDownSwitchToLeft::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();

	if (row != MushroomGrid::BOTTOM_ROW - 1)
		pNextState = &MoveFSM::StatePoisonTurnDownSwitchToRight;
	else
		pNextState = &MoveFSM::StateTurnDownSwitchToRight;  // Turn off poison on last turn

	return pNextState;
}