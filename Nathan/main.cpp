#include <SDL.h>

#include "Player.h"
#include "Enemy.h"
#include "Level.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

SDL_Window* window;
SDL_GLContext glContext;
SDL_Renderer* renderer;

const char WINDOW_TITLE[] = "MarioLazer";

Player* player;
Enemy* enemy;
Input* input;

Level* level;

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

	player = (Player*)malloc(sizeof(Player));
	enemy = (Enemy*)malloc(sizeof(Enemy));
	input = (Input*)malloc(sizeof(Input));
	input->up = 0; input->down = 0; input->left = 0; input->right = 0; input->space = 0;
	level = (Level*)malloc(sizeof(Level));

	InitLevel(level, renderer, "Levels/level1");
	InitPlayer(player, renderer);
	InitEnemy(enemy, renderer);
}

void update()
{
	GetInput(input);

	UpdateEnemy(enemy, player);
	UpdatePlayer(player, input, level);
}

void draw()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);

	//draw
	DrawLevel(level, renderer);
	DrawPlayer(player, renderer);
	DrawEnemy(enemy, renderer);

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

  