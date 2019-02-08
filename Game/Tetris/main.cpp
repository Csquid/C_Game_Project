#include "head.h"

int main()
{
	Tetris* firstTetris = (Tetris*)malloc(sizeof(Tetris));
	const int tetris_x = 0;
	const int tetris_y = 0;

	int** dPointer;
	int** curPointer;
	//figures[0] = firstFigure;

	firstTetris->MapPos.setPos(tetris_x, tetris_y);
	firstTetris->Init_Default_Map(&dPointer, &firstTetris->MapPos);
	firstTetris->Init_Current_Map(&curPointer, dPointer, firstTetris->MapPos);

	int figure_x = 4;
	int figure_y = 1;
	Pos* figurePos = (Pos*) malloc (sizeof(Pos));
	figurePos->setPos(figure_x, figure_y);

	while (1)
	{
		firstTetris->showMap(dPointer, firstTetris->MapPos);

		while (1)
		{
			SetColor(White, Black);
			firstTetris->ShowCurrentMap(curPointer, firstTetris->MapPos);
			SetColor(Red, Black);
			firstTetris->moveFigure(curPointer, figurePos, 1);
			firstTetris->ShowFigure(dPointer, figurePos, 1, firstTetris);
			Sleep(100);
		}
		//Sleep(100);
		//Clear();

	}
}