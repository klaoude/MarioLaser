#include "Player.h"

void InitPlayer(Player* player, SDL_Renderer* renderer)
{
	SDL_Surface* surf = SDL_LoadBMP("Sprites/mario-bas.bmp");
	player->pPlayerTextures[0] = SDL_CreateTextureFromSurface(renderer, surf);

	surf = SDL_LoadBMP("Sprites/mario-haut.bmp");
	player->pPlayerTextures[1] = SDL_CreateTextureFromSurface(renderer, surf);

	surf = SDL_LoadBMP("Sprites/mario-droite.bmp");
	player->pPlayerTextures[2] = SDL_CreateTextureFromSurface(renderer, surf);

	surf = SDL_LoadBMP("Sprites/mario-gauche.bmp");
	player->pPlayerTextures[3] = SDL_CreateTextureFromSurface(renderer, surf);

	player->x = 100;
	player->y = 100;

	player->animationNum = 0;
}

void UpdatePlayer(Player* player, SDL_Keycode keycode)
{
	switch (keycode)
	{
	case SDLK_LEFT:
		player->x -= 10;
		player->animationNum = 3;
		break;
	case SDLK_RIGHT:
		player->x += 10;
		player->animationNum = 2;
		break;
	case SDLK_UP:
		player->y -= 10;
		player->animationNum = 1;
		break;
	case SDLK_DOWN:
		player->y += 10;
		player->animationNum = 0;
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

	SDL_RenderCopy(renderer, player->pPlayerTextures[player->animationNum], NULL, &rect);
}