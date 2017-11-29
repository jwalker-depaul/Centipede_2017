#include "CentipedeSegmentFactory.h"

CentipedeSegmentFactory *CentipedeSegmentFactory::ptrInstance = nullptr;

CentipedeSegment* CentipedeSegmentFactory::privCreateCentipedeSegment(sf::Vector2f position, int numSegments)
{
	CentipedeSegment* centipedeSegment;

	if (recycledItems.empty())
	{
		centipedeSegment = new CentipedeSegment();

		centipedeSegment->SetExternalManagement(RecycleCentipedeSegment);
	}

	else
	{
		centipedeSegment = recycledItems.top();
		recycledItems.pop();

		centipedeSegment->RegisterToCurrentScene();
	}

	return centipedeSegment->Initialize(position, numSegments);
}

void CentipedeSegmentFactory::privRecycleCentipedeSegment(GameObject* centipedeSegment)
{
	recycledItems.push((CentipedeSegment*)centipedeSegment);
}

void CentipedeSegmentFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

CentipedeSegmentFactory::~CentipedeSegmentFactory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}