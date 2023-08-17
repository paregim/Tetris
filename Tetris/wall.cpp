#include "wall.h"

Wall::Wall()
{
	x_size = y_size = 0;
	wall = nullptr;
}

Wall::Wall(int x_in, int y_in)
{
	x_size = x_in + 2;
	y_size = y_in + 2;

	wall = new char* [x_in];
	for (int i = 0; i < x_in; i++)
		wall[i] = new char[y_in] {};

	for (int i = 0; i < y_in; i++)
	{
		wall[0][i] = game_cfg.wall_color;
		wall[x_in - 1][i] = game_cfg.wall_color;
	}
	for (int i = 0; i < x_in; i++)
	{
		wall[i][0] = game_cfg.wall_color;
		wall[i][y_in - 1] = game_cfg.wall_color;
	}
}

Wall::~Wall()
{
	if (wall == nullptr) return;

	for (int i = 0; i < x_size; i++) delete[] wall[i];
	delete[] wall;
}


void Wall::Draw()
{
	int color;

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; i++)
		{
			color = (wall[i][j] == 0) ? game_cfg.background_color : wall[i][j];

			PutDot(i + game_cfg.wall_start_x, j + game_cfg.wall_start_y, color);
		}
	}
}

void Wall::BrickToWall(class Brick& brick)
{
	
}

void Wall::FloorUp(int offset)
{

}

void Wall::ClearLine(int level)
{

}