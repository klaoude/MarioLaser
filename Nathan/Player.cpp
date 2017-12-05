#include "Player.h"

#include "Level.h"

void InitPlayer(Player* player, SDL_Renderer* renderer)
{
	player->pPlayerTextures[0] = SDL_LoadTexture(renderer, "Sprites/mario-bas.bmp");
	player->pPlayerTextures[1] = SDL_LoadTexture(renderer, "Sprites/mario-haut.bmp");
	player->pPlayerTextures[2] = SDL_LoadTexture(renderer, "Sprites/mario-droite.bmp");
	player->pPlayerTextures[3] = SDL_LoadTexture(renderer, "Sprites/mario-gauche.bmp");

	player->pos.x = 100;
	player->pos.y = 100;

	player->speed = 5;

	player->animationNum = 0;
}

void UpdatePlayer(Player* player, Input* input, Level* level)
{
	if (input->up)
	{
		player->pos.y -= player->speed;
		if(CollideWithWorld(level, player)==true)
			player->pos.y += player->speed;

		player->animationNum = 1;
	}
	else if (input->down)
	{
		player->pos.y += player->speed;
		if (CollideWithWorld(level, player)==true)
			player->pos.y -= player->speed;
		player->animationNum = 0;
	}

	if (input->left)
	{
		player->pos.x -= player->speed;
		if (CollideWithWorld(level, player)==true)
			player->pos.x += player->speed;
		player->animationNum = 3;
	}
	else if (input->right)
	{
		player->pos.x += player->speed;
		if (CollideWithWorld(level, player)==true)
			player->pos.x -= player->speed;
		player->animationNum = 2;
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