#include "Menu.h"

void menu(SDL_Renderer* renderer)
{
	
	SDL_Texture* pFondMenu = SDL_LoadTexture(renderer, "Sprites/mario_vs_croco.bmp");
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 600;
	rect.w = 800;
	SDL_RenderCopy(renderer, pFondMenu, NULL, &rect);
	SDL_Delay(4000);
}