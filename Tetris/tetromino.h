#pragma once
#include "seungtetris.h"
#include "util.h"

class Mino
{
public:
	const int color;
	const int size;		//ºí·Ï Ä­ °³¼ö
	const Point* shape[ROTATE_DIR::MAX_ROTATE];

	Mino()
		:color(0), size(0)
	{
		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++) shape[i] = nullptr;
	}

	Mino(int color_in, int size_in, const Point* deg0, const Point* deg90, const Point* deg180, const Point* deg270)
		:color(color_in), size(size_in)
	{
		shape[ROTATE_DIR::DEG_0] = deg0;
		shape[ROTATE_DIR::DEG_90] = deg90;
		shape[ROTATE_DIR::DEG_180] = deg180;
		shape[ROTATE_DIR::DEG_270] = deg270;
	}

	/*~Mino()
	{
		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++)
			if (shape[i] != nullptr) delete[] shape[i];
	}*/

	//void Draw(Point loc, int rotate) { for (int i = 0; i < size; i++) PutDot(loc + shape[rotate][i], color); }
};