#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define MAP_WIDTH 12
#define MAP_HEIGHT 15

#define MAP_MENU_WIDTH 10
#define MAP_MENU_HIGHT 15

#define ARROW_X 1
#define ARROW_Y 2

#define Default_Window_Config 0

typedef struct pos
{
	int x;
	int y;

	pos(int _x, int _y)
		: x(_x), y(_y)
	{
	}
	void setPos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setX(int x)
	{
		this->x = x;
	}
} Pos;

void gotoxy(const Pos nPos);
int  Move_Arrow(Pos* arrowPos);
void Window_Size_Config(int choose);
void mapLoding(int*** dPointer, char* mapPath, Pos** mapPos);
int  Move_Character(const Pos nMaxPos, Pos* mChar, int move_distance, int** dPointer);

typedef struct map
{
	void Menu()
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				Pos mapPos(j, i);
				gotoxy(mapPos);

				if ((i >= 1 && i <= MAP_HEIGHT - 2) && (j >= 1 && j <= MAP_WIDTH - 2))
				{
					continue;
				}
				printf("бс");
			}
		}
	}
	void DrawMap(Pos nMaxPos, int** dPointer)
	{
		for (int i = 0; i < nMaxPos.y; i++)
		{
			for (int j = 0; j < nMaxPos.x; j++)
			{
				Pos mapPos(j, i);

				gotoxy(mapPos);

				if (dPointer[i][j] == 1)
				{
					printf("бс");
				}
				else if (dPointer[i][j] == 0)
				{
					printf("  ");
				}
				else if (dPointer[i][j] == 2)
				{
					printf("T ");
				}
				else if (dPointer[i][j] == 3)
				{
					printf("E ");
				}
				else if (dPointer[i][j] == 4)
				{
					printf("S ");
				}
				else if (dPointer[i][j] == 5)
				{
					printf("E ");
				}
				else if (dPointer[i][j] == 6)
				{
					printf("N ");
				}
				else if (dPointer[i][j] == 7)
				{
					printf("D ");
				}
			}
			printf("\n");
		}
	}

	void DrowScrollMap(Pos nMaxPos, int** dPointer)
	{
		
	}
	void Square_Pattern(Pos nMaxPos, int** dPointer)
	{
		/*for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			for (int j = 0; j < MAP_WIDTH; ++j)
			{
				Pos mapPos(j, i);
				gotoxy(mapPos);

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
		}*/
	}
} Map;

typedef struct menu
{
	void Menu_Title()
	{
		Pos mapPos(1, 1);
		gotoxy(mapPos);
		printf("    >>  MENU  <<\n");
	}

	void Menu_Content()
	{
		Pos mapPos(1, 3);
		gotoxy(mapPos);
		printf("   1. Default Map \n");
		mapPos.setPos(1, 5);
		gotoxy(mapPos);
		printf("   2. Pattern Map \n");
		mapPos.setPos(1, 7);
		gotoxy(mapPos);
		printf("   3. Scroll Map \n");

	}
} Menu;