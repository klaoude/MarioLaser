#include <cmath>

#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include <SDL_ttf.h>

void InitLevel(Level* level, SDL_Renderer* renderer, const char* path)
{
	FILE* file = fopen(path, "r");
	
	char buff[255];
	fgets(buff, 255, file);
	level->w = (buff[0] - '0') * 10 + (buff[1] - '0');
	level->h = (buff[3] - 0x30) * 10 + (buff[4] - 0x30);

	level->levelTab = (unsigned char**)malloc(level->w*sizeof(char*));
	for (int i = 0; i < level->w; i++)
		level->levelTab[i] = (unsigned char*)malloc(level->h);

	for (int i = 0; i < level->w; i++)
	{
		fgets(buff, 255, file);
		for (int j = 0; j < level->h; j++)
		{
			switch (buff[j])
			{
			case 'W':
				level->levelTab[i][j] = 1;
				break;
			case '.':
				level->levelTab[i][j] = 0;
				break;
			case 'O':
				level->levelTab[i][j] = 2;
				break;
			case 'S':
				level->levelTab[i][j] = 3;
				break;

			default:
				level->levelTab[i][j] = 0;
				break;
			}
		}
	}

	level->pTextureAir = SDL_LoadTexture(renderer, "Sprites/fond.bmp");
	level->pTextureWall = SDL_LoadTexture(renderer, "Sprites/mur.bmp");
	level->pTextureEau[0] = SDL_LoadTexture(renderer, "Sprites/water.bmp");
	level->pTextureEau[1] = SDL_LoadTexture(renderer, "Sprites/water2.bmp");
	level->pTextureSable = SDL_LoadTexture(renderer, "Sprites/Sable.bmp");
}

void DrawLevel(Level* level, SDL_Renderer* renderer, Uint64 temps2)
{
	Uint64 temps = SDL_GetTicks();
	int flag ;
	if ((temps - temps2) < 1000)
	{

		flag = 1;
	}
	else if ((temps - temps2) < 2000)
		flag = 0;
	else
	{
		temps2 = temps;
		flag = 1;
	}

	for (int i = 0; i < level->w; i++)
		for (int j = 0; j < level->h; j++)
		{
			SDL_Rect rect;
			rect.x = j * 32;
			rect.y = i * 32;
			rect.h = 32;
			rect.w = 32;
			switch (level->levelTab[i][j])
			{
			case 0:
				SDL_RenderCopy(renderer, level->pTextureAir, NULL, &rect);
				break;
			case 1:
				SDL_RenderCopy(renderer, level->pTextureWall, NULL, &rect);
				break;
			case 2 : 
				SDL_RenderCopy(renderer, level->pTextureEau[flag], NULL, &rect);
				break;
			case 3:
				SDL_RenderCopy(renderer, level->pTextureSable, NULL, &rect);
				break;
			default:
				SDL_RenderCopy(renderer, level->pTextureAir, NULL, &rect);
				break;
			}
		}
}

bool CollideWithWorldP(Level* level, Player* player)
{
	if (level->levelTab[int(ceil(player->pos.y / 32))][int(ceil(player->pos.x / 32))] == 1 ||
		level->levelTab[int(ceil(player->pos.y / 32))][int(ceil(player->pos.x / 32))] == 2)
		return true;
	if (level->levelTab[int(floor(player->pos.y / 32))][int(floor(player->pos.x / 32))] == 1)
		return true;
	return false;
}

bool CollideWithWorldE(Level* level, Enemy* enemy)
{
	if (level->levelTab[int(ceil(enemy->pos.y / 32))][int(ceil(enemy->pos.x / 32))] == 1)
		return true;
	if (level->levelTab[int(floor(enemy->pos.y / 32))][int(floor(enemy->pos.x / 32))] == 1)
		return true;
	else
		return false;
}

char getCase(Level* level, int x, int y) 
{ 
	return level->levelTab[x][y]; 
}