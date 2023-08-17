#pragma once
#include "seungtetris.h"

class Mino
{
public:
	int color;
	int size;		//ºí·Ï Ä­ °³¼ö
	Point* shape[ROTATE_DIR::MAX_ROTATE];

	Mino()
	{
		color = 0;
		size = 0;
		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++)
			shape[i] = nullptr;
	}

	Mino(int color_in, int size_in, Point* shape_in[ROTATE_DIR::MAX_ROTATE])
		:color(color_in), size(size_in)
	{
		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++)
		{
			shape[i] = new Point[size];
			for (int j = 0; j < size; j++)
			{
				shape[i][j] = shape_in[i][j];
			}
		}
	}

	~Mino()
	{
		for (int i = 0; i < ROTATE_DIR::MAX_ROTATE; i++)
			if (shape[i] != nullptr) delete[] shape[i];
	}
};