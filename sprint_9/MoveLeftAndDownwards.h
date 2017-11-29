#ifndef _MoveLeftAndDownwards
#define _MoveLeftAndDownwards

#include "CentipedeMoveState.h"

class MoveLeftAndDownwards : public  CentipedeMoveState
{
public:
	MoveLeftAndDownwards();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _MoveLeftAndDownwards