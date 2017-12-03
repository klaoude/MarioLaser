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
} Level;

void InitLevel(Level* level, SDL_Renderer* renderer, const char* path);
void DrawLevel(Level* level, SDL_Renderer* renderer);