#ifndef _MoveRightAndDownwards
#define _MoveRightAndDownwards

#include "CentipedeMoveState.h"

class MoveRightAndDownwards : public CentipedeMoveState
{
public:
	MoveRightAndDownwards();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _MoveRightAndDownwards