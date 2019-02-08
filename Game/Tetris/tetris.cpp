#include "head.h"

/*
**** dou ==> double
**** tri ==> triple
**** defPointer ==> default Pointer
**** curPointer ==> current Pointer
*/

void tetris::Init_Default_Map(int*** triDefPointer, Pos* mapMaxPos)
{
	FILE* fp;
	mapMaxPos->x = 0;
	mapMaxPos->y = 0;

	fopen_s(&fp, "./maps/map.txt", "rt");
	fscanf_s(fp, "%d %d", &mapMaxPos->x, &mapMaxPos->y);

	*triDefPointer = (int**)malloc(sizeof(int*) * mapMaxPos->y);
	for (int i = 0; i < mapMaxPos->y; i++)
	{
		(*triDefPointer)[i] = (int*)malloc(sizeof(int) * mapMaxPos->x);
	}

	for (int i = 0; i < mapMaxPos->y; i++)
	{
		for (int j = 0; j < mapMaxPos->x; j++)
		{
			fscanf_s(fp, "%d", &(*triDefPointer)[i][j]);
		}
	}

	for (int i = 0; i < mapMaxPos->y; i++)
	{
		for (int j = 0; j < mapMaxPos->x; j++)
		{
			printf("%d ", (*triDefPointer)[i][j]);
		}
		printf("\n");
	}
}

void tetris::Init_Current_Map(int*** triCurPointer, int** douDefPointer, Pos mapMaxPos)
{
	*triCurPointer = (int**)malloc(sizeof(int*) * mapMaxPos.y);

	for (int i = 0; i < mapMaxPos.y; i++)
	{
		(*triCurPointer)[i] = (int*)malloc(sizeof(int) * mapMaxPos.x);
	}

	for (int i = 0; i < mapMaxPos.y; i++)
	{
		for (int j = 0; j < mapMaxPos.x; j++)
		{
			(*triCurPointer)[i][j] = douDefPointer[i][j];
		}
	}

}

void tetris::SetCurrentMap(int** dPointer, int*** curPointer, Pos CurPos)
{
	// r(int i = 0; i < )
}

void tetris::showMap(int** douDefPointer, Pos maxMapPos)
{
	for (int i = 0; i < maxMapPos.y; i++)
	{
		for (int j = 0; j < maxMapPos.x; j++)
		{
			Pos map;
			map.setPos(j, i);

			GotoXY(map);
			switch ((douDefPointer)[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("бс");
				break;
			}
		}
	}
}

void tetris::ShowCurrentMap(int** douCurPointer, Pos maxMapPos)
{
	for (int i = 0; i < maxMapPos.y; i++)
	{
		for (int j = 0; j < maxMapPos.x; j++)
		{
			Pos map;
			map.setPos(j, i);

			GotoXY(map);
			switch ((douCurPointer)[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("бс");
				break;
			}
		}
	}
}

void tetris::ShowFigure(int** douDefPointer, Pos* figurePos, int figuresKind, struct tetris* firstTetris)
{

	int checkFue = 0;
	switch (figuresKind)
	{
	case 0:
		if (checkFue > 5 || figurePos->y <= 5)
		{
			checkFue = 0;
			for (int i = 0; i < figurePos->y; i++)
			{
				++checkFue;
				Pos figuPos;
				figuPos.setPos(figurePos->x, (figurePos->y + 1) - checkFue);
				GotoXY(figuPos);
				printf("бс");
			}
		}
		else
		{
			checkFue = 0;
			int max_y = 5;

			for (int i = 0; i < max_y; i++)
			{
				++checkFue;
				Pos figuPos;
				figuPos.setPos(figurePos->x, (figurePos->y + 1) - checkFue);
				GotoXY(figuPos);
				printf("бс");
			}
		}

		break;
	case 1:
		if (checkFue > 2 || figurePos->y <= 2)
		{
			checkFue = 0;
			for (int i = 0; i < figurePos->y - 1; i++)
			{
				++checkFue;
				Pos figuPos;
				figuPos.setPos(figurePos->x, (figurePos->y) - checkFue);
				GotoXY(figuPos);
				printf("бс");
			}
		}
		else
		{
			checkFue = 0;
			int plus = 0;
			int max_y = 2;
			for (int i = 0; i < max_y; i++)
			{
				++checkFue;
				Pos figuPos;
				figuPos.setPos(figurePos->x, (figurePos->y + 1) - checkFue);
				GotoXY(figuPos);
				printf("бс");
			}
			checkFue = 0;
			for (int i = 0; i < max_y; i++)
			{
				++checkFue;
				Pos figuPos;
				figuPos.setPos(figurePos->x + 1, (figurePos->y + 1) - checkFue);
				GotoXY(figuPos);
				printf("бс");
			}
			//for (int i = 0; i < max_y; i++)
			//{
			//	++checkFue;
			//	for (int j = 0; j < 2; j--)
			//	{
			//		Pos figuPos;
			//		//firstTetris->SetCurrentMap()
			//		figuPos.setPos(figurePos->x + 1, (figurePos->y + 1) - checkFue);
			//		GotoXY(figuPos);
			//		printf("бс");
			//	}
			//	++plus;
			//}
		}
		break;
	}
	Pos setGto;
	setGto.setPos(0, 22);
	GotoXY(setGto);
	printf("Current Pos: [%d, %d]\n", figurePos->x, figurePos->y);
}

void tetris::moveFigure(int** douDefPointer, Pos* figurePos, int figuresKind)
{
	switch (figuresKind)
	{
	case 1:
		if (GetAsyncKeyState(VK_RIGHT) && (douDefPointer[figurePos->y][figurePos->x + 2] != 1))
		{
			figurePos->x += 1;
		}
		break;
	}

	if ((douDefPointer[figurePos->y + 1][figurePos->x]) != 1)
	{
		figurePos->y += 1;
	}
	if (GetAsyncKeyState(VK_LEFT) && (douDefPointer[figurePos->y][figurePos->x - 1] != 1))
	{
		figurePos->x -= 1;
	}
	/*if (GetAsyncKeyState(VK_RIGHT) && (dPointer[figurePos->y][figurePos->x + 1] != 1))
	{
		figurePos->x += 1;
	}*/
}