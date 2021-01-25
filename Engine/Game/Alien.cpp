#include "Alien.h"

Alien::Alien()
{
	alienOne_1.width = 8;
	alienOne_1.height = 8;
	alienOne_1.data = new uint8_t[64]
	{
		0,0,0,1,1,0,0,0, // ...@@...
		0,0,1,1,1,1,0,0, // ..@@@@..
		0,1,1,1,1,1,1,0, // .@@@@@@.
		1,1,0,1,1,0,1,1, // @@.@@.@@
		1,1,1,1,1,1,1,1, // @@@@@@@@
		0,1,0,1,1,0,1,0, // .@.@@.@.
		1,0,0,0,0,0,0,1, // @......@
		0,1,0,0,0,0,1,0  // .@....@.
	};

	alienOne.anim.loop = true;
	alienOne.anim.numFrames = 2;
	alienOne.anim.frameDuration = 20;
	alienOne.anim.time = 0;
	alienOne.anim.frames = new SpriteData*[2];
	alienOne.anim.frames[0] = &alienOne_1;

	alienOne_2.width = 8;
	alienOne_2.height = 8;
	alienOne_2.data = new uint8_t[64]
	{
		0,0,0,1,1,0,0,0, // ...@@...
		0,0,1,1,1,1,0,0, // ..@@@@..
		0,1,1,1,1,1,1,0, // .@@@@@@.
		1,1,0,1,1,0,1,1, // @@.@@.@@
		1,1,1,1,1,1,1,1, // @@@@@@@@
		0,0,1,0,0,1,0,0, // ..@..@..
		0,1,0,1,1,0,1,0, // .@.@@.@.
		1,0,1,0,0,1,0,1  // @.@..@.@
	};
	alienOne.anim.frames[1] = &alienOne_2;
	arrayOfAliens[0] = alienOne;

	alienTwo_1.width = 11;
	alienTwo_1.height = 8;
	alienTwo_1.data = new uint8_t[88]
	{
		0,0,1,0,0,0,0,0,1,0,0, // ..@.....@..
		0,0,0,1,0,0,0,1,0,0,0, // ...@...@...
		0,0,1,1,1,1,1,1,1,0,0, // ..@@@@@@@..
		0,1,1,0,1,1,1,0,1,1,0, // .@@.@@@.@@.
		1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
		1,0,1,1,1,1,1,1,1,0,1, // @.@@@@@@@.@
		1,0,1,0,0,0,0,0,1,0,1, // @.@.....@.@
		0,0,0,1,1,0,1,1,0,0,0  // ...@@.@@...
	};

	alienTwo.anim.loop = true;
	alienTwo.anim.numFrames = 2;
	alienTwo.anim.frameDuration = 20;
	alienTwo.anim.time = 0;
	alienTwo.anim.frames = new SpriteData*[2];
	alienTwo.anim.frames[0] = &alienTwo_1;

	alienTwo_2.width = 11;
	alienTwo_2.height = 8;
	alienTwo_2.data = new uint8_t[88]
	{
		0,0,1,0,0,0,0,0,1,0,0, // ..@.....@..
		1,0,0,1,0,0,0,1,0,0,1, // @..@...@..@
		1,0,1,1,1,1,1,1,1,0,1, // @.@@@@@@@.@
		1,1,1,0,1,1,1,0,1,1,1, // @@@.@@@.@@@
		1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
		0,1,1,1,1,1,1,1,1,1,0, // .@@@@@@@@@.
		0,0,1,0,0,0,0,0,1,0,0, // ..@.....@..
		0,1,0,0,0,0,0,0,0,1,0  // .@.......@.
	};
	alienTwo.anim.frames[1] = &alienTwo_2;
	arrayOfAliens[1] = alienTwo;

	alienThree_1.width = 12;
	alienThree_1.height = 8;
	alienThree_1.data = new uint8_t[96]
	{
		0,0,0,0,1,1,1,1,0,0,0,0, // ....@@@@....
		0,1,1,1,1,1,1,1,1,1,1,0, // .@@@@@@@@@@.
		1,1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@@
		1,1,1,0,0,1,1,0,0,1,1,1, // @@@..@@..@@@
		1,1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@@
		0,0,0,1,1,0,0,1,1,0,0,0, // ...@@..@@...
		0,0,1,1,0,1,1,0,1,1,0,0, // ..@@.@@.@@..
		1,1,0,0,0,0,0,0,0,0,1,1  // @@........@@
	};

	alienThree.anim.loop = true;
	alienThree.anim.numFrames = 2;
	alienThree.anim.frameDuration = 20;
	alienThree.anim.time = 0;
	alienThree.anim.frames = new SpriteData*[2];
	alienThree.anim.frames[0] = &alienThree_1;

	alienThree_2.width = 12;
	alienThree_2.height = 8;
	alienThree_2.data = new uint8_t[96]
	{
		0,0,0,0,1,1,1,1,0,0,0,0, // ....@@@@....
		0,1,1,1,1,1,1,1,1,1,1,0, // .@@@@@@@@@@.
		1,1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@@
		1,1,1,0,0,1,1,0,0,1,1,1, // @@@..@@..@@@
		1,1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@@
		0,0,1,1,1,0,0,1,1,1,0,0, // ..@@@..@@@..
		0,1,1,0,0,1,1,0,0,1,1,0, // .@@..@@..@@.
		0,0,1,1,0,0,0,0,1,1,0,0  // ..@@....@@..
	};
	alienThree.anim.frames[1] = &alienThree_2;
	arrayOfAliens[2] = alienThree;

	alienDeath_1.width = 13;
	alienDeath_1.height = 7;
	alienDeath_1.data = new uint8_t[91]
	{
	0,1,0,0,1,0,0,0,1,0,0,1,0, // .@..@...@..@.
	0,0,1,0,0,1,0,1,0,0,1,0,0, // ..@..@.@..@..
	0,0,0,1,0,0,0,0,0,1,0,0,0, // ...@.....@...
	1,1,0,0,0,0,0,0,0,0,0,1,1, // @@.........@@
	0,0,0,1,0,0,0,0,0,1,0,0,0, // ...@.....@...
	0,0,1,0,0,1,0,1,0,0,1,0,0, // ..@..@.@..@..
	0,1,0,0,1,0,0,0,1,0,0,1,0  // .@..@...@..@.
	};

	alienDeath.anim.loop = false;
	alienThree.anim.numFrames = 1;
	alienThree.anim.frameDuration = 10;
	alienThree.anim.time = 0;
	alienThree.anim.frames = new SpriteData*[1];
	alienThree.anim.frames[0] = &alienDeath_1;

}
