#include "Enemy.h"
#include "Player.h"
void InitEnemy(Enemy* enemy, SDL_Renderer* renderer)
{
	enemy->pEnemyTexture[0] = SDL_LoadTexture(renderer, "Sprites/croco_avant.bmp");
	enemy->pEnemyTexture[1] = SDL_LoadTexture(renderer, "Sprites/croco_arriere.bmp");
	enemy->pEnemyTexture[2] = SDL_LoadTexture(renderer, "Sprites/croco_droite.bmp");
	enemy->pEnemyTexture[3] = SDL_LoadTexture(renderer, "Sprites/croco_gauche.bmp");

	enemy->x = 500;
	enemy->y = 500;

	enemy->animationNum = 0;
}
void UpdateEnemy(Enemy* enemy, Player* player)
{
	
	
	if (player->pos.x -10> enemy->x)
	{
		enemy->x += 0.2;
		
	}
	else if (player->pos.x-10 < enemy->x)
	{
		enemy->x -= 0.2;
		
	}
	else
		enemy->animationNum = 2;
	if (player->pos.y-10 > enemy->y)
	{
		enemy->y += 0.2;
		//enemy->animationNum = 0;
	}
	else if (player->pos.y-10 < enemy->y)
	{
		enemy->y -= 0.2;
		//enemy->animationNum = 1;
	}
	else
		enemy->animationNum = 2;

	if  ((player->pos.y == enemy->y) && (player->pos.x > enemy->x))
		enemy->animationNum = 2;
	else if ((player->pos.y == enemy->y) && (player->pos.x < enemy->x))
	{
		enemy->animationNum = 3;
	}
	if ((player->pos.y == enemy->y) && (player->pos.x == enemy->x))
		enemy->animationNum = 2;



		
}
	void DrawEnemy(Enemy* enemy, SDL_Renderer* renderer)
	{
		SDL_Rect rect;
		rect.x = enemy->x;
		rect.y = enemy->y;
		rect.h = 32;
		rect.w = 32;

		SDL_RenderCopy(renderer, enemy->pEnemyTexture[enemy->animationNum], NULL, &rect);
	}