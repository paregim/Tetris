#pragma once
#include "seungtetris.h"

class Wall
{
	friend class Brick;

private:
	int x_size, y_size;
	char** wall;

public:
	Wall();
	Wall(int x_in, int y_in);
	~Wall();

	void Draw();
	void BrickToWall(class Brick& brick);
	void FloorUp(int offset);
	void ClearLine(int level);
};