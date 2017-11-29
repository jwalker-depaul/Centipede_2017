#include "CentipedeHeadFactory.h"

CentipedeHeadFactory *CentipedeHeadFactory::ptrInstance = nullptr;

CentipedeHead* CentipedeHeadFactory::privCreateCentipedeHead(sf::Vector2f position, const CentipedeMoveState* movementState, int numSegments)
{
	CentipedeHead * centipedeHead;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New CentipedeHead");

		centipedeHead = new CentipedeHead();

		centipedeHead->SetExternalManagement(RecycleCentipedeHead);
	}

	else
	{
		ConsoleMsg::WriteLine("Recycled CentipedeHead");

		centipedeHead = recycledItems.top();
		recycledItems.pop();

		centipedeHead->RegisterToCurrentScene();

	}

	// Counter
	centipedeOnScreenCount++;

	return centipedeHead->Initialize(position, movementState, numSegments);
}

void CentipedeHeadFactory::privRecycleCentipedeHead(GameObject *centipedeHead)
{
	recycledItems.push((CentipedeHead*)centipedeHead);
	
	// Counter
	centipedeOnScreenCount--;
}

void CentipedeHeadFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

CentipedeHeadFactory::~CentipedeHeadFactory()
{
	ConsoleMsg::WriteLine("Deleteing recycled items (" + Tools::ToString(recycledItems.size()) + ")");
	// Forces deletion of all recycled GameObjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	centipedeOnScreenCount = 0;
}