#pragma once

#include <cstdio>
#include <cstdlib>

#include "Utils.h"

typedef struct Level
{
	unsigned char** levelTab;
	unsigned int w, h;

	SDL_Texture* pTextureWall;
	SDL_Texture* pTextureAir;
	SDL_Texture* pTextureEau;
	SDL_Texture* pTextureSable;
} Level;

void InitLevel(Level* level, SDL_Renderer* renderer, const char* path);
void DrawLevel(Level* level, SDL_Renderer* renderer);

bool CollideWithWorld(Level* level, struct Player* player);