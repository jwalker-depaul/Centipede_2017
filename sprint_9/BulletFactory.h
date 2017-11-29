#ifndef _BulletFactory
#define _BulletFactory

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Bullet.h"

class BulletFactory
{
public:

	// Services/API
	static void CreateBullet(sf::Vector2f position) { Instance().privCreateBullet(position); };
	static void RecycleBullet(GameObject* bullet) { Instance().privRecycleBullet(bullet); };

	static void Terminate();

private:
	
	/**********************************
	***       Singleton Setup       ***
	**********************************/
	static BulletFactory* ptrInstance; // Game set up as a singleton

	BulletFactory() = default;
	BulletFactory(const BulletFactory&) = delete; // Prevent copy-construction
	BulletFactory& operator = (const BulletFactory&) = delete; // Prevent assignment
	~BulletFactory(); // Only this class can delete

	static BulletFactory & Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new BulletFactory;
		}
		return *ptrInstance;
	}

	std::stack<Bullet*> recycledItems; // Back to be a non-static member

	// Private methods
	void privCreateBullet(sf::Vector2f position);
	void privRecycleBullet(GameObject* bullet);

	bool canFire = true;

};

#endif _BulletFactory