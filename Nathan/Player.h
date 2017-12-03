#pragma once

#include <SDL.h>

typedef struct Vec2
{
	int x, y;
} Vec2;

typedef struct Player
{
	SDL_Texture* pPlayerTexture;
	Vec2 pos;
} Player;

void InitPlayer(Player* player, SDL_Renderer* renderer, Vec2 pos);
void UpdatePlayer(Player* player, SDL_Keycode keycode);
void DrawPlayer(Player* player, SDL_Renderer* renderer);