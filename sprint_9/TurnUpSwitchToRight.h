#ifndef _TurnUpSwitchToRight
#define _TurnUpSwitchToRight

#include "CentipedeMoveState.h"

class TurnUpSwitchToRight : public  CentipedeMoveState
{
public:
	TurnUpSwitchToRight();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _TurnUpSwitchToRight