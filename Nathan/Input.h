#pragma once

#include <SDL.h>

typedef struct Input
{
	unsigned char up, down, left, right, space;
} Input;

void GetInput(Input* input);