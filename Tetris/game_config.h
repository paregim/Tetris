#pragma once
#include "seungtetris.h"

class GameConfig
{
public:
	int x_wall_size;
	int y_wall_size;
	Point wall_corner;

	int wall_color;
	int text_color;
	int floor_color;
	int background_color;

	char left_key;
	char right_key;
	char s_drop_key;
	char h_drop_key;
	char rotate90_key;
	char ratate180_key;
	char hold_key;
	char pause_key;

	int preview_num;
	int hold_num;
	int floor_up_cycle;
	int floor_up_offset;
	int clear_goal;

	GameConfig()
	{
		x_wall_size = 10;
		y_wall_size = 20;
		wall_corner.x = 15;
		wall_corner.y = 5;

		wall_color = blue;
		text_color = black;
		floor_color = lightgray;
		background_color = white;

#if 0
		left_key;
		right_key;
		s_drop_key;
		h_drop_key;
		rotate90_key;
		ratate180_key;
		hold_key;
		pause_key;

		preview_num;
		hold_num;
		floor_up_cycle;
		floor_up_offset;
		clear_goal;
#endif
	}
};