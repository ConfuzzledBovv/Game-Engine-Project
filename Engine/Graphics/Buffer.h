#pragma once
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Sprite.h"

struct BufferData
{
	size_t width, height;
	uint32_t* data;
};

class Buffer
{
public:
	Buffer(const size_t buffer_width = 224, const size_t buffer_height = 224);

	void Buffer_clear(BufferData* buffer, uint32_t color);
	uint32_t rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b);
	void Buffer_Texture();
	void buffer_draw_sprite(BufferData* buffer, const SpriteData& sprite, size_t x, size_t y, uint32_t color);

	BufferData buffer;
};

