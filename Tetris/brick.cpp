#include "inc.h"

Brick::Brick(int type_in) :minotype(type_in)
{
	loc.x = game_config.wall_corner.x + game_config.x_wall_size / 2;
	loc.y = game_config.wall_corner.y + 1;
	rotate = 0;

	if (CanMove(MOVE_DIR::DOWN, 1))	Draw();
	else Playing = 0;
}

Brick::Brick(int type_in, Point location_in, int rotate_in) :minotype(type_in)
{
	loc.x = location_in.x;
	loc.y = location_in.y;
	rotate = rotate_in;

	if (CanMove(MOVE_DIR::DOWN, 1))	Draw();
	else Playing = 0;
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
	for (int i = 0; i < offset; i++)
	{
		if (CanMove(dir, 1))
		{
			if (dir == MOVE_DIR::DOWN)
				loc.y += 1;
			else if (dir == MOVE_DIR::LEFT)
				loc.x -= 1;
			else if (dir == MOVE_DIR::RIGHT)
				loc.x += 1;
		}
		else return false;
	}
	return true;
}

void Brick::Rotate(int offset)
{
	rotate = (rotate + offset) % 4;
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
		if (WallOffsetFromCorner.x <= 0 || WallOffsetFromCorner.y <= 0) return false;
		if (wall.wall[WallOffsetFromCorner.x][WallOffsetFromCorner.y] != game_config.background_color) return false;
	}

	return true;
}

bool Brick::CanRotate(int offset)
{
	int saverotate = rotate;
	rotate = (rotate + offset) % ROTATE_DIR::MAX_ROTATE;
	bool ret = CanMove(MOVE_DIR::DOWN, 0);
	rotate = saverotate;
	return ret;
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
		if (CanRotate(rotate)) Rotate(rotate);
		else
		{
			for (int i = 0; i < wall.x_size; i++)
				for (int j = 0; j < wall.y_size; j++)
					if (wall.wall[i][j] == game_config.background_color)
						PutDot(i + game_config.wall_corner.x, j + game_config.wall_corner.y, lightred);
			Sleep(100);
			wall.Draw();
			Draw();
		}
		/*else	좌 우로 1칸씩 이동해서 돌리기
		{
			Move(MOVE_DIR::LEFT, 1);
			if (CanRotate(rotate)) Rotate(rotate);
			else
			{
				Move(MOVE_DIR::RIGHT, 2);
				if (CanRotate(rotate)) Rotate(rotate);
				else
				{
					Move(MOVE_DIR::LEFT, 1);
					return;
				}
			}
		}*/
	Draw();
}
