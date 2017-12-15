#include "Bullet.h"

void InitBullet(Bullet* bullet, Player* player, SDL_Renderer* renderer)
{
	bullet->pBulletTexture = SDL_LoadTexture(renderer, "Sprites/pierre.bmp");
	bullet->speed = 0.2f;


}

void UpdateBullet(Bullet* bullet, Player* player, Input* input)
{
	Vec2 startPos;
	startPos.x = 800;
	startPos.y = 600;
	bullet->down = 0;
	bullet->up = 0;
	bullet->right = 0;
	bullet->left = 0;
	if (input->space)
	{
		startPos = player->pos;
		bullet->bulletPos = startPos;
		bullet->bulletExist = true;
		
		switch (player->animationNum)
		{
		case 0:
			bullet->down = 1;
			break;
		case 1 :
			bullet->up = 1;
			break;
		case 2 :
			bullet->right = 1;
			break;
		case 3 :
			bullet->left = 1;
		
		}
	}
	
	if ((dist(startPos, bullet->bulletPos)) < (5 * 32))
	{
		if (bullet->down == 1)
			bullet->bulletPos.y += 0.2;
		else if (bullet->up == 1)
			bullet->bulletPos.y -= 0.2;
		else if (bullet->right == 1)
			bullet->bulletPos.x += 0.2;
		else if (bullet->left ==1)
			bullet->bulletPos.x -= 0.2;

	}
	else
	{
		bullet->bulletExist = false;
		bullet->down = 0;
		bullet->up = 0;
		bullet->left = 0;
		bullet->right = 0;
	}
}

void DrawBullet(Bullet* bullet, SDL_Renderer* renderer)
{
	if (bullet->bulletExist)
	{
		SDL_Rect rect;
		rect.x = bullet->bulletPos.x;
		rect.y = bullet->bulletPos.y;
		rect.h = 32;
		rect.w = 32;

		SDL_RenderCopy(renderer, bullet->pBulletTexture, NULL, &rect);
	}
}