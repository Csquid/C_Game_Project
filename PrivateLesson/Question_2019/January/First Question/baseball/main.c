#include "head.h"

int main()
{
  //checkCurrentUserInformation
  int ccui = FALSE;
  char *rand_N_Number = getRand();

  int i = 0;
  for (i = 0; i < 5; i++)
  {
    char *userNumber = getUserNumber();
    ccui = compareNumber(userNumber, rand_N_Number);

    if (ccui == TRUE)
    {
      printf("You Win \n");
      break;
    }
  }
  if (i == 5)
  {
    printf("\nYou LOSE \n");
  }
}