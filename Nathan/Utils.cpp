#include "Utils.h"
#include "Bullet.h"

SDL_Texture* SDL_LoadTexture(SDL_Renderer* renderer, const char* fileName)
{
	SDL_Surface* surf = SDL_LoadBMP(fileName);
	SDL_SetColorKey(surf, 1, SDL_MapRGB(surf->format, 255, 255, 255));
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	return text;
}

float dist(Vec2 a, Vec2 b)
{
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

void pushFile(File** file, Bullet* bullet)
{
	File* nouv = (File*)malloc(sizeof(File));
	nouv->value = bullet;
	nouv->next = *file;
	*file = nouv;
}

void delFile(File** file, Bullet* target)
{
	File* tmp = *file;
	File* prev;

	if (tmp == NULL)
		return;

	if (tmp->next == NULL && tmp->value == target)
	{
		*file = NULL;
		free(tmp);
		return;
	}
	
	while (tmp->next != NULL)
	{
		if (tmp->next->value == target)
		{
			prev = tmp;
			File* suivant = tmp->next->next;
			prev->next = suivant;
			free(tmp->next);
			return;
		}
		tmp = tmp->next;
	}
}