#include "Enemy.h"
#include "Player.h"
void InitEnemy(Enemy* enemy, SDL_Renderer* renderer)
{
	SDL_Surface* surf = SDL_LoadBMP("Sprites/croco_avant.bmp");
	enemy->pEnemyTexture[0] = SDL_CreateTextureFromSurface(renderer, surf);

 	surf = SDL_LoadBMP("Sprites/croco_arriere.bmp");
	enemy->pEnemyTexture[1] = SDL_CreateTextureFromSurface(renderer, surf);

	surf = SDL_LoadBMP("Sprites/croco_droite.bmp");
	enemy->pEnemyTexture[2] = SDL_CreateTextureFromSurface(renderer, surf);

	surf = SDL_LoadBMP("Sprites/croco_gauche.bmp");
	enemy->pEnemyTexture[3] = SDL_CreateTextureFromSurface(renderer, surf);

	enemy->x = 500;
	enemy->y = 500;

	enemy->animationNum = 0;
}
void UpdateEnemy(Enemy* enemy, Player* player)
{
	if (player->x > enemy->x)
	{
		enemy->x += 0.2;
		
	}
	else
	{
		enemy->x -= 0.2;
		
	}
	if (player->y > enemy->y)
	{
		enemy->y += 0.2;
		enemy->animationNum = 0;
	}
	else
	{
		enemy->y -= 0.2;
		enemy->animationNum = 1;
	}
	if  ((player->y == enemy->y) && (player->x > enemy->x))
		enemy->animationNum = 2;
	else if ((player->y == enemy->y) && (player->x < enemy->x))
	{
		enemy->animationNum = 3;
	}


		
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