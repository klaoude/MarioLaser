#pragma once

#include <SDL.h>

struct Bullet;

typedef struct Vec2
{
	float x, y;
} Vec2;

typedef struct File
{
	struct File* next;
	Bullet* value;
};

void pushFile(File** file, Bullet* bullet);
void delFile(File** file, Bullet* target);

SDL_Texture* SDL_LoadTexture(SDL_Renderer* renderer, const char* fileName);

float dist(Vec2 a, Vec2 b);