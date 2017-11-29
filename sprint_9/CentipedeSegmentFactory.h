#ifndef _CentipedeSegmentFactory
#define _CentipedeSegmentFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "CentipedeSegment.h"

class CentipedeSegmentFactory
{
public:

	// Service/API
	static CentipedeSegment* CreateCentipedeSegment(sf::Vector2f position, int numSegments)
	{
		return Instance().privCreateCentipedeSegment(position, numSegments);
	};
	static void RecycleCentipedeSegment(GameObject* centipedeSegment) { Instance().privRecycleCentipedeSegment(centipedeSegment); };

	static void Terminate();

private:
	// Singleton setup

	static CentipedeSegmentFactory *ptrInstance;

	CentipedeSegmentFactory() = default;
	CentipedeSegmentFactory(const CentipedeSegmentFactory&) = delete; // Prevent copy-construction
	CentipedeSegmentFactory& operator = (const CentipedeSegmentFactory&) = delete;  // prevent assignment
	~CentipedeSegmentFactory(); // Only this class can delete

	static CentipedeSegmentFactory & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new CentipedeSegmentFactory;
		}

		return *ptrInstance;
	}

	std::stack<CentipedeSegment*> recycledItems; // Back to be a non-static member

											  // Methods
	CentipedeSegment* privCreateCentipedeSegment(sf::Vector2f position, int numSegments);
	void privRecycleCentipedeSegment(GameObject* centipedeSegment);


};

#endif _CentipedeSegmentFactory