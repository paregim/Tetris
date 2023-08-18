#include "inc.h"

extern Mino* mino_shapes;
extern Wall wall;

Brick::Brick(int type_in) :minotype(type_in)
{
	loc.x = game_config.wall_corner.x + game_config.x_wall_size / 2;
	loc.y = 0;
	rotate = 0;
}

int Brick::GetMinoType() const
{
	return minotype;
}

Point& Brick::GetLocation(Point& location) const
{
	location = loc;
	return location;
}

int Brick::GetRotate() const
{
	return rotate;
}

void Brick::Draw()
{
	for (int i = 0; i < mino_shapes[minotype].size; i++) PutDot(loc + mino_shapes[minotype].shape[rotate][i], mino_shapes[minotype].color);
}

void Brick::Erase()
{
	for (int i = 0; i < mino_shapes[minotype].size; i++) PutDot(loc + mino_shapes[minotype].shape[rotate][i], game_config.background_color);
}

void Brick::Move(MOVE_DIR dir, int offset)
{
	//if (CanMove(dir, offset))
	{
		if (dir == MOVE_DIR::DOWN)
			loc.y += offset;
		else if (dir == MOVE_DIR::LEFT)
			loc.x -= offset;
		else if (dir == MOVE_DIR::RIGHT)
			loc.x += offset;
	}
}

void Brick::Rotate(int offset)
{
	rotate += offset;
}

bool Brick::CanMove(MOVE_DIR dir, int offset)
{
	Point temp(loc);

	if (dir == MOVE_DIR::DOWN)
		temp.y = loc.y + offset;
	else if (dir == MOVE_DIR::LEFT)
		temp.x = loc.x - offset;
	else if (dir == MOVE_DIR::RIGHT)
		temp.x = loc.x + offset;

	for (int i = 0; i < mino_shapes[minotype].size; i++)
		if (wall.wall[temp.x - game_config.wall_corner.x + mino_shapes[minotype].shape[rotate][i].x][temp.y - game_config.wall_corner.y + mino_shapes[minotype].shape[rotate][i].y] != 0)
			return false;
	return true;
}

void Brick::MoveNDraw(MOVE_DIR dir, int offset)
{
	Erase();
	Move(dir, offset);
	Draw();
}

void Brick::RotateNDraw(int rotate)
{
	Erase();
	Rotate(rotate);
	Draw();
}
