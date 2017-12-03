#pragma once

#include <SDL.h>

#include "Input.h"
#include "Utils.h"

typedef struct Player
{
	SDL_Texture* pPlayerTextures[4];
	Vec2 pos;
	unsigned char animationNum = 0;
	unsigned int speed;
} Player;

void InitPlayer(Player* player, SDL_Renderer* renderer);
void UpdatePlayer(Player* player, Input* input);
void DrawPlayer(Player* player, SDL_Renderer* renderer);