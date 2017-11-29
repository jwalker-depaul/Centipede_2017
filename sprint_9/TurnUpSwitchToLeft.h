#ifndef _TurnUpSwitchToLeft
#define _TurnUpSwitchToLeft

#include "CentipedeMoveState.h"

class TurnUpSwitchToLeft : public CentipedeMoveState
{
public:
	TurnUpSwitchToLeft();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _TurnUpSwitchToLeft