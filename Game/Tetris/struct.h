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

typedef struct tetris
{
	Pos MapPos;
	
	void showMap(int** dPointer, Pos MaxMapPos);
	void ShowFigure(int** dPointer, Pos* figurePos, int figuresKind);
} Tetris;