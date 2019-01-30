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

typedef struct _bullets
{
	Pos curPos;
} Bullets;

//CirCle_Doubly_Linked_List
typedef struct _node
{
	struct _bullets bull;
	struct _node* next;
	struct _node* prev;
} Node;
