#include "inc.h"
#include <conio.h>

GameConfig game_config;
Point* shape_I = new Point[4] = {
		{ {-1, 0},{0, 0},{1, 0},{2, 0} },
		{ {1,-1},{1, 0},{1, 1},{1, 2} },
		{ {-1, 1},{0, 1},{1, 1},{2, 1} },
		{ {0, -1},{0, 0},{0, 1},{0, 2} }
};

Mino mino_I(5, 4, shape_I);

int main()
{
	cout << game_config.x_wall_size << endl;
	cout << game_config.y_wall_size << endl;
	Wall wall(game_config.x_wall_size, game_config.y_wall_size);
	_getch();
	wall.Draw();
	_getch();

	return 0;
}