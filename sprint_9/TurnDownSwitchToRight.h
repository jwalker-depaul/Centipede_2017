#ifndef _TurnDownSwitchToRight
#define _TurnDownSwitchToRight

#include "CentipedeMoveState.h"

class TurnDownSwitchToRight : public  CentipedeMoveState
{
public:
	TurnDownSwitchToRight();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _TurnDownSwitchToRight