#include "head.h"

void Clear(void)
{
	system("cls");
}

void GotoXY(Pos nPos)
{
	COORD pos = { nPos.x * 2, nPos.y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void SetConsoleSize(Pos ConsolePos)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", ConsolePos.x, ConsolePos.y);
	system(setText);
}

void ConfigMap(int*** dPointer)
{
	FILE* fp;
	int mapMax_x = 0;
	int mapMax_y = 0;

	fopen_s(&fp, "./maps/map.txt", "rt");
	fscanf_s(fp, "%d %d", &mapMax_x, &mapMax_y);
	
	*dPointer = (int**)malloc(sizeof(int*) * mapMax_y);
	for (int i = 0; i < mapMax_y; i++)
	{
		(*dPointer)[i] = (int*)malloc(sizeof(int) * mapMax_x);
	}

	for (int i = 0; i < mapMax_y; i++)
	{
		for (int j = 0; j < mapMax_x; j++)
		{
			fscanf_s(fp, "%d", &(*dPointer)[i][j]);
		}
	}

	for (int i = 0; i < mapMax_y; i++)
	{
		for (int j = 0; j < mapMax_x; j++)
		{
			printf("%d ", (*dPointer)[i][j]);
		}
		printf("\n");
	}

	printf("[%d, %d] \n", mapMax_x, mapMax_y);
}

void tetris::showMap(int** dPointer, Pos maxMapPos)
{
	for (int i = 0; i < maxMapPos.y; i++)
	{
		for (int j = 0; j < maxMapPos.x; j++)
		{
			Pos map;
			map.setPos(j, i);

			GotoXY(map);
			switch ((dPointer)[i][j])
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

void tetris::ShowFigure(int** dPointer, Pos* figurePos, int figuresKind)
{
	switch (figuresKind)
	{
	case 0:
		int checkFue = 0;
		if (checkFue > 5 || figurePos->y <= 5)
		{
			int checkFue = 0;
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
			int checkFue = 0;
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
	}
}
