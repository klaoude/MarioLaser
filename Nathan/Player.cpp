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

	player->pos.x = 100;
	player->pos.y = 100;

	player->speed = 5;

	player->animationNum = 0;
}

void UpdatePlayer(Player* player, Input* input)
{
	if (input->up)
	{
		player->pos.y -= player->speed;
	}
	else if (input->down)
	{
		player->pos.y += player->speed;
	}

	if (input->left)
	{
		player->pos.x -= player->speed;
	}
	else if (input->right)
	{
		player->pos.x += player->speed;
	}
}

void DrawPlayer(Player* player, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = player->pos.x;
	rect.y = player->pos.y;
	rect.h = 32;
	rect.w = 32;

	SDL_RenderCopy(renderer, player->pPlayerTextures[player->animationNum], NULL, &rect);
}