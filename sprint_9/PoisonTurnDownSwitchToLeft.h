#ifndef _PoisonTurnDownSwitchToLeft
#define _PoisonTurnDownSwitchToLeft

#include "CentipedeMoveState.h"

class PoisonTurnDownSwitchToLeft : public  CentipedeMoveState
{
public:
	PoisonTurnDownSwitchToLeft();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _PoisonTurnDownSwitchToLeft