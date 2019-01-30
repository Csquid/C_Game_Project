#include "head.h"

int main()
{
	Node* seNode = nullptr;
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* cur = nullptr;

	Insert(&head, &tail, 1);
	Insert(&head, &tail, 2);
	Insert(&head, &tail, 3);
	Insert(&head, &tail, 4);

	seNode = Search(head, cur, 2);

	if (seNode == NULL)
	{
		printf("Can't Find Node \n");
	}
	else
	{
		printf("Find! [%d] Node \n", seNode->data);
	}

	Delete(&head, &tail, seNode);

	AllPrint(head, cur);

	Free(&head, &tail, cur);

	return 0;
}