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

	player->speed = 0.2f;

	player->animationNum = 0;

	player->temps = SDL_GetTicks();
}

void UpdatePlayer(Player* player, Input* input, File** bullets, Level* level, SDL_Renderer* renderer, double deltatime)
{
	if (input->up)
	{
		player->pos.y -= player->speed * deltatime;
		if(CollideWithWorldP(level, player))
			player->pos.y += player->speed * deltatime;

		player->animationNum = 1;
	}
	else if (input->down)
	{
		player->pos.y += player->speed * deltatime;
		if (CollideWithWorldP(level, player))
			player->pos.y -= player->speed * deltatime;
		player->animationNum = 0;
	}

	if (input->left)
	{
		player->pos.x -= player->speed * deltatime;
		if (CollideWithWorldP(level, player))
			player->pos.x += player->speed * deltatime;
		player->animationNum = 3;
	}
	else if (input->right)
	{
		player->pos.x += player->speed * deltatime;
		if (CollideWithWorldP(level, player))
			player->pos.x -= player->speed * deltatime;
		player->animationNum = 2;
	}

	if (input->space && (SDL_GetTicks() - player->temps) > 400)
	{
		player->temps = SDL_GetTicks();
		Bullet* bullet = (Bullet*)malloc(sizeof(Bullet));
		InitBullet(bullet, renderer, player->animationNum, player->pos);
		pushFile(bullets, bullet);			
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