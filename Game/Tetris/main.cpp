#include "head.h"

int main()
{
	Tetris* firstTetris = (Tetris*)malloc(sizeof(Tetris));
	const int tetris_x = 15;
	const int tetris_y = 20;
	int** dPointer;
	char firstFigure[] = "¡á¡á\n¡á¡á";
	char** figures = (char**)malloc(sizeof(char) * 10);
	//figures[0] = firstFigure;

	firstTetris->MapPos.setPos(tetris_x, tetris_y);
	ConfigMap(&dPointer);

	firstTetris->showMap(dPointer, firstTetris->MapPos);

	int figure_x = 4;
	int figure_y = 1;
	Pos* figurePos = (Pos*) malloc (sizeof(Pos));
	figurePos->setPos(figure_x, figure_y);
	while (1)
	{
		firstTetris->showMap(dPointer, firstTetris->MapPos);
		firstTetris->ShowFigure(dPointer, figurePos, 0);
		Sleep(60);
		Clear();

		if ((dPointer[figurePos->y + 1][figurePos->x]) != 1)
		{
			figurePos->y += 1;
		}
		if (GetAsyncKeyState(VK_LEFT) && (dPointer[figurePos->y][figurePos->x - 1] != 1))
		{
			figurePos->x -= 1;
		}
		if (GetAsyncKeyState(VK_RIGHT) && (dPointer[figurePos->y][figurePos->x + 1] != 1))
		{
			figurePos->x += 1;
		}
	}
}