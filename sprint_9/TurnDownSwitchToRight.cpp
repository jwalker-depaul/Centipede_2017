#include "TurnDownSwitchToRight.h"
#include "MoveFSM.h"

TurnDownSwitchToRight::TurnDownSwitchToRight()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsTurnDownEndRight;
}

const CentipedeMoveState* TurnDownSwitchToRight::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() + 1; // looking ahead after turn -> right

										  // Check for mushrooms
	bool mushroomToRight = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	if (mushroomToRight == false) // No mushrooms to right
	{
		if (col > MushroomGrid::EAST_WALL)
		{
			if (row == MushroomGrid::BOTTOM_ROW)
			{
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
			}
			else
			{
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
			}
		}
		else
		{
			if ((row + 1) > MushroomGrid::BOTTOM_ROW)
			{
				pNextState = &MoveFSM::StateMoveRightAndUpwards;
			}
			else
			{
				pNextState = &MoveFSM::StateMoveRightAndDownwards;
			}
		}
	}
	else if (mushroomToRight == true) // Edge, shroom or letter?
	{
		if (row != MushroomGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	return pNextState;
}