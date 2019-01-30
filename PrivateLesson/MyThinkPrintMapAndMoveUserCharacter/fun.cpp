#include "head.h"

void gotoxy(const Pos nPos)
{
	COORD pos = { nPos.x * 2, nPos.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void mapLoding(int*** dPointer, char* mapPath, Pos** mapPos)
{
	FILE *fp;
	int nMap;

	fopen_s(&fp, mapPath, "rt");
	fscanf_s(fp, "%d %d", &(*mapPos)->x, &(*mapPos)->y);

	*dPointer = (int **)malloc(sizeof(int) * (*mapPos)->y);

	for (int i = 0; i < (*mapPos)->y; i++)
	{
		(*dPointer)[i] = (int *)malloc(sizeof(int) * (*mapPos)->x);
	}

	for (int i = 0; i < (*mapPos)->y; i++)
	{
		for (int j = 0; j < (*mapPos)->x; j++)
		{
			fscanf_s(fp, "%d", &nMap, sizeof(nMap));
			(*dPointer)[i][j] = nMap;
		}
	}
	 
	fclose(fp);
}

int Move_Character(const Pos nMaxPos, Pos* mChar, int move_distance, int** dPointer)
{

	if ((GetAsyncKeyState(VK_UP) & 0x8000))
	{
		if((dPointer[mChar->y - 1][mChar->x]) != 1)
		{
			mChar->y -= 1;
		}
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x8000))
	{
		if ((dPointer[mChar->y + 1][mChar->x]) != 1)
		{
			mChar->y += 1;
		}
	}

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000))
	{
		if ((dPointer[mChar->y][mChar->x - 1]) != 1)
		{
			mChar->x -= 1;
		}
	}

	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000))
	{
		if ((dPointer[mChar->y][mChar->x + 1]) != 1)
		{
			mChar->x += 1;
		}
	}
	/*if ((GetAsyncKeyState(VK_UP) & 0x8000) && (mChar->y > 1))
	{
	mChar->y -= move_distance;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && (mChar->y < nMaxPos.y - 2))
	{
		mChar->y += move_distance;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && (mChar->x > 1))
	{
		mChar->x -= move_distance;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && (mChar->x < nMaxPos.x - 2))
	{
		mChar->x += move_distance;
	}*/
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		return -1;
	}
	gotoxy(*mChar);
	printf("¡Ú");

	Pos* printPos = (Pos*) malloc (sizeof(Pos));
	printPos->setPos(0, 11);
	gotoxy(*printPos);

	return 0;
}

int Move_Arrow(Pos* arrowPos)
{
	int move_distance = 1;

	if ((GetAsyncKeyState(VK_UP) & 0x8000) && (arrowPos->y > 2))
	{
		arrowPos->y -= move_distance;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && (arrowPos->y < MAP_HEIGHT - 2))
	{
		arrowPos->y += move_distance;
	}

	//Enter
	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (arrowPos->y)
		{
			//default
		case 3:
			return 1;
			break;
			//pattern
		case 5:
			return 2;
			break;
		case 7:
			return 3;
			break;
		}
	}

	gotoxy(*arrowPos);
	printf("¢º");

	return 0;
}

void Window_Size_Config(int choose)
{
	int cols;
	int lines;
	char colsChar[3];
	char linesChar[3];

	char window_size[30] = "mode con cols=";

	switch (choose)
	{
		//default
	case 0:
		cols = 40;
		lines = 25;
		break;
		//game_map
	case 1:
	case 2:
		cols = 45;
		lines = 25;
		break;
	case 3:
		cols = 60;
		lines = 25;
		break;
	default:
		break;
	}
	sprintf_s(colsChar, sizeof(colsChar), "%d", cols);
	sprintf_s(linesChar, sizeof(linesChar), "%d", lines);

	//strcat = combine str1 after str2
	strcat_s(window_size, sizeof(window_size), colsChar);
	strcat_s(window_size, sizeof(window_size), " lines=");
	strcat_s(window_size, sizeof(window_size), linesChar);

	system(window_size);
}