#include "MoveLeftAndDownwards.h"
#include "MoveFSM.h"

MoveLeftAndDownwards::MoveLeftAndDownwards()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsStraightLeft;
}

const CentipedeMoveState* MoveLeftAndDownwards::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() - 1; // looking ahead while left

										  // Check for mushrooms
	bool mushroomToLeft = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	// If no mushrooms to the left
	if (mushroomToLeft == false)
	{
		// If haven't reached the wall
		if (col < MushroomGrid::WEST_WALL)
		{
			// If at the bottom of the screen
			if (row == MushroomGrid::BOTTOM_ROW)
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		}

		// haven't reached the wall
		else
		{
			pNextState = &MoveFSM::StateMoveLeftAndDownwards;
		}
	}
	else if (mushroomToLeft == true) // Edge, shroom or letter?
	{
		if (row == MushroomGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}
	return pNextState;
}