#include "Bullet.h"

Bullet::Bullet()
{
	sprite.sData.width = 1;
	sprite.sData.height = 3;
	sprite.sData.data = new uint8_t[3]
	{
		1,
		1,
		1
	};
}
