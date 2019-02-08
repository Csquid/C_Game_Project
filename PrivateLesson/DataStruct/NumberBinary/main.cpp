#include "head.h"

void add(int a)
{
	if (a > 10)
		return;
	printf("%d\n", a + 1);
	add(a + 1);
}

int check = 4;

void Question(int a, int loopNumber)
{
	int n = 0;
	if (a > 4)
	{
		printf("");
		return;
	}
	
	int nArr[4][2];
	int nNum = 1;

	for (int i = 0; i < 4; i++)
	{
		--nNum;
		for (int j = 0; j < 2; j++)
		{
			nArr[i][j] = 0;
		}
		++nNum;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++) 
		{
			printf("nArr[%d][%d]: %d ", i, j,  nArr[i][j]);
		}
	}
	printf("\n");

	//Question(a + 1, loopNumber * 2);

	//char nStr[10];
	//int nArr[4];

	//int binaryCheck;

	//sprintf_s(nStr, sizeof(nStr), "%d", a);

	//printf("nStr: %s \n", nStr);

	//for (int i = 0; i < 4; i++)
	//{
	//	int a = (int)nStr[i] - 48;
	//	
	//	nArr[i] = a;
	//}

	//for (int i = 0; i < 4; i++)
	//{
	//	printf("nArr[i]: %d \n", nArr[i]);
	//}

}

void Test(int loop, int count, int checkNum)
{
	if (count >= 2)
		return;

	/*for (int i = 0; i < loop; i++)
	{
		int nNum = 0;
		printf("%d\n", nNum);
		if (nNum != 1)
			nNum++;
		printf("%d\n", nNum);
	}*/

	int nNum = 0;

	for (int i = 0; i < loop; i++)
	{

		for (int j = 0; j < checkNum; j++)
		{
			printf("%d \n", nNum);
		}
		nNum++;
		for (int j = 0; j < checkNum; j++)
		{
			printf("%d \n", nNum);
		}
		nNum--;

	}
	count++;
	Test(loop, count, checkNum * 2);
}

int main()
{
	int dBNumber = 1;
	Test(1, 0, dBNumber);
	
	return 0;
}