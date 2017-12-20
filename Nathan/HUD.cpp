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
	texte->police = TTF_OpenFont("8bit.ttf", 65);
	texte->couleurNoire = { 0, 0, 0 };
}

void DrawTexte(Texte* texte)
{
	texte->texte = TTF_RenderText_Blended(texte->police, "Vie", texte->couleurNoire);
	SDL_FillRect(texte->ecran, NULL, SDL_MapRGB(texte->ecran->format, 255, 255, 255));
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	SDL_BlitSurface(texte->fond, NULL, texte->ecran, &rect); /* Blit du fond */

	rect.x = 180;
	rect.y = 8;
	SDL_BlitSurface(texte->fond, NULL, texte->ecran, &rect); /* Blit du texte */
}



