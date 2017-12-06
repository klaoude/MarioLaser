#pragma once
#include <SDL.h>
#include "Player.h"
#include "Utils.h"
#include "Level.h"


typedef struct Bullet
{
	SDL_Texture* pBulletTexture;
	unsigned char up, down, left, right;
	Vec2 bulletPos;
	double speed;
	bool bulletExist;
}Bullet;

void DrawBullet(Bullet* bullet, SDL_Renderer* renderer);
void UpdateBullet(Bullet* bullet, Player* player, Input* input);
void InitBullet(Bullet* bullet, Player* player, SDL_Renderer* renderer);