#include <SDL.h>
#include <SDL_ttf.h>
#include <time.h>
#include <string.h>

#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include "Bullet.h"
#include "Menu.h"
#include "HUD.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

#define NUM_ENEMY 4

SDL_Window* window;
SDL_GLContext glContext;
SDL_Renderer* renderer;
Uint64 temps2 = 0;

const char WINDOW_TITLE[] = "MarioLazer";

Player* player;
Enemy** enemy; //tableau de pointeur vers enemy
Input* input;
File* bullets;
Vie* vie;
Texte* textVie, *textScore, *textLevel;
Level* level;

unsigned int score = 0;
unsigned int levelNum = 1;

void spawnEnemies()
{
	srand(time(NULL));

	float x, y;
	for (int i = 0; i < levelNum; i++)
	{
		do
		{
			x = rand() % (level->w - 2);
			y = rand() % (level->h - 2);
		} while (getCase(level, (int)x, (int)y) != 0);//si zero case de vide
		InitEnemy(enemy[i], renderer, { y * 32.f, x *32.f }, levelNum);
	}		
}

//init SDL and init all object
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
}

//quit
void quitSDL()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void init()
{
	player = (Player*)malloc(sizeof(Player));
	enemy = (Enemy**)malloc(sizeof(Enemy*) * levelNum);
	for (int i = 0; i < levelNum; i++)
		enemy[i] = (Enemy*)malloc(sizeof(Enemy));
	input = (Input*)malloc(sizeof(Input));
	input->up = 0; input->down = 0; input->left = 0; input->right = 0; input->space = 0;
	level = (Level*)malloc(sizeof(Level));
	vie = (Vie*)malloc(sizeof(Vie));

	InitLevel(level, renderer, "Levels/level1");
	InitPlayer(player, renderer);
	
	spawnEnemies();

	InitVie(vie, renderer);
	InitText(&textVie, { 140, 3 }, "Vie");
	InitText(&textScore, { 600, 3 }, "Score 0");
	InitText(&textLevel, { 600, 30 }, "Level 1");
}

//update all bullets
void updateAllBullets(double deltaTime)
{
	File* tmp = bullets;//pointeur sur 
	while (tmp != NULL && tmp != (File*)0xdddddddd)//parcour toute la pile de bas en haut
	{
		if (!UpdateBullet(tmp->value, deltaTime))
		{
			delFile(&bullets, tmp->value);
			tmp = tmp->next;//fait pointer vers la bullet suivante
			break;
		}

		for (int i = 0; i < levelNum; i++)
			if (enemy[i] != NULL && CheckColl(enemy[i], tmp->value))
			{
				free(enemy[i]);
				enemy[i] = NULL;
				score++;
				char scoreStr[5];//chaine caractere avec valeur du score
				sprintf(scoreStr, "%d", score + levelNum * (levelNum - 1) / 2);
				char totalScore[11] = "Score ";
				strcat(totalScore, scoreStr);//fusionne
				changeText(textScore, totalScore);
			}

		tmp = tmp->next;
	}

	if (score >= levelNum)
	{	
		free(enemy);

		score = 0;
		levelNum++;

		char levelStr[3];
		sprintf(levelStr, "%d", levelNum);
		char tmp[9] = "Level ";
		strcat(tmp, levelStr);
		changeText(textLevel, tmp);

		enemy = (Enemy**)malloc(levelNum * sizeof(Enemy*));//aloue le tableau pour un ennemie sup
		for (int i = 0; i < levelNum; i++)
			enemy[i] = (Enemy*)malloc(sizeof(Enemy));

		spawnEnemies();
	}
}

void gameOver()
{
	for (int i = 0; i < 100; i++)
	{
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderClear(renderer);
			
		DrawLevel(level, renderer, temps2);
		DrawPlayer(player, renderer);

		for (int i = 0; i < levelNum; i++)
			if (enemy[i] != NULL)
				DrawEnemy(enemy[i], renderer);

		DrawVie(vie, renderer);
		DrawTexte(textVie, renderer);
		DrawTexte(textScore, renderer);
		DrawTexte(textLevel, renderer);

		SDL_Texture* gameOvertexture = SDL_LoadTexture(renderer, "Sprites/gameOver.bmp");
		SDL_Rect rect;
		rect.w = i*800/100;
		rect.h = i*600/100;
		rect.x = 400-rect.w/2;
		rect.y = 300-rect.h/2;

		SDL_RenderCopy(renderer, gameOvertexture, NULL, &rect);
		SDL_DestroyTexture(gameOvertexture);

		SDL_RenderPresent(renderer);

		SDL_Delay(50);
	}		

	quitSDL();
	exit(0);
}

//update all object
void update(double deltatime)
{
	GetInput(input);

	for (int i = 0; i < levelNum; i++)
		if (enemy[i] != NULL)
			UpdateEnemy(enemy[i], player, level, deltatime, vie);

	UpdatePlayer(player, input, &bullets, level, renderer, deltatime);
	updateAllBullets(deltatime);

	if (vie->PointVie <= 0)
		gameOver();
}

//draw all bullets
void drawAllBullets()
{
	File* tmp = bullets;
	while (tmp != NULL)//jusqua qu'in sois arriver en haut
	{
		DrawBullet(tmp->value, renderer);
		tmp = tmp->next;
	}
}

//draw all object
void draw()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);

	//draw
	DrawLevel(level, renderer, temps2);
	DrawPlayer(player, renderer);

	for (int i = 0; i < levelNum; i++)
		if(enemy[i] != NULL)
			DrawEnemy(enemy[i], renderer);

	drawAllBullets();
	DrawVie(vie, renderer);
	DrawTexte(textVie, renderer);
	DrawTexte(textScore, renderer);
	DrawTexte(textLevel, renderer);

	SDL_RenderPresent(renderer);
}

//main loop
void run()
{
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	while (1)
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / SDL_GetPerformanceFrequency());//gere en fonction du frame rate

		update(deltaTime);
		draw();

		SDL_Delay(1);	
	}
}

int main(int argc, char** argv)
{
	initSDL();
	
	menu(renderer);

	init();

	run();

	quitSDL();

	return 0;
}