#pragma once

#include "head.h"

typedef struct pos
{
	int x;
	int y;

	void setPos(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}
} Pos;