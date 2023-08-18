#pragma once
#include "seungtetris.h"
#include "util.h"

class Mino
{
public:
	int color;
	int size;		//ºí·Ï Ä­ °³¼ö
	Point** shape;

	Mino()
	{
		color = 0;
		size = 0;
		shape = new Point * [1];
		shape[0] = nullptr;
	}

	Mino(int color_in, int size_in, Point* shape_in)
		:color(color_in), size(size_in)
	{
		shape = new Point* [ROTATE_DIR::MAX_ROTATE];

		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++)
		{
			shape[i] = new Point[size];
			for (int j = 0; j < size; j++)
			{
				shape[i][j] = shape_in[(4 * i) + j];
			}
		}
	}

	~Mino()
	{
		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++)
			if (shape[i] != nullptr) delete[] shape[i];
	}

	//void Draw(Point loc, int rotate) { for (int i = 0; i < size; i++) PutDot(loc + shape[rotate][i], color); }
};