#include "MoveLeftAndUpwards.h"
#include "MoveFSM.h"

MoveLeftAndUpwards::MoveLeftAndUpwards()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsStraightLeft;
}

const CentipedeMoveState* MoveLeftAndUpwards::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() - 1; // looking ahead while left

										  // Check for mushrooms
	bool mushroomToLeft = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	if (mushroomToLeft == false) // No mushrooms to left
	{
		if (col < MushroomGrid::WEST_WALL)
		{
			if (row == MushroomGrid::TOP_PLAYER_ROW)
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		}
		else
		{
			pNextState = &MoveFSM::StateMoveLeftAndUpwards;
		}

	}
	else if (mushroomToLeft == true) // Edge, shroom or letter?
	{
		if (row == MushroomGrid::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	return pNextState;
}