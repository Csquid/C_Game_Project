#include "head.h"

void InitDpMapArray(int** dpMap, Pos mapMaxPos, FILE* fp)
{
	for (int i = 0; i < mapMaxPos.y; i++)
	{
		dpMap[i] = (int*)malloc(sizeof(int) * mapMaxPos.x);
	}

	for (int i = 0; i < mapMaxPos.y; i++)
	{
		for (int j = 0; j < mapMaxPos.x; j++)
		{
			fscanf_s(fp, "%d", &dpMap[i][j]);
		}
	}
}

void InitConfig(Pos* consoleSizePos, Pos* planePos)
{
	consoleSizePos->setPos(CONSOLE_X, CONSOLE_Y);
	SetConsoleSize(*consoleSizePos);

	planePos->setPos(PLANE_X, PLANE_Y);
	SetCursor(FALSE);
}

void Move_AirPlane(Pos* airPlanePos, int mapMax_Width)
{
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && airPlanePos->x > 1)
	{
		airPlanePos->x -= 1;
	}
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && airPlanePos->x <= mapMax_Width - 3)
	{
		airPlanePos->x += 1;
	}

	GotoXY(*airPlanePos);
	printf("¡ã");
}

void Bullet(Pos PlanePos, Node** tail, Node* cur)
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		Pos* bullets = (Pos*)malloc(sizeof(Pos));
		bullets->setPos(PlanePos.x, PlanePos.y);
		GotoXY(*bullets);
		printf("¦¢");
		Linked_Insert(tail, *bullets);
	}
	//if(D)
}