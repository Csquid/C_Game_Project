#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

char *getUserNumber();
char *getRand();
int compareNumber(char userNumData[], char randData[]);

char *getUserNumber()
{
  static char strUserNumber[4];
  int userNumber;

  printf("Input three Digits Number(Not Digits Zero, Not Compare): ");
  scanf("%d", &userNumber);

  itoa(userNumber, strUserNumber, 10);

  return strUserNumber;
}

char *getRand()
{
  static char strNumber[4];
  int checkConfig = FALSE;
  int randNumber = 0;

  srand(time(NULL));
  while (checkConfig == FALSE)
  {
    randNumber = (rand() % 1000) + 100;

    itoa(randNumber, strNumber, 10);

    /*
      *** randNumber 1000 over --> continue ***
    */
    if (randNumber > 1000)
    {
      continue;
    }

    int checkDigitsZero = FALSE;

    /*
      *** randNumber digits ZERO --> continue ***
    */

    for (int i = 1; i <= 2; i++)
    {
      if (strNumber[i] == '0')
      {
        checkDigitsZero = TRUE;
      }
    }

    /*
      ***if randNumber digits wasn't have Zero --> out While and return randNumber***
      ***만약 랜덤숫자 자릿수중 0을 가지고 있지 않았다면 while을 빠져 나가며 랜덤숫자를 return***
    */

    if (checkDigitsZero == TRUE)
    {
      continue;
    }

    checkConfig = TRUE;
  }

  return strNumber;
}

int compareNumber(char userNumData[], char randData[])
{
  printf("call compareNumber Function \n");
  printf("userData: %s \n", userNumData);
  printf("randData: %s \n", randData);

  int checkCompare = FALSE;

  if (!strcmp(userNumData, randData))
  {
    printf("HOME RUN \n");
    return TRUE;
  }

  /*
    *** Using double for statement --> check Strike and Ball
  */
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (randData[i] == userNumData[j])
      {
        if (i == j)
        {
          printf("Strike \n");
        }
        else
        {
          printf("Ball \n");
        }
        checkCompare = TRUE;
      }
      if (checkCompare == TRUE)
      {
        break;
      }
    }
    if (checkCompare == TRUE)
    {
      break;
    }
  }
  if (checkCompare == FALSE)
  {
    printf("Out \n");
  }
}