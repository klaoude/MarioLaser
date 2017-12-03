#pragma once

#include <SDL.h>

typedef struct Player
{
	SDL_Texture* pPlayerTextures[4];
	float x, y;
	unsigned char animationNum = 0;
} Player;

void InitPlayer(Player* player, SDL_Renderer* renderer);
void UpdatePlayer(Player* player, SDL_Keycode keycode);
void DrawPlayer(Player* player, SDL_Renderer* renderer);