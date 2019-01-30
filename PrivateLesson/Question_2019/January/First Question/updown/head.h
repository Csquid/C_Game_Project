#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRand()
{
    int randNumber = 0;

    srand(time(NULL));
    randNumber = (rand() % 100) + 1;

    return randNumber;
}