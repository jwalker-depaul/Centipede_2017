#include "MoveRightAndUpwards.h"
#include "MoveFSM.h"

MoveRightAndUpwards::MoveRightAndUpwards()
{

	MyMoveOffsets = &CentipedeMovementCollection::OffsetsStraightRight;
}

const CentipedeMoveState* MoveRightAndUpwards::GetNextState(CentipedeHead* centipede) const
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
			if (row == MushroomGrid::TOP_PLAYER_ROW)
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
			else
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		}
		else
		{
			pNextState = &MoveFSM::StateMoveRightAndUpwards;
		}
	}

	else if (mushroomToRight == true) // Edge, shroom or letter?
	{
		if (row == MushroomGrid::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	return pNextState;
}