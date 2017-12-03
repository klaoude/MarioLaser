#pragma once

#include <SDL.h>
#include "Player.h"

typedef struct Enemy
{
	SDL_Texture* pEnemyTexture[4];
	float x, y;
	unsigned char animationNum = 0;
} Enemy;

void InitEnemy(Enemy* enemy, SDL_Renderer* renderer);
void UpdateEnemy(Enemy* enemy,Player* player);
void DrawEnemy(Enemy* enemy, SDL_Renderer* renderer);