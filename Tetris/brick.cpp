#include "inc.h"

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

}

void Brick::Erase()
{

}

void Brick::Move(MOVE_DIR dir, int offset)
{
	if (CanMove(dir, offset))
	{
		if (dir == MOVE_DIR::DOWN)
			loc.y--;
		else if (dir == MOVE_DIR::LEFT)
			loc.x--;
		else if (dir == MOVE_DIR::RIGHT)
			loc.x++;

		Draw();
	}
}

void Brick::Rotate(int rotate)
{
	
}

bool Brick::CanMove(MOVE_DIR dir, int offset)
{
	return true;
}

void Brick::MoveNDraw(MOVE_DIR dir, int offset)
{

}

void Brick::RotateNDraw(int rotate)
{

}
