#include "menu_interface.h"
#include "inc.h"

MenuInterface::MenuInterface(int* minolist)
{
	nextmino = minolist;
	holdmino = TETROMINO::MAX_TYPE;
	DrawMenuFrame();
	DrawHoldFrame();
	DrawNext();
}

int MenuInterface::GetNextMino(int newmino)
{
	int temp = nextmino[0];
	for (int i = 0; i < game_config.preview_num - 1; i++) nextmino[i] = nextmino[i + 1];
	nextmino[game_config.preview_num - 1] = newmino;
	DrawNext();
	return temp;
}

void MenuInterface::DrawMenuFrame()
{
	GotoCursor(game_config.wall_corner.x - 5, game_config.wall_corner.y);
	Setcolor(red, black);
	cout << "NEXT";
}

void MenuInterface::DrawHoldFrame()
{
	GotoCursor(game_config.wall_corner.x + game_config.x_wall_size + 5, game_config.wall_corner.y);
	Setcolor(blue, black);
	cout << "HOLD";
}

void MenuInterface::DrawSpeed()
{

}

void MenuInterface::EraseHold()
{
	for (int i = 0; i < mino[holdmino].size; i++) PutDot(game_config.wall_corner.x + game_config.x_wall_size + mino[holdmino].shape[ROTATE_DIR::DEG_0][i].x + 6, game_config.wall_corner.y + mino[holdmino].shape[ROTATE_DIR::DEG_0][i].y + 2, black);
}

void MenuInterface::DrawHold()
{
	for (int i = 0; i < mino[holdmino].size; i++) PutDot(game_config.wall_corner.x + game_config.x_wall_size + mino[holdmino].shape[ROTATE_DIR::DEG_0][i].x + 6, game_config.wall_corner.y + mino[holdmino].shape[ROTATE_DIR::DEG_0][i].y + 2, mino[holdmino].color);
}

int MenuInterface::Hold(int mino)
{
	int temp = holdmino;
	if (holdmino != TETROMINO::MAX_TYPE) EraseHold();
	holdmino = mino;
	DrawHold();
	return temp;
}

int MenuInterface::Hold(Brick brick)
{
	int temp = holdmino;
	if (holdmino != TETROMINO::MAX_TYPE) EraseHold();
	holdmino = mino;
	DrawHold();
	return temp;
}

//void MenuInterface::EraseNext(/*int* mino*/)
//{
//	
//}

void MenuInterface::DrawNext(/*int* mino*/)
{
	int GaptoNextMino = 4;

	for (int i = 0; i < game_config.wall_corner.x; i++)
	{
		for (int j = game_config.wall_corner.y + 1; j < game_config.y_wall_size + (game_config.wall_corner.y * 2) + 1; j++)
			PutDot(i, j, black);
	}

	for (int i = 0; i < game_config.preview_num; i++) 
		for (int j = 0; j < mino[nextmino[i]].size; j++) 
			PutDot(game_config.wall_corner.x - 5 + mino[nextmino[i]].shape[ROTATE_DIR::DEG_0][j].x, game_config.wall_corner.y + mino[nextmino[i]].shape[ROTATE_DIR::DEG_0][j].y + i * GaptoNextMino + 3, mino[nextmino[i]].color);
}

void MenuInterface::DrawGoal(int goal)
{

}