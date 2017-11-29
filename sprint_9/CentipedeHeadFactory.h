#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "CentipedeHead.h"

class CentipedeHeadFactory
{
public:

	// Service/API
	static CentipedeHead* CreateCentipedeHead(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments)
	{
		return Instance().privCreateCentipedeHead(position, movementState, numSegments);
	};
	static void RecycleCentipedeHead(GameObject* centipedeHead) { Instance().privRecycleCentipedeHead(centipedeHead); };

	static int getCentipedeOnScreenCount() { return Instance().centipedeOnScreenCount; };

	static void Terminate();

private:
	// Singleton setup

	static CentipedeHeadFactory *ptrInstance;

	CentipedeHeadFactory() = default;
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete; // Prevent copy-construction
	CentipedeHeadFactory& operator = (const CentipedeHeadFactory&) = delete;  // prevent assignment
	~CentipedeHeadFactory(); // Only this class can delete

	static CentipedeHeadFactory & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new CentipedeHeadFactory;
		}

		return *ptrInstance;
	}

	std::stack<CentipedeHead*> recycledItems; // Back to be a non-static member

											  // Methods
	CentipedeHead* privCreateCentipedeHead(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments);
	void privRecycleCentipedeHead(GameObject* centipedeHead);

	int centipedeOnScreenCount = 0;

};

#endif _CentipedeHeadFactory