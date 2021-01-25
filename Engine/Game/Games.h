#pragma once
#include "Character.h"
#include "Alien.h"
#include "Buffer.h"
#include <iostream>



class Games
{

public:

	virtual ~Games() {};
	Games();
	const char* gameName;

	virtual void RunGame() = 0;
	virtual void GameLoop() = 0;
	Buffer buffer;

	virtual void LeftKey() = 0;
	virtual void RightKey() = 0;
	virtual void LeftRightKeyReleased() = 0;
	virtual void UpKey() = 0;
};

