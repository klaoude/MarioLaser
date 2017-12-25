#include "Bullet.h"

//init bullet pos and texture
void InitBullet(Bullet* bullet, SDL_Renderer* renderer, int dir, Vec2 pos)
{
	bullet->pBulletTexture = SDL_LoadTexture(renderer, "Sprites/pierre.bmp");
	bullet->speed = 0.2f;
	bullet->startPos = pos;
	bullet->bulletPos = pos;
	bullet->dir = dir;
}

//update a bullet
//return true if exist
//return false if must be destroy
bool UpdateBullet(Bullet* bullet , double deltaTime)
{	
	if ((dist(bullet->startPos, bullet->bulletPos)) < (5 * 32))
	{
		switch (bullet->dir)
		{
		case 0:
			bullet->bulletPos.y += bullet->speed * deltaTime;
			break;
		case 1:
			bullet->bulletPos.y -= bullet->speed * deltaTime;
			break;
		case 2:
			bullet->bulletPos.x += bullet->speed * deltaTime;
			break;
		case 3:
			bullet->bulletPos.x -= bullet->speed * deltaTime;
			break;
		}
		return true;
	}
	else
		return false;
}

void DrawBullet(Bullet* bullet, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = bullet->bulletPos.x;
	rect.y = bullet->bulletPos.y;
	rect.h = 16;
	rect.w = 16;

	SDL_RenderCopy(renderer, bullet->pBulletTexture, NULL, &rect);
}