#include "inc.h"
#include <conio.h>

GameConfig game_config;

const Point Mino_I_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(-1, 0), Point(0, 0), Point(1, 0), Point(2, 0),
	Point(1, -1), Point(1, 0), Point(1, 1), Point(1, 2),
	Point(-1, 1), Point(0, 1), Point(1, 1), Point(2, 1),
	Point(0, -1), Point(0, 0), Point(0, 1), Point(0, 2)
};

const Point Mino_O_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(-1, 0), Point(0, 0), Point(1, 0), Point(2, 0),
	Point(1, -1), Point(1, 0), Point(1, 1), Point(1, 2),
	Point(-1, 1), Point(0, 1), Point(1, 1), Point(2, 1),
	Point(0, -1), Point(0, 0), Point(0, 1), Point(0, 2)
};

Mino* mino = new Mino[TETROMINO::MAX_TYPE] {
	Mino(green, 4, Mino_I_Shape[ROTATE_DIR::DEG_0], Mino_I_Shape[ROTATE_DIR::DEG_90], Mino_I_Shape[ROTATE_DIR::DEG_180], Mino_I_Shape[ROTATE_DIR::DEG_270]),
	Mino(blue, 4, Mino_O_Shape[ROTATE_DIR::DEG_0], Mino_O_Shape[ROTATE_DIR::DEG_90], Mino_I_Shape[ROTATE_DIR::DEG_180], Mino_I_Shape[ROTATE_DIR::DEG_270])
};

Wall wall(game_config.x_wall_size, game_config.y_wall_size);

bool Playing = 0;
bool TouchGround = 0;

int main()
{
	wall.Draw();

	Brick* brick = new Brick(TETROMINO::I);

	Playing = 1;

	while (Playing)
	{
		switch (_getch())
		{
		case 'a':
			brick->MoveNDraw(MOVE_DIR::LEFT, 1);
			break;

		case 's':
			brick->MoveNDraw(MOVE_DIR::DOWN, 1);
			break;

		case 'd':
			brick->MoveNDraw(MOVE_DIR::RIGHT, 1);
			break;


		}
		if (TouchGround)
		{
			wall.BrickToWall(*brick);
			Brick* temp = brick;
			brick = new Brick(TETROMINO::I);
			delete temp;
			TouchGround = 0;
		}
	}

	return 0;
}