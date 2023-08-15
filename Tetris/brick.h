#pragma once
#include "seungtetris.h"

class Brick
{
private:
	const int minotype;
	Point loc;
	int rotate;		//enum ROTATE_DIR

public:
	Brick(int type_in);

	int GetMinoType() const;
	Point& GetLocation(Point& loc) const;
	int GetRotate() const;

	void Draw();
	void Erase();
	void Move(MOVE_DIR dir, int offset);
	void Rotate(int rotate);	//enum ROTATE_DIR
	bool CanMove(MOVE_DIR dir, int offset);
	void MoveNDraw(MOVE_DIR dir, int offset);
	void RotateNDraw(int rotate);	//enum ROTATE_DIR
};