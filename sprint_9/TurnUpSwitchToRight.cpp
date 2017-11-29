#include "TurnUpSwitchToRight.h"
#include "MoveFSM.h"

TurnUpSwitchToRight::TurnUpSwitchToRight()
{
	MyMoveOffsets = &CentipedeMovementCollection::OffsetsTurnUpEndRight;
}

const CentipedeMoveState* TurnUpSwitchToRight::GetNextState(CentipedeHead* centipede) const
{
	const CentipedeMoveState* pNextState;

	int row = centipede->getRow();
	int col = centipede->getColumn() + 1; // looking ahead after turn -> Right

										  // Check for mushrooms
	bool mushroomToRight = MushroomGrid::isMushroom({ row, col });
	bool isPoisonMushroom = MushroomGrid::isPoisonMushroom({ row, col });

	if (mushroomToRight == false) // No mushrooms ahead
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (mushroomToRight == true) // Edge, shroom or letter?
	{
		if (row != MushroomGrid::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else if (isPoisonMushroom)
			pNextState = &MoveFSM::StatePoisonTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	return pNextState;
}