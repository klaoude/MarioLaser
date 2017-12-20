#include "Menu.h"

void menu(SDL_Renderer* renderer)
{
	
	SDL_Texture* pFondMenu = SDL_LoadTexture(renderer, "Sprites/Menu.bmp");
	SDL_Texture* pFleche = SDL_LoadTexture(renderer, "Sprites/Bowser.bmp");
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 600;
	rect.w = 800; 
	int pointeur=1;
	int validation = 0;
	while (1)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				pointeur = 1;
				break;
			case SDLK_DOWN:
				pointeur = 0;
				break;
			case SDLK_RETURN:
				validation = 1;
				break;


			}
		}

		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, pFondMenu, NULL, &rect);
		if (pointeur == 1)
		{
			SDL_Rect rect2;
			rect2.x = 40;
			rect2.y = 200;
			rect2.h = 32;
			rect2.w = 32;
			SDL_RenderCopy(renderer, pFleche, NULL, &rect2);
		}
		else if (pointeur == 0)
		{
			SDL_Rect rect2;
			rect2.x = 40; 
			rect2.y = 313;
			rect2.h = 32;
			rect2.w = 32;
			SDL_RenderCopy(renderer, pFleche, NULL, &rect2);
		}
		if (validation == 1)
		{
			if (pointeur == 1)
			{
				return;
			}
			else if (pointeur == 0)
			{
				exit(1);
			}
		}

		SDL_RenderPresent(renderer);
	}

}