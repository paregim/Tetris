#include "inc.h"


Wall::Wall()
{
	x_size = y_size = 0;
	wall = nullptr;
}

Wall::Wall(int x_in, int y_in)
{
	x_size = x_in + 2;
	y_size = y_in + 2;

	wall = new char* [x_size];
	for (int i = 0; i < x_size; i++)
		wall[i] = new char[y_size] {};

	for (int i = 0; i < x_size; i++)
		for (int j = 0; j < y_size; j++)
			wall[i][j] = game_config.background_color;

	for (int i = 0; i < y_size; i++)
	{
		wall[0][i] = game_config.wall_color;
		wall[x_size - 1][i] = game_config.wall_color;
	}
	for (int i = 0; i < x_size; i++)
	{
		//wall[i][0] = game_config.wall_color;
		wall[i][y_size - 1] = game_config.wall_color;
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
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			PutDot(i + game_config.wall_corner.x, j + game_config.wall_corner.y, wall[i][j]);
		}
	}
}

void Wall::BrickToWall(class Brick& brick)
{
	for (int i = 0; i < brick.BrickSize(); i++)
	{
		Point BrickOffsetFromCorner = (brick.loc + brick.CurrentShape()[i]) - game_config.wall_corner;
		wall[BrickOffsetFromCorner.x][BrickOffsetFromCorner.y] = mino[brick.minotype].color;
	}
	ClearLine();
}

void Wall::FloorUp(int offset)
{
	for (int i = 1; i < x_size - 1; i++)
	{
		for (int j = 0; j < y_size - offset - 1; j++) wall[i][j] = wall[i][j + offset];
		for (int j = y_size - offset - 1; j < y_size - 1; j++) wall[i][j] = game_config.floor_color;
	}
}

void Wall::ClearLine()
{
	for (int i = 0; i < y_size - 1; i++)
	{
		bool LineIsFull = true;
		for (int j = 1; j < x_size - 1; j++)
			if (wall[j][i] != game_config.background_color)
				LineIsFull = false;
		if (LineIsFull == true)
			for (int j = i; j > 0; j--)
				for (int k = 1; k < x_size - 1; k++)
					wall[k][j] = wall[k][j - 1];
	}
}