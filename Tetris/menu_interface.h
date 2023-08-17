#pragma once
#include "seungtetris.h"

class MenuInterface
{
public:
	void DrawMenuFrame();
	void DrawHoldFrame();
	void DrawSpeed();
	void DrawHold(int mino);
	void DrawNext(int* mino);
	void DrawGoal(int goal);
};