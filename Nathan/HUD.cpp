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

void InitText(Texte** texte, Vec2 pos, const char* text)
{
	*texte = (Texte*)malloc(sizeof(Texte));

	TTF_Init();

	(*texte)->police = TTF_OpenFont("Fonts/8bit.ttf", 22);
	(*texte)->color = { 0, 0, 0 };
	(*texte)->texte = TTF_RenderText_Blended((*texte)->police, text, (*texte)->color);	
	(*texte)->textPos.x = pos.x;
	(*texte)->textPos.y = pos.y;
}

void DrawTexte(Texte* texte, SDL_Renderer* renderer)
{	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, texte->texte);

	SDL_QueryTexture(texture, NULL, NULL, &texte->textPos.w, &texte->textPos.h);
	SDL_RenderCopy(renderer, texture, NULL, &texte->textPos);

	SDL_DestroyTexture(texture);
}

void changeText(Texte* texte, const char* text)
{
	texte->texte = TTF_RenderText_Blended(texte->police, text, texte->color);
}