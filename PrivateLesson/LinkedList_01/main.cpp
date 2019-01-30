#include "head.h"

int main()
{
	Link head;
	Link tail;
	int k = 0;
	int d = 0;
	init(&head, &tail);
	
	int chooseMenu = -1;

	while (chooseMenu != 0)
	{
		menu();
		
		printf("choose: ");
		scanf_s("%d", &chooseMenu);

		switch (chooseMenu)
		{
		case 0:
			exit(1);
			break;
		case 1:
			printf("input Data: ");
			scanf_s("%d", &k);

			addNode(k, &head, &tail);
			break;
		case 2:
			printf("Delete Integer Data: ");
			scanf_s("%d", &d);

			deleteNode(d, &head, &tail);
			break;
		case 3:
			printNode(&head);
			break;
		}
	}
}