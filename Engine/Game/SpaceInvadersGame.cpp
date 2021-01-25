#include "SpaceInvadersGame.h"

SpaceInvadersVariables spaceVariables;

SpaceInvadersGame::SpaceInvadersGame(Buffer _buffer)
{
	gameName = "Space Invaders";
	buffer = _buffer;
}

void SpaceInvadersGame::RunGame()
{
	//spaceVariables.alien_sprite.alienOne.sData.width = 11;
	//spaceVariables.alien_sprite.alienOne.sData.height = 8;

	spaceVariables.player_sprite.width = 11;
	spaceVariables.player_sprite.height = 7;
	spaceVariables.player_sprite.data = new uint8_t[77]
	{
		0,0,0,0,0,1,0,0,0,0,0, // .....@.....
		0,0,0,0,1,1,1,0,0,0,0, // ....@@@....
		0,0,0,0,1,1,1,0,0,0,0, // ....@@@....
		0,1,1,1,1,1,1,1,1,1,0, // .@@@@@@@@@.
		1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
		1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
		1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
	};

	width = buffer.buffer.width;
	height = buffer.buffer.height;
	num_aliens = 55;
	aliens = new Alien[num_aliens];
	player.x = 107;
	player.y = 32;
	player.life = 3;


	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 11; x++)
		{
			Alien& alien = aliens[y * 11 + x];
			alien.type = (3 - y) / 2 + 1;

			const Sprite& sprite = aliens->arrayOfAliens[(alien.type - 1)];
			alien.x = 16 * x + 20 + (aliens->alienDeath.sData.width - sprite.sData.width);
			alien.y = 17 * y + 128;
		}
	}

	spaceVariables.deathCounters = new uint8_t[num_aliens];
	for (size_t i = 0; i < num_aliens; i++)
	{
		spaceVariables.deathCounters[i] = 10;
	}

	spaceVariables.player_move_dir = 0;
}

void SpaceInvadersGame::GameLoop()
{
	buffer.Buffer_clear(&buffer.buffer, buffer.rgb_to_uint32(0, 128, 0));

	DrawPlayerAndAliens();

	DeathCounter();

	DrawBullets();

	PlayerMovement();

	UpdateAlienAnimation();

	MoveAndDeleteBullet();
}

void SpaceInvadersGame::LeftKey()
{
	spaceVariables.player_move_dir -= 1;
}

void SpaceInvadersGame::RightKey()
{
	spaceVariables.player_move_dir += 1;
}

void SpaceInvadersGame::LeftRightKeyReleased()
{
	spaceVariables.player_move_dir = 0;
}

void SpaceInvadersGame::UpKey()
{
	if (spaceVariables.totalBullets < spaceVariables.maxBullets)
	{
		bullets[spaceVariables.totalBullets].x = player.x + spaceVariables.player_sprite.width / 2;
		bullets[spaceVariables.totalBullets].y = player.y + spaceVariables.player_sprite.height;
		bullets[spaceVariables.totalBullets].dir = 2;
		spaceVariables.totalBullets++;
	}

}

void SpaceInvadersGame::DrawPlayerAndAliens()
{
	for (size_t i = 0; i < num_aliens; i++)
	{

		if (!spaceVariables.deathCounters[i]) continue;

		Alien& alien = aliens[i];
		if (alien.type == ALIEN_DEAD)
		{
			buffer.buffer_draw_sprite(&buffer.buffer, alien.alienDeath_1, alien.x, alien.y, buffer.rgb_to_uint32(128, 0, 0));			
		}
		else
		{
			Sprite& animation = aliens->arrayOfAliens[alien.type];
			size_t current_frame = animation.anim.time / animation.anim.frameDuration;
			const SpriteData& draw = *animation.anim.frames[current_frame];
			buffer.buffer_draw_sprite(&buffer.buffer, draw, alien.x, alien.y, buffer.rgb_to_uint32(128, 0, 0));
		}
	}

	buffer.buffer_draw_sprite(&buffer.buffer, spaceVariables.player_sprite, player.x, player.y, buffer.rgb_to_uint32(128, 0, 0));
}

void SpaceInvadersGame::DeathCounter()
{
	for (size_t ai = 0; ai < num_aliens; ++ai)
	{
		const Alien& alien = aliens[ai];
		if (alien.type == ALIEN_DEAD && spaceVariables.deathCounters[ai])
		{
			spaceVariables.deathCounters[ai]--;
		}
	}
}

void SpaceInvadersGame::DrawBullets()
{
	for (size_t i = 0; i < spaceVariables.totalBullets; i++)
	{
		const Bullet& bullet = bullets[i];
		const Sprite& sprite = bullet.sprite;
		buffer.buffer_draw_sprite(&buffer.buffer, sprite.sData, bullet.x, bullet.y, buffer.rgb_to_uint32(128, 0, 0));
	}
}



void SpaceInvadersGame::PlayerMovement()
{
	int player_move_dir = 2 * spaceVariables.player_move_dir;

	if (player_move_dir != 0)
	{
		if (player.x + spaceVariables.player_sprite.width + player_move_dir >= width)
		{
			player.x = width - spaceVariables.player_sprite.width;
		}
		else if ((int)player.x + player_move_dir <= 0)
		{
			player.x = 0;
		}
		else player.x += player_move_dir;
	}
}

void SpaceInvadersGame::UpdateAlienAnimation()
{
	for (size_t i = 0; i < 3; i++)
	{
		aliens->arrayOfAliens[i].anim.time++;
		if (aliens->arrayOfAliens[i].anim.time == aliens->arrayOfAliens[i].anim.numFrames * aliens->arrayOfAliens[i].anim.frameDuration)
		{
			aliens->arrayOfAliens[i].anim.time = 0;
		}
	}
}

void SpaceInvadersGame::MoveAndDeleteBullet()
{
	for (size_t i = 0; i < spaceVariables.totalBullets; i++)
	{
		bullets[i].y += bullets[i].dir;
		if (bullets[i].y >= height || bullets[i].y < bullets->sprite.sData.height)
		{
			bullets[i] = bullets[spaceVariables.totalBullets - 1];
			spaceVariables.totalBullets--;
		}

		for (size_t j = 0; j < num_aliens; j++)
		{
			const Alien& alien = aliens[i];
			if (alien.type == ALIEN_DEAD) continue;

			const Sprite& animation = aliens->arrayOfAliens[alien.type];
			size_t current_frame = animation.anim.time / animation.anim.frameDuration;
			const SpriteData& alien_sprite = *animation.anim.frames[current_frame];
			bool overlap = SpriteOverlapCheck(
				bullets->sprite, bullets[i].x, bullets[i].y,
				alien_sprite, alien.x, alien.y);
			if (overlap)
			{
				aliens[j].type = ALIEN_DEAD;
				aliens[j].x -= (aliens->alienDeath.sData.width - alien_sprite.width) / 2;
				bullets[i] = bullets[spaceVariables.totalBullets - 1];
				spaceVariables.totalBullets--;
				continue;
			}
		}

	}
}

bool SpaceInvadersGame::SpriteOverlapCheck(const Sprite & spriteA, size_t xA, size_t yA, const SpriteData spriteB, size_t xB, size_t yB)
{
	if (xA < xB + spriteB.width && xA + spriteA.sData.width > xB &&
		yA < yB + spriteB.height && yA + spriteA.sData.height > yB)
	{
		return true;
	}
	return false;
}
