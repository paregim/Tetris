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
};