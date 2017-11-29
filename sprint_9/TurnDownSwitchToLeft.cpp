#include "TurnDownSwitchToLeft.h"
#include "MoveFSM.h"

TurnDownSwitchToLeft::TurnDownSwitchToLeft()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsTurnDownEndLeft;
}

const CentipedeMoveState* TurnDownSwitchToLeft::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() - 1; // looking ahead after turn ->left

										  // Check for mushrooms
	bool mushroomToLeft = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	if (mushroomToLeft == false) // No mushrooms to left
	{
		if (col < MushroomGrid::WEST_WALL)
		{
			if (row == MushroomGrid::BOTTOM_ROW)
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		}
		else
		{
			pNextState = &MoveFSM::StateMoveLeftAndDownwards;
		}

	}
	else if (mushroomToLeft == true) // Edge, shroom or letter?
	{
		if (row != MushroomGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	return pNextState;
}