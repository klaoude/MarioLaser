#include <SDL.h>

#include "Player.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

SDL_Window* window;
SDL_GLContext glContext;
SDL_Renderer* renderer;

const char WINDOW_TITLE[] = "MarioLazer";

Player* player;

SDL_Texture* levelFond;

void initLevel()
{
	SDL_Surface* surf = SDL_LoadBMP("Sprites/fond.bmp");
	levelFond = SDL_CreateTextureFromSurface(renderer, surf);
}

void initSDL()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	glContext = SDL_GL_CreateContext(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	initLevel();

	player = (Player*)malloc(sizeof(Player));
	InitPlayer(player, renderer, {100, 100});
}

void update()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			exit(0);
			break;
		case SDL_KEYDOWN:
			UpdatePlayer(player, evnt.key.keysym.sym);
			break;
		}
	}
}

void drawLevel()
{
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
		{
			SDL_Rect rect;
			rect.x = i * 32;
			rect.y = j * 32;
			rect.h = 32;
			rect.w = 32;
			SDL_RenderCopy(renderer, levelFond, NULL, &rect);
		}
}

void draw()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);

	//draw
	drawLevel();
	DrawPlayer(player, renderer);

	SDL_RenderPresent(renderer);
}


void run()
{
	while (1)
	{
		update();
		draw();

		SDL_Delay(1);	
	}
}

void quitSDL()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char** argv)
{
	initSDL();

	run();

	quitSDL();

	return 0;
}

  