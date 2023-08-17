#include "util.h"

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

void PutDot(Point loc, int color = 0)
{
	Setcolor(16, color);
	GotoCursor(loc);
	cout << "  ";
}