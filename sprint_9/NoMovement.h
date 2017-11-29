#ifndef _NoMovement
#define _NoMovement

#include "CentipedeMoveState.h"
#include "CentipedeHead.h"

class NoMovement : public CentipedeMoveState
{
public:
	NoMovement();
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const;
};

#endif _NoMovement