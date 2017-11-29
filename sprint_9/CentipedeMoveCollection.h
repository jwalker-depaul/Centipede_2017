#ifndef _CentipedeMovementCollection
#define _CentipedeMovementCollection

struct movementDirection
{
	float speedX;
	float speedY;
	float rotation;

	movementDirection(float x, float y, float z) : speedX(x), speedY(y), rotation(z) {};
};

class CentipedeMovementCollection
{
public:
	static const movementDirection OffsetsNoMovement;
	static const movementDirection OffsetsStraightRight;
	static const movementDirection OffsetsTurnUpEndRight;
	static const movementDirection OffsetsTurnDownEndRight;
	static const movementDirection OffsetsStraightLeft;
	static const movementDirection OffsetsTurnUpEndLeft;
	static const movementDirection OffsetsTurnDownEndLeft;

};

#endif _CentipedeMovementCollection