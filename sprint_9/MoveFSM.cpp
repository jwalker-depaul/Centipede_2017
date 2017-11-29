#include "MoveFSM.h"

// Set up all the unique copies of states
const NoMovement MoveFSM::StateNoMovement;
const MoveRightAndDownwards MoveFSM::StateMoveRightAndDownwards;
const MoveRightAndUpwards MoveFSM::StateMoveRightAndUpwards;
const MoveLeftAndDownwards MoveFSM::StateMoveLeftAndDownwards;
const MoveLeftAndUpwards MoveFSM::StateMoveLeftAndUpwards;
const TurnDownSwitchToLeft MoveFSM::StateTurnDownSwitchToLeft;
const TurnDownSwitchToRight MoveFSM::StateTurnDownSwitchToRight;
const TurnUpSwitchToLeft MoveFSM::StateTurnUpSwitchToLeft;
const TurnUpSwitchToRight MoveFSM::StateTurnUpSwitchToRight;
const PoisonTurnDownSwitchToLeft MoveFSM::StatePoisonTurnDownSwitchToLeft;
const PoisonTurnDownSwitchToRight MoveFSM::StatePoisonTurnDownSwitchToRight;