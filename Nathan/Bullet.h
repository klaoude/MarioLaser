#pragma once
#include <SDL.h>
#include "Utils.h"

typedef struct Bullet
{
	SDL_Texture* pBulletTexture;
	Vec2 bulletPos;
	double speed;
	Vec2 startPos;
	int dir;
}Bullet;

void DrawBullet(Bullet* bullet, SDL_Renderer* renderer);
bool UpdateBullet(Bullet* bullet, double deltaTime);
void InitBullet(Bullet* bullet, SDL_Renderer* renderer, int dir, Vec2 pos);