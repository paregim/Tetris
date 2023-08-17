#pragma once
#include "seungtetris.h"

class GameCtrl
{
public:
	int current_stage;
	int current_speed;
	int* next_minotype;
	int hold_minotype;
};