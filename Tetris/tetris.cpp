#include "inc.h"
#include <conio.h>

GameConfig game_config;

Mino* mino_shapes = new Mino[1];

Mino mino_I(green, 4, new Point[4 * ROTATE_DIR::MAX_ROTATE]
	{
			Point(-1, 0),Point(0, 0),Point(1, 0),Point(2, 0),
			Point(1, -1),Point(1, 0),Point(1, 1),Point(1, 2),
			Point(-1, 1),Point(0, 1),Point(1, 1),Point(2, 1),
			Point(0, -1),Point(0, 0),Point(0, 1),Point(0, 2)
	});

Wall wall(game_config.x_wall_size, game_config.y_wall_size);

int main()
{
	mino_shapes[0] = mino_I;

	cout << game_config.x_wall_size << endl;
	cout << game_config.y_wall_size << endl;
	
	wall.Draw();

	cout << endl;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << mino_I.shape[i][j].x << " " << mino_I.shape[i][j].y << endl;

	Brick brick(TETROMINO::I);
	brick.Draw();
	_getch();
	brick.RotateNDraw(1);
	_getch();
	brick.MoveNDraw(MOVE_DIR::DOWN, 5);
	_getch();
	brick.MoveNDraw(MOVE_DIR::RIGHT, 3);
	_getch();

	return 0;
}