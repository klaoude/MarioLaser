#pragma once

#include <SDL.h>

typedef struct Vec2
{
	float x, y;
} Vec2;

SDL_Texture* SDL_LoadTexture(SDL_Renderer* renderer, const char* fileName);

float dist(Vec2 a, Vec2 b);