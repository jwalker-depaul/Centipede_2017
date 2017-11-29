#ifndef _SpiderFactory
#define _SpiderFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Spider.h"

class SpiderFactory
{
public:

	// Services / API
	static Spider* CreateSpider()
	{
		return Instance().privCreateSpider();
	}
	static void RecycleSpider(GameObject *spider) { Instance().privRecycleSpider(spider); };

	static int getSpiderOnScreenCount() { return Instance().spiderOnScreenCount; };

	static void Terminate();

private:

	static SpiderFactory *ptrInstance;

	SpiderFactory()										= default;
	SpiderFactory(const SpiderFactory&)					= delete;
	SpiderFactory* operator = (const SpiderFactory&)	= delete;
	~SpiderFactory();

	static SpiderFactory& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new SpiderFactory;
		}
		return *ptrInstance;
	}

	std::stack<Spider*> recycledItems;

	Spider* privCreateSpider();
	void privRecycleSpider(GameObject* spider);

	int spiderOnScreenCount = 0;

};

#endif _SpiderFactory