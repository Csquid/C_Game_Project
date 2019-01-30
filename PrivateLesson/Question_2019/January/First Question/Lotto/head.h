#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void getRottoNumbers();

void getRottoNumbers()
{
  static char strNumber[4];
  static int inArray[6];

  int checkConfig = FALSE;
  //check Current Index
  int ccIndex = 0;
  int randNumber = 0;

  srand(time(NULL));

  for (int i = 0; i < 5; i++)
  {
    while (checkConfig == FALSE)
    {
      randNumber = (rand() % 44) + 1;
      printf("rand: %d \n", randNumber);
      if (ccIndex == 0)
      {
        inArray[0] = randNumber;
        ccIndex++;
      }
      else
      {
        for (int i = 0; i < 6; i++)
        {
          // if (i == ccIndex - 1)
          // {
          //   continue;
          // }
          if (randNumber == inArray[i])
          {
            printf("randNumber == inArray[i]");
            checkConfig = FALSE;
            break;
          }
          if ((i + 1) == ccIndex)
          {
            inArray[ccIndex] = randNumber;
            checkConfig = TRUE;
            ccIndex++;
          }
        }
        if (checkConfig == TRUE)
        {
          inArray[ccIndex] = randNumber;
          ccIndex++;
        }
      }
    }
  }

  for (int i = 0; i < 6; i++)
  {
    printf("inArray[%d]: %d \n", i, inArray[i]);
  }
}