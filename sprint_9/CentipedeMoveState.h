#ifndef _CentipedeMoveState
#define _CentipedeMoveState

#include "CentipedeMoveCollection.h"

struct movementDirection;
class CentipedeHead;
class CentipedeBase;

class CentipedeMoveState
{
public:
	CentipedeMoveState() {};
	const movementDirection* GetMoveOffsets() const { return MyMoveOffsets; }
	virtual const CentipedeMoveState* GetNextState(CentipedeHead* centipede) const = 0;

protected:
	const movementDirection* MyMoveOffsets;

};



#endif _CentipedeMoveState