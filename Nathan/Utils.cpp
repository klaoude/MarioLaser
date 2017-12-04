#include "Utils.h"

SDL_Texture* SDL_LoadTexture(SDL_Renderer* renderer, const char* fileName)
{
	SDL_Surface* surf = SDL_LoadBMP(fileName);
	SDL_SetColorKey(surf, 1, SDL_MapRGB(surf->format, 255, 255, 255));
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	return text;
}

float dist(Vec2 a, Vec2 b)
{
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}