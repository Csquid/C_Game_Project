#include "head.h"

int main()
{
	Node* head;
	Node* tail;
	Node* cur;
	Node* searchNode;

	int readData;
	int searchData;
	int checkProgram = -1;

	Init(&head, &tail, &cur, &searchNode);

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
			printf("input data: ");
			scanf_s("%d", &readData);

			InsertNode(&head, &tail, readData);
			break;
		case 2:
			printf("Search Data:");
			scanf_s("%d", &searchData);
			
			searchNode = Search(head, cur, searchData);
			if (searchNode == nullptr)
				printf("Can't Find Data \n");
			else
				printf("Find Data: %d \n\n", searchNode->data);
			break;
		case 3:
			printf("Delete Data:");
			scanf_s("%d", &searchData);

			searchNode = Search(head, cur, searchData);
			if (searchNode == nullptr)
				printf("Can't Find Data \n");
			else
			{
				printf("Find Data: %d \n\n", searchNode->data);
				DeleteNode(&head, &tail, &searchNode, cur);
			}
			break;
		case 4:
			PrintNode(head, cur);
			break;
		}
	}
	FreeNode(&head, &tail);

	return 0;
}