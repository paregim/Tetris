#pragma once
#include "seungtetris.h"

class MenuInterface
{
private:
	int* nextmino;
	int holdmino;
public:
	MenuInterface(int* minolist);
	int GetNextMino(int newmino);
	void DrawMenuFrame();
	void DrawHoldFrame();
	void DrawSpeed();
	void DrawHold();
	void EraseHold();
	int Hold(int mino);
	int Hold(Brick brick);
	//void EraseNext(/*int* mino*/);
	void DrawNext(/*int* mino*/);
	void DrawGoal(int goal);
};