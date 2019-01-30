#include "head.h"

int main()
{
  int userNumber = 0;
  int rand_N_Number = getRand();

  while (userNumber != rand_N_Number)
  {
    printf("input Number: ");
    scanf("%d", &userNumber);

    printf("Rand_N_Number: %d\n", rand_N_Number);

    if (userNumber == rand_N_Number)
    {
      printf("Win");
      break;
    }
    else if (userNumber < rand_N_Number)
    {
      printf("Up \n");
    }
    else
    {
      printf("Down \n");
    }
  }

  return 0;
}