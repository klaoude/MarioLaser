#pragma once

#include <SDL.h>

#include "Input.h"
#include "Utils.h"
#include "Level.h"
#include "Bullet.h"

typedef struct Player
{
	SDL_Texture* pPlayerTextures[4];
	Vec2 pos;
	unsigned char animationNum = 0;
	double speed;
	unsigned char PlayerLife = 10;
	int vie = 10;	

	Uint32 temps;
} Player;


void InitPlayer(Player* player, SDL_Renderer* renderer);
void UpdatePlayer(Player* player, Input* input, File** bullets, Level* level, SDL_Renderer* renderer, double deltatime);
void DrawPlayer(Player* player, SDL_Renderer* renderer);