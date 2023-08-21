#pragma once
#include "seungtetris.h"

class MenuInterface
{
private:
	int* nextmino;
public:
	MenuInterface(int* minolist);
	int GetNextMino(int newmino);
	void DrawMenuFrame();
	void DrawHoldFrame();
	void DrawSpeed();
	void DrawHold(int mino);
	void EraseNext(/*int* mino*/);
	void DrawNext(/*int* mino*/);
	void DrawGoal(int goal);
};