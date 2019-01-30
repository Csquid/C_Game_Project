#include "head.h"

void Show_Monster()
{
	for (int i = 0; i < 5; i++)
	{
		Pos gotoPos;
		gotoPos.setPos(i, 1);
		GotoXY(gotoPos);

		printf("бс");
	}
}

void Show_Map(Pos nMaxPos, int** mapArray)
{
	for (int i = 0; i < nMaxPos.y; i++)
	{
		for (int j = 0; j < nMaxPos.x; j++)
		{
			Pos gotoPos;
			gotoPos.setPos(j, i);

			GotoXY(gotoPos);
			if (mapArray[i][j] == 1)
			{
				printf("бс");
			}
			else if (mapArray[i][j] == 0)
			{
				printf("  ");
			}
		}
	}
}