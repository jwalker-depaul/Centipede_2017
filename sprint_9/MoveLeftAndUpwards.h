#ifndef _MoveLeftAndUpwards
#define _MoveLeftAndUpwards

#include "CentipedeMoveState.h"

class MoveLeftAndUpwards : public  CentipedeMoveState
{
public:
	MoveLeftAndUpwards();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _MoveLeftAndUpwards