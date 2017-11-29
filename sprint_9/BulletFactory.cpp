// BulletFactory
// Joseph Walker

#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory *BulletFactory::ptrInstance = nullptr;

void BulletFactory::privCreateBullet(sf::Vector2f position)
{
	// If there is no bullet currently on screen
	if (canFire)
	{
		Bullet *bullet;

		// If this is the first bullet, create a new one
		if (recycledItems.empty())
		{
			//ConsoleMsg::WriteLine("New Bullet");

			bullet = new Bullet();

			bullet->SetExternalManagement(RecycleBullet);
			canFire = false;
		}

		// Recycle the previous bullet
		else
		{
			//ConsoleMsg::WriteLine("Recycled Bullet");

			bullet = recycledItems.top();
			recycledItems.pop();

			bullet->RegisterToCurrentScene();
			canFire = false;
		}


		// Have the bullet initialize itself at the blaster position
		bullet->Initialize(position);
	}

}

void BulletFactory::privRecycleBullet(GameObject *bullet)
{
	canFire = true;
	recycledItems.push((Bullet*)bullet);
	//ConsoleMsg::WriteLine("Recycled Bullet Stack Size: " + Tools::ToString(recycledItems.size()));
}

void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

BulletFactory::~BulletFactory()
{
	// Forces deletion of all recycled GameObjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}