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
	Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1),
	Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1),
	Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1),
	Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1)
};

const Point Mino_S_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(0, -1), Point(1, -1), Point(-1, 0), Point(0, 0),
	Point(-1, -1), Point(-1, 0), Point(0, 0), Point(0, 1),
	Point(0, 0), Point(1, 0), Point(-1, 1), Point(0, 1),
	Point(0, -1), Point(0, 0), Point(1, 0), Point(1, 1)
};

const Point Mino_Z_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(-1, -1), Point(0, -1), Point(0, 0), Point(1, 0),
	Point(0, -1), Point(-1, 0), Point(0, 0), Point(-1, 1),
	Point(-1, 0), Point(0, 0), Point(0, 1), Point(1, 1),
	Point(1, -1), Point(0, 0), Point(1, 0), Point(0, 1)
};

const Point Mino_J_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(-1, 0), Point(-1, 1), Point(0, 1), Point(1, 1),
	Point(1, -1), Point(1, 0), Point(0, 1), Point(1, 1),
	Point(-1, -1), Point(0, -1), Point(1, -1), Point(1, 0),
	Point(-1, -1), Point(0, -1), Point(-1, 0), Point(-1, 1)
};

const Point Mino_L_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(1, 0), Point(-1, 1), Point(0, 1), Point(1, 1),
	Point(0, -1), Point(1, -1), Point(1, 0), Point(1, 1),
	Point(-1, -1), Point(0, -1), Point(1, -1), Point(-1, 0),
	Point(-1, -1), Point(-1, 0), Point(-1, 1), Point(0, 1)
};

const Point Mino_T_Shape[ROTATE_DIR::MAX_ROTATE][4]
{
	Point(-1, 0), Point(0, 0), Point(1, 0), Point(0, 1),
	Point(0, -1), Point(0, 0), Point(1, 0), Point(0, 1),
	Point(0, -1), Point(-1, 0), Point(0, 0), Point(1, 0),
	Point(0, -1), Point(-1, 0), Point(0, 0), Point(0, 1)
};

Mino* mino = new Mino[TETROMINO::MAX_TYPE] {
	Mino(lightblue, 4, Mino_I_Shape[ROTATE_DIR::DEG_0], Mino_I_Shape[ROTATE_DIR::DEG_90], Mino_I_Shape[ROTATE_DIR::DEG_180], Mino_I_Shape[ROTATE_DIR::DEG_270]),
	Mino(yellow, 4, Mino_O_Shape[ROTATE_DIR::DEG_0], Mino_O_Shape[ROTATE_DIR::DEG_90], Mino_O_Shape[ROTATE_DIR::DEG_180], Mino_O_Shape[ROTATE_DIR::DEG_270]),
	Mino(green, 4, Mino_S_Shape[ROTATE_DIR::DEG_0], Mino_S_Shape[ROTATE_DIR::DEG_90], Mino_S_Shape[ROTATE_DIR::DEG_180], Mino_S_Shape[ROTATE_DIR::DEG_270]),
	Mino(red, 4, Mino_Z_Shape[ROTATE_DIR::DEG_0], Mino_Z_Shape[ROTATE_DIR::DEG_90], Mino_Z_Shape[ROTATE_DIR::DEG_180], Mino_Z_Shape[ROTATE_DIR::DEG_270]),
	Mino(blue, 4, Mino_J_Shape[ROTATE_DIR::DEG_0], Mino_J_Shape[ROTATE_DIR::DEG_90], Mino_J_Shape[ROTATE_DIR::DEG_180], Mino_J_Shape[ROTATE_DIR::DEG_270]),
	Mino(brown, 4, Mino_L_Shape[ROTATE_DIR::DEG_0], Mino_L_Shape[ROTATE_DIR::DEG_90], Mino_L_Shape[ROTATE_DIR::DEG_180], Mino_L_Shape[ROTATE_DIR::DEG_270]),
	Mino(purple, 4, Mino_T_Shape[ROTATE_DIR::DEG_0], Mino_T_Shape[ROTATE_DIR::DEG_90], Mino_T_Shape[ROTATE_DIR::DEG_180], Mino_T_Shape[ROTATE_DIR::DEG_270])
};

Wall wall(game_config.x_wall_size, game_config.y_wall_size);

bool Playing = 0;
bool TouchGround = 0;
int linescore = 0;


int main()
{
	init();

	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> random(0, TETROMINO::MAX_TYPE - 1);

	Playing = 1;

	int* minolist = new int[game_config.preview_num];
	for (int i = 0; i < game_config.preview_num; i++)
		minolist[i] = random(mersenne);

	MenuInterface ui(minolist);
	ui.DrawMenuFrame();
	wall.Draw();

	Brick* brick = new Brick(ui.GetNextMino(random(mersenne)));
	int floorupcount = 0;

	auto start = chrono::steady_clock::now();

	while (Playing)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				brick->MoveNDraw(MOVE_DIR::LEFT, 1);
				break;

			case 's':
				brick->MoveNDraw(MOVE_DIR::DOWN, 1);
				start = chrono::steady_clock::now();
				break;

			case 'd':
				brick->MoveNDraw(MOVE_DIR::RIGHT, 1);
				break;

			case 'w':
				brick->RotateNDraw(1);
				break;

			case 32:		//spacebar
				brick->MoveNDraw(MOVE_DIR::DOWN, game_config.y_wall_size);
				break;

			case 'c':
				brick->RotateNDraw(2);
				break;

			case 'x':
			{
				Brick* temp = brick;
				int holdtype = ui.Hold(brick->GetMinoType());
				Point loc;
				if (holdtype != TETROMINO::MAX_TYPE) brick = new Brick(holdtype, temp->GetLocation(loc), temp->GetRotate());
				else brick = new Brick(ui.GetNextMino(random(mersenne)), temp->GetLocation(loc), temp->GetRotate());

				/*if (Playing = false)
				{
					ui.EraseHold();
					Brick* temp2 = brick;
					brick = temp;
					delete temp2;
					Playing = true;
				}
				else
				{
					delete temp;
				}*/
				delete temp;

				wall.Draw();
				brick->Draw();
				break;
			}

			case 224:		//arrow keys
				switch (_getch())
				{
				case 75:	//left
					brick->MoveNDraw(MOVE_DIR::LEFT, 1);
					break;

				case 80:	//down
					brick->MoveNDraw(MOVE_DIR::DOWN, 1);
					start = chrono::steady_clock::now();
					break;

				case 77:	//right
					brick->MoveNDraw(MOVE_DIR::RIGHT, 1);
					break;

				case 72:	//up
					brick->RotateNDraw(1);
					break;
				}
				break;
			}
		}
		if (TouchGround)
		{
			wall.BrickToWall(*brick);
			wall.ClearLine();
			Brick* temp = brick;
			brick = new Brick(ui.GetNextMino(random(mersenne)));
			delete temp;
			TouchGround = 0;
			start = chrono::steady_clock::now();
		}
		if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() > 500)
		{
			brick->MoveNDraw(MOVE_DIR::DOWN, 1);
			start = chrono::steady_clock::now();
			floorupcount++;
		}
		if (floorupcount > game_config.floor_up_cycle)
		{
			brick->MoveNDraw(MOVE_DIR::DOWN, game_config.floor_up_offset);
			wall.FloorUp(1);
			brick->Draw();
			floorupcount = 0;
		}
		if (linescore > game_config.clear_goal)
			Playing = 0;
	}

	return 0;
}