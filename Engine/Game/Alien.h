#pragma once
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Sprite.h"

enum AlienType : uint8_t
{

	ALIEN_TYPE_A = 0, 
	ALIEN_TYPE_B = 1,
	ALIEN_TYPE_C = 2,
	ALIEN_DEAD = 4
};

class Alien
{
public:
	size_t x, y;

	uint8_t type;

	Sprite alienOne;

	Sprite alienTwo;

	Sprite alienThree;

	Sprite alienDeath;

	Sprite arrayOfAliens[3];

	SpriteData alienDeath_1;

	Alien();

private:
	SpriteData alienOne_1;
	SpriteData alienOne_2;

	SpriteData alienTwo_1;
	SpriteData alienTwo_2;

	SpriteData alienThree_1;
	SpriteData alienThree_2;

};

