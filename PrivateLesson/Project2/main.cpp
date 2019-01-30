#include "head.h"

int main()
{
    clock_t CurTime, OldTime;
    POS *pData = (POS *)malloc(sizeof(POS));
    Map *pMap = (Map *)malloc(sizeof(Map));

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
        OldTime = clock();
        Move_Character(&x, &y);
        gotoxy(x, y);
        printf("★");
        pMap->Default();
        printf("\nCurrent X: %d Y: %d \n", x, y);
        printf("Clock: %d", OldTime);
        system("cls");
    }
}