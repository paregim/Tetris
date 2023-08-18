#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

namespace ROTATE_DIR {
	enum dir
	{
		DEG_0, DEG_90, DEG_180, DEG_270, MAX_ROTATE
	};
}

enum class MOVE_DIR
{
	NO_DIR, LEFT, RIGHT, DOWN, MAX_DIR
};

enum class CMD_KEY
{
	ROTATE, LEFT, RIGHT, S_DROP, H_DROP, ROT180, HOLD, PAUSE
};

namespace TETROMINO {
	enum type {
		I, O, S, Z, J, L, T, MAX_TYPE
	};
}

struct Point
{
	int x, y;

	Point(int x_in = 0, int y_in = 0)
	{
		x = x_in;
		y = y_in;
	}

	Point operator + (Point& p)
	{
		return Point(this->x + p.x, this->y + p.y);
	}

	Point operator - (Point& p)
	{
		return Point(this->x - p.x, this->y - p.y);
	}

	friend ostream& operator << (ostream& out, Point& p)
	{
		out << p.x << ", " << p.y;
		return out;
	}
};

enum {
	black = 0,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

