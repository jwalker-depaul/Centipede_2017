#include "CentipedeMoveCollection.h"

const movementDirection CentipedeMovementCollection::OffsetsNoMovement = movementDirection(0, 0, 0);
const movementDirection CentipedeMovementCollection::OffsetsStraightRight = movementDirection(2, 0, 180);
const movementDirection CentipedeMovementCollection::OffsetsTurnUpEndRight = movementDirection(0, -2, 90);
const movementDirection CentipedeMovementCollection::OffsetsTurnDownEndRight = movementDirection(0, 2, -90);
const movementDirection CentipedeMovementCollection::OffsetsStraightLeft = movementDirection(-2, 0, 0);
const movementDirection CentipedeMovementCollection::OffsetsTurnUpEndLeft = movementDirection(0, -2, 90);
const movementDirection CentipedeMovementCollection::OffsetsTurnDownEndLeft = movementDirection(0, 2, -90);
