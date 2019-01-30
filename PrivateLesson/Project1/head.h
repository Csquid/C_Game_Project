#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAP_WIDTH 5
#define MAP_HEIGHT 5

void gotoxy(int x, int y);
void Move_Character(int* x, int* y);

typedef struct Map
{
	void Default()
	{
		for (int i = 0; i < MAP_HEIGHT; ++i) 
		{

			for (int j = 0; j < MAP_WIDTH; ++j)
			{
				gotoxy(j, i);

				if ((i >= 1 && i <= MAP_HEIGHT - 2) && (j >= 1 && j <= MAP_WIDTH - 2))
				{
					continue;
				}
				printf("бс");
			}
		}
	}

	void Square_Pattern()
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			for (int j = 0; j < MAP_WIDTH; ++j)
			{
				gotoxy(j, i);
				
				if ((i >= 1 && i <= MAP_HEIGHT - 2) && (j >= 1 && j <= MAP_WIDTH - 2))
				{
					if ((i % 2) == 0)
					{
						printf("бс");
					}
					else
					{
						if ((j % 2) != 1)
						{
							printf("бс");
						}
						continue;
					}
				}
				printf("бс");
			}
		}
	}
};

//Point Of Sale
struct POS
{
	int x;
	int y;

	POS(int _x, int _y)
		:x(_x), y(_y)
	{}
};

void tmp(POS pt)
{
	pt.x;
	pt.y;

}

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Move_Character(int* x, int* y)
{
	int move_distance = 1;

	if ((GetAsyncKeyState(VK_UP) & 0x8000) && (*y > 1))
	{
		*y -= move_distance;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && (*y < MAP_HEIGHT - 2))
	{
		*y += move_distance;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && (*x > 1))
	{
		*x -= move_distance;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && (*x < MAP_WIDTH - 2))
	{
		*x += move_distance;
	}
}