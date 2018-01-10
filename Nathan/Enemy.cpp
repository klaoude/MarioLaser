#include "Enemy.h"
#include "Player.h"
#include "Utils.h"
#include "HUD.h"

//init enemy pos and textures
void InitEnemy(Enemy* enemy, SDL_Renderer* renderer, Vec2 pos, int levelNum)
{
	enemy->pEnemyTexture[0] 
		= SDL_LoadTexture(renderer, "Sprites/croco_avant.bmp");
	enemy->pEnemyTexture[1] 
		= SDL_LoadTexture(renderer, "Sprites/croco_arriere.bmp");
	enemy->pEnemyTexture[2] 
		= SDL_LoadTexture(renderer, "Sprites/croco_droite.bmp");
	enemy->pEnemyTexture[3] 
		= SDL_LoadTexture(renderer, "Sprites/croco_gauche.bmp");

	enemy->pos = pos;

	enemy->speed = 0.05f + levelNum * 0.01f;//auggmente spped en fonction level

	enemy->animationNum = 0;
}

void UpdateEnemy(Enemy* enemy, Player* player, Level* level, double deltatime, Vie* vie)
{
	if (dist(player->pos, enemy->pos) < 150)
	{
		if (player->pos.x > enemy->pos.x)
		{
			enemy->pos.x += enemy->speed * deltatime;
			if (CollideWithWorldE(level, enemy))
				enemy->pos.x -= enemy->speed * deltatime;
		}
		else
		{
			enemy->pos.x -= enemy->speed * deltatime;
			if (CollideWithWorldE(level, enemy))
				enemy->pos.x += enemy->speed * deltatime;
		}

		if (player->pos.y > enemy->pos.y)
		{
			enemy->pos.y += enemy->speed * deltatime;
			if (CollideWithWorldE(level, enemy))
				enemy->pos.y -= enemy->speed * deltatime;
			enemy->animationNum = 0;
		}
		else
		{
			enemy->pos.y -= enemy->speed * deltatime;
			if (CollideWithWorldE(level, enemy))
				enemy->pos.y += enemy->speed * deltatime;
			enemy->animationNum = 1;
		}
		if ((player->pos.y == enemy->pos.y) &&
			(player->pos.x > enemy->pos.x))
			enemy->animationNum = 2;
		else if ((player->pos.y == enemy->pos.y) &&
			(player->pos.x < enemy->pos.x))
		{
			enemy->animationNum = 3;
		}
		if (dist(player->pos, enemy->pos) < 10)
		{
			vie->PointVie -= 1;
		}
	}
}

void DrawEnemy(Enemy* enemy, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = enemy->pos.x;
	rect.y = enemy->pos.y;
	rect.h = 64;
	rect.w = 64;

	SDL_RenderCopy(renderer,
				   enemy->pEnemyTexture[enemy->animationNum], 
				   NULL, 
				   &rect);
}

unsigned char CheckColl(Enemy* enemy, Bullet* bullet)
{
	return dist(enemy->pos, bullet->bulletPos) < 10;
}