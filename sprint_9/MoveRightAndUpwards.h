#ifndef _MoveRightAndUpwards
#define _MoveRightAndUpwards

#include "CentipedeMoveState.h"

class MoveRightAndUpwards : public  CentipedeMoveState
{
public:
	MoveRightAndUpwards();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _MoveRightAndUpwards