#pragma once

#include <SDL.h>

typedef struct Player
{
	SDL_Texture* pPlayerTexture;
	float x, y;
} Player;

void InitPlayer(Player* player, SDL_Renderer* renderer);
void UpdatePlayer(Player* player, SDL_Keycode keycode);
void DrawPlayer(Player* player, SDL_Renderer* renderer);