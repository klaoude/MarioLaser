#include "Player.h"

void InitPlayer(Player* player, SDL_Renderer* renderer)
{
	SDL_Surface* surf = SDL_LoadBMP("Sprites/mario-bas.bmp");
	player->pPlayerTexture = SDL_CreateTextureFromSurface(renderer, surf);

	player->x = 100;
	player->y = 100;
}

void UpdatePlayer(Player* player, SDL_Keycode keycode)
{
	switch (keycode)
	{
	case SDLK_LEFT:
		player->x -= 10;
		break;
	case SDLK_RIGHT:
		player->x += 10;
		break;
	case SDLK_UP:
		player->y -= 10;
		break;
	case SDLK_DOWN:
		player->y += 10;
		break;
	}
}

void DrawPlayer(Player* player, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = player->x;
	rect.y = player->y;
	rect.h = 32;
	rect.w = 32;

	SDL_RenderCopy(renderer, player->pPlayerTexture, NULL, &rect);
}