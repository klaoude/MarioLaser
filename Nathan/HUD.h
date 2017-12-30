#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Player.h"

typedef struct Vie
{
	SDL_Texture* pVieTexture;
	Vec2 viePos;
	int PointVie;
}Vie;

typedef struct Texte
{
	SDL_Surface* texteVie = NULL, *fond = NULL;
	TTF_Font* police = NULL;
	SDL_Rect* textPos;
	SDL_Color couleurNoire;
} Texte;

void InitVie(Vie* vie, SDL_Renderer* renderer);
void DrawVie(Vie* vie, SDL_Renderer* renderer);
void InitText(Texte* texte);
void DrawTexte(Texte* texte, SDL_Renderer* renderer);

