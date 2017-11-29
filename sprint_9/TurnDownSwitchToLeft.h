#ifndef _TurnDownSwitchToLeft
#define _TurnDownSwitchToLeft

#include "CentipedeMoveState.h"

class TurnDownSwitchToLeft : public CentipedeMoveState
{
public:
	TurnDownSwitchToLeft();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _TurnDownSwitchToLeft