#pragma once

#include <SDL.h>

#include "Input.h"
#include "Utils.h"
#include "Level.h"

typedef struct Player
{
	SDL_Texture* pPlayerTextures[4];
	Vec2 pos;
	unsigned char animationNum = 0;
	double speed;
} Player;

typedef struct InfoPlayer
{
	unsigned char PlayerLife = 10;
};

void InitPlayer(Player* player, SDL_Renderer* renderer);
void UpdatePlayer(Player* player, Input* input, Level* level, double deltatime);
void DrawPlayer(Player* player, SDL_Renderer* renderer);