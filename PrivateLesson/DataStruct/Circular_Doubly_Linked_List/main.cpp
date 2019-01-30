#include "head.h"

int main()
{
	Node* scNode = nullptr;
	Node* tail = nullptr;
	Node* cur = nullptr;


	for (int i = 0; i < 10; i++)
	{
		Insert(&tail, i + 1);
	}

	scNode = Search(tail, cur, 5);

	if (scNode == NULL)
	{
		printf("Can't Found Node \n");
	}
	else
	{
		printf("Find! [ %d ] \n", scNode->data);
	}

	Delete(&tail, scNode);

	AllPrint(tail, cur);

	Free(&tail, cur);

	return 0;
}