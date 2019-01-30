#include "head.h"

int main()
{
	Node* scNode;
	Node* tail;
	Node* cur;
	int readData;
	int checkProgram = -1;

	Init(&tail, &cur, &scNode);
	
	while (checkProgram != 0)
	{
		Menu();
		printf("Choose: ");
		scanf_s("%d", &checkProgram);
		printf("\n");

		switch (checkProgram)
		{
		case 0:
			break;
		case 1:
			printf("Input Data: ");
			scanf_s("%d", &readData);
			
			InsertFront(&tail, readData);
			InsertBack(&tail, readData);
			printf("\n");
			break;
		case 2:
			printf("Search Data: ");
			scanf_s("%d", &readData);
			printf("\n");

			scNode = SearchNode(tail, cur, readData);

			if (scNode == nullptr)
			{
				printf("Can't Find Data \n");
			}
			else
			{
				printf("Find! [%d] \n", scNode->data);
			}
			break;
		case 3:
			printf("Delete Data: ");
			scanf_s("%d", &readData);

			scNode = SearchNode(tail, cur, readData);
			printf("\n");

			if (scNode == nullptr)
			{
				printf("Can't Find Data \n");
			}
			else
			{
				printf("Find! [%d] \n", scNode->data);
				DeleteNode(&tail, scNode);
			}
			break;
		case 4:
			PrintAll(tail, cur);
			break;
		}
	}

	if(tail != nullptr)
		FreeNode(&tail, cur);
	return 0;
}