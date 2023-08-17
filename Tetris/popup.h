#pragma once
#include "seungtetris.h"

class Popup
{
public:
	virtual void Draw() = 0;
	virtual int Select() = 0;
};

class PausePopup : public Popup
{
	void Draw();
	int Select();
};

class StartPopup : public Popup
{
	void Draw();
	int Select();
};