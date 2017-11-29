#ifndef _PoisonTurnDownSwitchToRight
#define _PoisonTurnDownSwitchToRight

#include "CentipedeMoveState.h"

class PoisonTurnDownSwitchToRight : public  CentipedeMoveState
{
public:
	PoisonTurnDownSwitchToRight();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _PoisonTurnDownSwitchToRight