#include "HUD.h"

void InitVie(Vie* vie, SDL_Renderer* renderer)
{
	vie->pVieTexture = SDL_LoadTexture(renderer, "Sprites/vie.bmp");
	vie->viePos.x = 200;
	vie->viePos.y =8;
	vie->PointVie = 400;
}

void DrawVie(Vie* vie, SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = vie->viePos.x;
	rect.y = vie->viePos.y;
	rect.h = 16;
	rect.w = vie->PointVie;

	SDL_RenderCopy(renderer, vie->pVieTexture, NULL, &rect);
}

void InitText(Texte* texte)
{
	TTF_Init();
	texte->police = TTF_OpenFont("Fonts/8bit.ttf", 22);
	texte->couleurNoire = { 0, 0, 0 };
	texte->texte = TTF_RenderText_Blended(texte->police, "Vie", texte->couleurNoire);
}

void DrawTexte(Texte* texte, SDL_Renderer* renderer)
{	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, texte->texte);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	//SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	//SDL_RenderCopy(renderer, texture, NULL, &rect);

	rect.x = 140;
	rect.y =3;
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(renderer, texture, NULL, &rect);

	SDL_DestroyTexture(texture);
}



