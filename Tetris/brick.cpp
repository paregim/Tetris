#include "inc.h"

Brick::Brick(int type_in) :minotype(type_in)
{
	loc.x = game_config.wall_corner.x + game_config.x_wall_size / 2;
	loc.y = game_config.wall_corner.y;
	rotate = 0;

	Draw();
}

const int Brick::BrickSize()
{
	return mino[minotype].size;
}

const Point* Brick::CurrentShape()
{
	return mino[minotype].shape[rotate];
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
	const Point* Shape = CurrentShape();
	for (int i = 0; i < mino[minotype].size; i++) PutDot(loc + Shape[i], mino[minotype].color);
}

void Brick::Erase()
{
	const Point* Shape = CurrentShape();
	for (int i = 0; i < mino[minotype].size; i++) PutDot(loc + Shape[i], game_config.background_color);
}

bool Brick::Move(MOVE_DIR dir, int offset)
{
	if (CanMove(dir, offset))
	{
		if (dir == MOVE_DIR::DOWN)
			loc.y += offset;
		else if (dir == MOVE_DIR::LEFT)
			loc.x -= offset;
		else if (dir == MOVE_DIR::RIGHT)
			loc.x += offset;
		return true;
	}
	return false;
}

void Brick::Rotate(int offset)
{
	rotate += offset;
}

bool Brick::CanMove(MOVE_DIR dir, int offset)
{
	Point temp_cood(loc);
	const Point* Shape = CurrentShape();

	if (dir == MOVE_DIR::DOWN) temp_cood.y = loc.y + offset;
	else if (dir == MOVE_DIR::LEFT) temp_cood.x = loc.x - offset;
	else if (dir == MOVE_DIR::RIGHT) temp_cood.x = loc.x + offset;

	for (int i = 0; i < BrickSize(); i++)
	{
		// BrickDot_cood = temp_cood + Shape[i];
		// WallOffsetFromCorner = BrickDot_cood - game_config.wall_corner;
		Point WallOffsetFromCorner = (temp_cood + Shape[i]) - game_config.wall_corner;
		if (wall.wall[WallOffsetFromCorner.x][WallOffsetFromCorner.y] != game_config.background_color) return false;
	}

	return true;
}

void Brick::MoveNDraw(MOVE_DIR dir, int offset)
{
	Erase();
	bool moved = Move(dir, offset);
	Draw();
	if (moved == false && dir == MOVE_DIR::DOWN) TouchGround = 1;
}

void Brick::RotateNDraw(int rotate)
{
	Erase();
	Rotate(rotate);
	Draw();
}
