#pragma once
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Sprite;

struct SpriteData 
{
	size_t width, height;
	uint8_t* data;
};
struct SpriteAnimation
{
	bool loop;
	size_t numFrames, frameDuration, time;
	SpriteData** frames;
};

class Sprite
{
public:
	SpriteData sData;
	SpriteAnimation anim;
};

