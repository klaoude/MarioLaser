#include "Player.h"

void InitPlayer(Player* player, SDL_Renderer* renderer, Vec2 pos)
{
	SDL_Surface* surf = SDL_LoadBMP("Sprites/mario-bas.bmp");
	player->pPlayerTexture = SDL_CreateTextureFromSurface(renderer, surf);

	player->pos = pos;
}

void UpdatePlayer(Player* player, SDL_Keycode keycode)
{
	if(keycode == SDLK_LEFT)
		player->pos.x -= 10;
	else if(keycode == SDLK_RIGHT)
		player->pos.x += 10;
	if(keycode == SDLK_UP)
		player->pos.y -= 10;
	else if(keycode == SDLK_DOWN)
		player->pos.y += 10;
}

void DrawPlayer(Player* player, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = player->pos.x;
	rect.y = player->pos.y;
	rect.h = 32;
	rect.w = 32;

	SDL_RenderCopy(renderer, player->pPlayerTexture, NULL, &rect);
}