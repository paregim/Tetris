#pragma once
#include "seungtetris.h"
#include "game_config.h"

void Setcolor(int f_color, int b_color);
void GotoCursor(Point loc);
void GotoCursor(int x, int y);
void PutDot(Point loc, int color);
void PutDot(int x, int y, int color);