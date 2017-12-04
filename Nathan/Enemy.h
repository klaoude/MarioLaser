#pragma once

#include <SDL.h>
#include "Player.h"
#include "Utils.h"

typedef struct Enemy
{
	SDL_Texture* pEnemyTexture[4];
	Vec2 pos;
	unsigned char animationNum = 0;
	double speed;
} Enemy;

void InitEnemy(Enemy* enemy, SDL_Renderer* renderer, 
			   Vec2 pos);
void UpdateEnemy(Enemy* enemy,Player* player, 
				 Level* level, double deltatime);
void DrawEnemy(Enemy* enemy, SDL_Renderer* renderer);