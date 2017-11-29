#include "MoveRightAndDownwards.h"
#include "MoveFSM.h"

MoveRightAndDownwards::MoveRightAndDownwards()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsStraightRight;
}

const CentipedeMoveState* MoveRightAndDownwards::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() + 1; // looking ahead while right

										  // Check for mushrooms
	bool mushroomToRight = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	if (mushroomToRight == false) // If road ahead is clear
	{
		if (col > MushroomGrid::EAST_WALL)
		{
			if (row == MushroomGrid::BOTTOM_ROW)
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		}
		else
		{
			pNextState = &MoveFSM::StateMoveRightAndDownwards;
		}
	}

	else if (mushroomToRight == true) // Edge, shroom or letter?
	{
		if (row == MushroomGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	return pNextState;
}