#pragma once
#include "Games.h"
#include "Bullet.h"


struct SpaceInvadersVariables
{
	Alien alien_sprite;
	SpriteData player_sprite;
	int player_move_dir;
	int maxBullets = 128;
	int totalBullets = 0;
	uint8_t* deathCounters;
};

class SpaceInvadersGame :
	public Games
{
private:
	SpaceInvadersVariables spaceVariables;

public:
	SpaceInvadersGame(Buffer _buffer);
	int maxBullets;
	void RunGame();
	size_t width, height;
	size_t num_aliens;
	Alien* aliens;
	Character player;
	Bullet bullets[128];
	/// This is for the window game loop ONLY
	void GameLoop();

	void LeftKey();
	void RightKey();
	void LeftRightKeyReleased();
	void UpKey();

private:
	void DrawPlayerAndAliens();
	void DeathCounter();
	void DrawBullets();
	void PlayerMovement();
	void UpdateAlienAnimation();
	void MoveAndDeleteBullet();

	bool SpriteOverlapCheck(const Sprite& spriteA, size_t xA, size_t yA, const SpriteData spriteB, size_t xB, size_t yB);
};

