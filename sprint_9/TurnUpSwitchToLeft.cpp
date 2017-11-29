#include "TurnUpSwitchToLeft.h"
#include "MoveFSM.h"

TurnUpSwitchToLeft::TurnUpSwitchToLeft()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsTurnUpEndLeft;
}

const CentipedeMoveState* TurnUpSwitchToLeft::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() - 1; // looking ahead after turn -> left

										  // Check for mushrooms
	bool mushroomToLeft = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	if (mushroomToLeft == false) // No mushrooms ahead
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (mushroomToLeft == true) // Edge, shroom or letter?
	{
		if (row != MushroomGrid::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}

	else if (col <= MushroomGrid::WEST_WALL)
	{
		pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}

	return pNextState;
}