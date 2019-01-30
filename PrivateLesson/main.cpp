#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

struct POS
{
  int x;
  int y;

  POS(int _x, int _y)
      : x(_x), y(_y)
  {
  }
};

void tmp(POS pt)
{
  pt.x;
  pt.y;
}
void gotoxy(int x, int y)
{
  COORD pos = {x * 2, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Map_OutPut(int **tPointer)
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
      printf("■");
    }
  }
}
int main()
{
  POS *pData = (POS *)malloc(sizeof(POS));

  pData->x;
  pData->y;

  (*pData).x;
  (*pData).y;

  tmp(*pData);

  int **dPointer = (int **)malloc(sizeof(int *) * MAP_WIDTH);

  for (int i = 0; i < MAP_HEIGHT; i++)
  {
    dPointer[i] = (int *)malloc(sizeof(int) * MAP_WIDTH);
  }
  int x = 1;
  int y = 1;

  while (1)
  {

    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
      y--;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
      y++;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
      x--;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
      x++;
    }
    gotoxy(x, y);
    printf("★");
    Map_OutPut(dPointer);
    system("cls");
  }
}