#include "util.h"
#include "inc.h"

void init()
{
	char cmd[128];
	sprintf_s(cmd, "mode con cols=%d lines=%d | title 테 트 리 스", (game_config.x_wall_size + (game_config.wall_corner.x * 2)) * 2, game_config.y_wall_size + (game_config.wall_corner.y * 2) + 1);
	system(cmd);

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void Setcolor(int f_color, int b_color)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = f_color + b_color * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void GotoCursor(Point loc)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = loc.x * 2;
	pos.Y = loc.y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void GotoCursor(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void PutDot(Point loc, int color = 0)
{
	Setcolor(15, color);
	if (loc.x >= 0 && loc.y >= 0)
	{
		GotoCursor(loc);
		cout << "  ";
	}
}

void PutDot(int x, int y, int color = 0)
{
	Setcolor(15, color);
	GotoCursor(x, y);
	cout << "  ";
}